
#ifndef AERO_AST_FORMAT_H
#define AERO_AST_FORMAT_H

#include <string>

#include "syntax/ast/element.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::ast {
std::string PrettyGreenNode(const GreenNode &, size_t);
std::string PrettyGreenToken(const GreenToken &);
}  // namespace aero::syntax::ast

#endif