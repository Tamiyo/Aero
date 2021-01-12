#include "syntax/parser/event.h"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::parser {
Event::Event(EventType t) : type(t) {}

std::ostream& operator<<(std::ostream& os, const Event& event) {
  if (std::holds_alternative<event::StartNode>(event.type)) {
    event::StartNode node = std::get<event::StartNode>(event.type);

    std::string fp = (node.forward_parent.has_value())
                         ? std::to_string(*node.forward_parent)
                         : "N/A";
    return os << fmt::format("StartNode({}, {})", node.kind, fp);
  } else if (std::holds_alternative<event::AddToken>(event.type)) {
    return os << "AddToken()";
  } else if (std::holds_alternative<event::FinishNode>(event.type)) {
    return os << "FinishNode()";
  } else if (std::holds_alternative<event::Placeholder>(event.type)) {
    return os << "Placeholder()";
  } else {
    event::Error node = std::get<event::Error>(event.type);
    return os << "Error()";
  }
}
}  // namespace aero::syntax::parser