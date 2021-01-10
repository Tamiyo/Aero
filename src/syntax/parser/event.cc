#include "syntax/parser/event.h"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::parser {
Event::Event(EventType t) : type(t) {}

std::string Event::Pretty() {
  if (std::holds_alternative<EventStartNode>(type)) {
    EventStartNode node = std::get<EventStartNode>(type);
    std::string fp = (node.forward_parent.has_value())
                         ? std::to_string(*node.forward_parent)
                         : "N/A";

    return fmt::format("StartNode {{{} : {}}}",
                       magic_enum::enum_name(node.kind), fp);
  } else if (std::holds_alternative<EventAddToken>(type)) {
    return "AddToken {}";
  } else if (std::holds_alternative<EventFinishNode>(type)) {
    return "FinishNode {}";
  } else if (std::holds_alternative<EventPlaceholder>(type)) {
    return "Placeholder {}";
  } else {
    EventError node = std::get<EventError>(type);
    return "Error {}";
  }
}
}  // namespace aero::syntax::parser