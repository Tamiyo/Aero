
#ifndef AERO_AST_ELEMENT_HPP
#define AERO_AST_ELEMENT_HPP

#include <deque>
#include <memory>
#include <variant>

#include "syntax/syntax_kind.h"

namespace aero::syntax::ast {
struct GreenToken {
  SyntaxKind kind;
  std::string text;
};

struct GreenNode {
  SyntaxKind kind;
  size_t text_len;
  std::deque<std::shared_ptr<std::variant<GreenNode, GreenToken>>> children;
};

using GreenElement = std::variant<GreenNode, GreenToken>;

}  // namespace aero::syntax::ast

#endif