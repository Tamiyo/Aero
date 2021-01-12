
#ifndef AERO_PARSER_ERROR_H
#define AERO_PARSER_ERROR_H

#include <optional>
#include <utility>
#include <vector>

#include "syntax/parser/context/token_kind.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
struct ParseError {
  std::vector<context::TokenKind> expected;
  std::optional<SyntaxKind> found;
  std::pair<size_t, size_t> range;
};
};  // namespace aero::syntax::parser

#endif