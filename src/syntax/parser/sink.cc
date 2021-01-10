#include "syntax/parser/sink.h"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <variant>

namespace aero::syntax::parser {
Sink::Sink(std::vector<aero::syntax::lexer::Token> t, std::vector<Event> e)
    : tokens(t), events(e) {
  this->builder = ast::GreenNodeBuilder();
  this->cursor = 0;
}

ast::GreenNode Sink::Finish() {
  for (size_t idx = 0; idx < events.size(); idx += 1) {
    Event event = events.at(idx);
    events.at(idx) = {EventPlaceholder{}};

    if (std::holds_alternative<EventStartNode>(event.type)) {
      EventStartNode start = std::get<EventStartNode>(event.type);
      std::vector<SyntaxKind> kinds({start.kind});

      size_t idx_parent = idx;
      std::optional<size_t> forward_parent = start.forward_parent;

      for (;;) {
        if (auto fp = forward_parent) {
          idx_parent += *fp;

          Event event_parent = events.at(idx_parent);
          events.at(idx_parent) = Event{EventPlaceholder{}};

          if (std::holds_alternative<EventStartNode>(event_parent.type)) {
            EventStartNode start_inner =
                std::get<EventStartNode>(event_parent.type);
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
    } else if (std::holds_alternative<EventAddToken>(event.type)) {
      Token();
    } else if (std::holds_alternative<EventFinishNode>(event.type)) {
      builder.FinishNode();
    }

    EatTrivia();
  }

  return builder.Finish();
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