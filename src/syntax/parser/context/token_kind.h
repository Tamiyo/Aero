#ifndef AERO_PARSER_CONTEXT_TOKEN_KIND_H
#define AERO_PARSER_CONTEXT_TOKEN_KIND_H

#include <variant>

#include "syntax/syntax_kind.h"

namespace aero::syntax::parser::context {
struct Syntax {
  SyntaxKind kind;
};
struct Literal {};
struct Keyword {};
struct Operator {};
struct Identifier {};
struct Type {};

using TokenKind =
    std::variant<Syntax, Literal, Keyword, Operator, Identifier, Type>;

TokenKind FromSyntaxKind(SyntaxKind);
}  // namespace aero::syntax::parser::context

#endif