#ifndef AERO_PARSER_EVENT_H
#define AERO_PARSER_EVENT_H

#include <fmt/ostream.h>

#include <optional>
#include <variant>

#include "syntax/parser/error.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
namespace event {
struct StartNode {
  SyntaxKind kind;
  std::optional<size_t> forward_parent;
};
struct AddToken {};
struct FinishNode {};
struct Placeholder {};
struct Error {
  ParseError error;
};
}  // namespace event

using EventType =
    std::variant<event::StartNode, event::AddToken, event::FinishNode,
                 event::Placeholder, event::Error>;

class Event {
 public:
  Event(EventType);
  Event() = delete;
  Event(const Event&) = default;
  ~Event() = default;

  EventType type;
};

std::ostream& operator<<(std::ostream&, const Event&);
}  // namespace aero::syntax::parser

#endif