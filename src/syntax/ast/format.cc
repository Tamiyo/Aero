#include "syntax/ast/format.h"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::ast {
std::string PrettyGreenNode(const GreenNode &n, size_t i) {
  std::string magic_kind = std::string(magic_enum::enum_name(n.kind));
  std::string out = fmt::format("{: >{}}{}\n", "", i * 2, magic_kind);

  for (auto child : n.children) {
    GreenElement *ptr = child.get();
    if (auto child_node = std::get_if<GreenNode>(ptr)) {
      out.append(PrettyGreenNode(*child_node, i + 1));
    } else {
      out.append(fmt::format("{: >{}}{}\n", "", 2 * (i + 1),
                             PrettyGreenToken(std::get<1>(*ptr))));
    }
  }

  return out;
}

std::string PrettyGreenToken(const GreenToken &t) {
  std::string magic_kind = std::string(magic_enum::enum_name(t.kind));
  return fmt::format("{} \"{}\"", magic_kind, t.text);
}
}  // namespace aero::syntax::ast