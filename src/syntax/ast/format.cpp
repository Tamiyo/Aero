#include "syntax/ast/format.hpp"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::ast {
std::string PrettyGreenNode(const GreenNode &n, size_t i) {
  std::string magic_kind = std::string(magic_enum::enum_name(n.kind));
  std::string out = fmt::format("{: >{}}{}\n", "", i * 2, magic_kind);

  for (auto child : n.children) {
    GreenElement *ptr = child.get();
    if (ptr->index() == 0) {
      out.append(PrettyGreenNode(std::get<0>(*ptr), i + 1));
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