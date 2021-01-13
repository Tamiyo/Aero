#include "syntax/ast/element.h"

#include "fmt/core.h"
#include "magic_enum.hpp"

namespace aero::syntax::ast {

bool GreenToken::operator==(const GreenToken &other) const {
  return (this->kind == other.kind) && (this->text == other.text);
}

bool GreenNode::operator==(const GreenNode &other) const {
  return (this->kind == other.kind) && (this->text_len == other.text_len) &&
         (this->children == other.children);
}

std::ostream &operator<<(std::ostream &os, const GreenToken &token) {
  auto magic_kind = magic_enum::enum_name(token.kind);
  return os << fmt::format("GreenToken({}, \"{}\")", std::string(magic_kind),
                           token.text);
}

std::ostream &operator<<(std::ostream &os, const GreenNode &node) {
  auto magic_kind = magic_enum::enum_name(node.kind);

  std::string out = fmt::format("GreenNode({}, {})", std::string(magic_kind),
                                node.children.size());

  for (auto child : node.children) {
    GreenElement element = *child.get();
    out.append(fmt::format("\n{}", element));
  }

  return os << out;
}

std::ostream &operator<<(std::ostream &os, const GreenElement &element) {
  if (std::holds_alternative<GreenNode>(element)) {
    return os << fmt::format("{}", std::get<GreenNode>(element));
  } else {
    return os << fmt::format("{}", std::get<GreenToken>(element));
  }
}
}  // namespace aero::syntax::ast