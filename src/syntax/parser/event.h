#ifndef AERO_PARSER_EVENT_H
#define AERO_PARSER_EVENT_H

#include <optional>

#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
enum class EventType {
  StartNode = 1,
  AddToken,
  FinishNode,
  Placeholder,
};

class EventValue {
 public:
  EventValue(SyntaxKind, std::optional<size_t>);
  EventValue() = delete;
  EventValue(const EventValue&) = default;
  ~EventValue() = default;

  std::string Pretty();

  SyntaxKind Kind();
  void SetKind(SyntaxKind);

  std::optional<size_t> ForwardParent();
  void SetForwardParent(std::optional<size_t>);

 private:
  SyntaxKind kind;
  std::optional<size_t> forward_parent;
};

class Event {
 public:
  Event(EventType, std::optional<EventValue>);
  Event() = default;

  std::string Pretty();

  EventType Type();
  void SetType(EventType);

  std::optional<EventValue> Value();
  void SetValue(std::optional<EventValue>);

  EventValue* ValueUnwrappedRef();

 private:
  EventType type;
  std::optional<EventValue> value;
};

}  // namespace aero::syntax::parser

#endif