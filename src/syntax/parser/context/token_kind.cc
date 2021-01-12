#include "token_kind.h"

#include <spdlog/spdlog.h>

#include "magic_enum.hpp"

namespace aero::syntax::parser::context {
TokenKind FromSyntaxKind(SyntaxKind kind) {
  if (kind < SyntaxKind::__LITERALS) {
    return {context::Syntax{kind}};
  } else if (kind < SyntaxKind::__TOKENS) {
    return context::Literal{};
  } else if (kind == SyntaxKind::Identifier) {
    return context::Identifier{};
  } else if (kind < SyntaxKind::__KEYWORDS) {
    return context::Operator{};
  } else if (kind < SyntaxKind::__TYPES) {
    return context::Keyword{};
  } else if (kind < SyntaxKind::__NODES) {
    return context::Type{};
  } else {
    // Should never happen
    spdlog::error("TokenKind cannot be from SyntaxKind::__NODES!");
    exit(1);
  }
}
}  // namespace aero::syntax::parser::context