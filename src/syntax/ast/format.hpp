
#ifndef AERO_AST_FORMAT_HPP
#define AERO_AST_FORMAT_HPP

#include <string>

#include "syntax/ast/element.hpp"
#include "syntax/syntax_kind.hpp"

namespace aero::syntax::ast {
std::string PrettyGreenNode(const GreenNode &, size_t);
std::string PrettyGreenToken(const GreenToken &);
}  // namespace aero::syntax::ast

#endif