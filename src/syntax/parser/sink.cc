#include "syntax/parser/sink.h"

#include <algorithm>

namespace aero::syntax::parser {
Sink::Sink(std::vector<aero::syntax::lexer::Token> t, std::deque<Event> e)
    : tokens(t), events(e) {
  this->builder = ast::GreenNodeBuilder();
  this->cursor = 0;
}

ast::GreenNode Sink::Finish() {
  for (size_t idx = 0; idx < events.size(); idx += 1) {
    Event event = events[idx];
    events[idx] = Event{EventType::Placeholder, std::nullopt};

    if (auto ev = event.Value(); ev && event.Type() == EventType::StartNode) {
      std::vector<SyntaxKind> kinds({(*ev).Kind()});

      size_t idx_i = idx;
      std::optional<size_t> forward_parent = (*ev).ForwardParent();

      for (;;) {
        if (auto fp = forward_parent; fp) {
          idx_i += *fp;

          Event event_i = events[idx_i];
          events[idx_i] = Event{EventType::Placeholder, std::nullopt};

          if (auto ev_v = event_i.Value();
              ev && event_i.Type() == EventType::StartNode) {
            kinds.push_back((*ev_v).Kind());
            forward_parent = (*ev_v).ForwardParent();
          }
        } else {
          break;
        }
      }

      std::reverse(kinds.begin(), kinds.end());
      for (auto kind : kinds) {
        builder.StartNode(kind);
      }
    } else if (event.Type() == EventType::AddToken) {
      Token();
    } else if (event.Type() == EventType::FinishNode) {
      builder.FinishNode();
    }

    EatTrivia();
  }

  return builder.Finish();
}

void Sink::EatTrivia() {
  while (cursor < tokens.size()) {
    lexer::Token t = tokens.at(cursor);

    if (!is_trivia(t.Kind())) break;

    Token();
  }
}

void Sink::Token() {
  lexer::Token t = tokens.at(cursor);
  builder.Token(t.Kind(), t.Text());
  cursor += 1;
}
}  // namespace aero::syntax::parser