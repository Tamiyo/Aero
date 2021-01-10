
#ifndef AERO_PARSER_ERROR_H
#define AERO_PARSER_ERROR_H

#include <deque>

#include "syntax/parser/context/token_kind.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
struct ParseError {
  std::deque<context::TokenKind> expected;
  std::deque<SyntaxKind> found;
  size_t range;
};
}  // namespace aero::syntax::parser

#endif