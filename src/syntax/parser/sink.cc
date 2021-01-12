#include "syntax/parser/sink.h"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <variant>

namespace aero::syntax::parser {
Sink::Sink(std::vector<aero::syntax::lexer::Token> t, std::vector<Event> e)
    : tokens(t), events(e) {
  this->builder = ast::GreenNodeBuilder();
  this->errors = std::vector<ParseError>();
  this->cursor = 0;
}

Parse Sink::Finish() {
  for (size_t idx = 0; idx < events.size(); idx += 1) {
    Event event = events.at(idx);
    events.at(idx) = {event::Placeholder{}};

    if (std::holds_alternative<event::StartNode>(event.type)) {
      event::StartNode start = std::get<event::StartNode>(event.type);
      std::vector<SyntaxKind> kinds({start.kind});

      size_t idx_parent = idx;
      std::optional<size_t> forward_parent = start.forward_parent;

      for (;;) {
        if (auto fp = forward_parent) {
          idx_parent += *fp;

          Event event_parent = events.at(idx_parent);
          events.at(idx_parent) = Event{event::Placeholder{}};

          if (std::holds_alternative<event::StartNode>(event_parent.type)) {
            event::StartNode start_inner =
                std::get<event::StartNode>(event_parent.type);
            kinds.push_back(start_inner.kind);
            forward_parent = start_inner.forward_parent;
          }
        } else {
          break;
        }
      }

      std::reverse(kinds.begin(), kinds.end());
      for (auto kind : kinds) {
        builder.StartNode(kind);
      }
    } else if (std::holds_alternative<event::AddToken>(event.type)) {
      Token();
    } else if (std::holds_alternative<event::FinishNode>(event.type)) {
      builder.FinishNode();
    } else if (std::holds_alternative<event::Error>(event.type)) {
      errors.emplace_back(std::get<event::Error>(event.type).error);
    }

    EatTrivia();
  }

  return Parse{builder.Finish(), errors};
}

void Sink::EatTrivia() {
  while (cursor < tokens.size()) {
    lexer::Token t = tokens.at(cursor);

    if (!IsTrivia(t.Kind())) break;

    Token();
  }
}

void Sink::Token() {
  lexer::Token t = tokens.at(cursor);
  builder.Token(t.Kind(), t.Text());
  cursor += 1;
}
}  // namespace aero::syntax::parser