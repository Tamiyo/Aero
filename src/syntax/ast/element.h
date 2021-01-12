
#ifndef AERO_AST_ELEMENT_H
#define AERO_AST_ELEMENT_H

#include <deque>
#include <memory>
#include <variant>

#include "fmt/ostream.h"
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

std::ostream &operator<<(std::ostream &, const GreenToken &);
std::ostream &operator<<(std::ostream &, const GreenNode &);
std::ostream &operator<<(std::ostream &, const GreenElement &);
}  // namespace aero::syntax::ast

#endif