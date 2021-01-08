#include "syntax/lexer/token.h"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::lexer {
Token::Token(SyntaxKind k, std::string t) : kind(k), text(t) {}

bool Token::operator==(const Token& other) const {
  return (this->kind == other.kind) && (this->text == other.text);
}

SyntaxKind Token::Kind() { return this->kind; }
std::string Token::Text() { return this->text; }

std::string Token::Pretty() {
  auto magic_kind = std::string(magic_enum::enum_name(this->kind));
  if (text == "\n")
    return fmt::format("[{}, \'\\n\']", magic_kind);
  else
    return fmt::format("[{}, \'{}\']", magic_kind, text);
}
}  // namespace aero::syntax::lexer