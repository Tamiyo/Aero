#include "syntax/parser/event.hpp"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::parser {
// Event Value
EventValue::EventValue(SyntaxKind k, std::optional<size_t> fp) {
  this->kind = k;
  this->forward_parent = fp;
}

SyntaxKind EventValue::Kind() { return this->kind; }
void EventValue::SetKind(SyntaxKind k) { this->kind = k; }

std::optional<size_t> EventValue::ForwardParent() {
  return this->forward_parent;
}

void EventValue::SetForwardParent(std::optional<size_t> fp) {
  this->forward_parent = fp;
}

std::string EventValue::Pretty() {
  auto magic_kind = std::string(magic_enum::enum_name(this->kind));
  if (auto fp = forward_parent; fp)
    return fmt::format("[{}, {}]", magic_kind, std::to_string(*fp));
  else
    return fmt::format("[{}, NULL]", magic_kind);
}

// Event
Event::Event(EventType t, std::optional<EventValue> v) {
  this->type = t;
  this->value = v;
}

EventType Event::Type() { return this->type; }
void Event::SetType(EventType t) { this->type = t; }

std::optional<EventValue> Event::Value() { return this->value; }
void Event::SetValue(std::optional<EventValue> v) { this->value = v; }

EventValue* Event::ValueUnwrappedRef() { return &*(this->value); }

std::string Event::Pretty() {
  auto magic_type = magic_enum::enum_name(this->type);

  if (auto v = value; v && type == EventType::StartNode)
    return fmt::format("[{}, {}]", magic_type, (*v).Pretty());
  else
    return fmt::format("[{}, NULL]", magic_type);
}
}  // namespace aero::syntax::parser