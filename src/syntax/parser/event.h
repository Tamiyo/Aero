#ifndef AERO_PARSER_EVENT_H
#define AERO_PARSER_EVENT_H

#include <optional>
#include <variant>

#include "syntax/parser/error.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
struct EventStartNode {
  SyntaxKind kind;
  std::optional<size_t> forward_parent;
};
struct EventAddToken {};
struct EventFinishNode {};
struct EventPlaceholder {};
struct EventError {};

using EventType = std::variant<EventStartNode, EventAddToken, EventFinishNode,
                               EventPlaceholder, EventError>;

class Event {
 public:
  Event(EventType);
  Event() = delete;
  Event(const Event&) = default;
  ~Event() = default;

  std::string Pretty();

  EventType type;
};

}  // namespace aero::syntax::parser

#endif