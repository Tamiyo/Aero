#include "syntax/lexer/token.h"

#include <fmt/core.h>

#include <magic_enum.hpp>

namespace aero::syntax::lexer {
Token::Token(SyntaxKind k, std::string t, std::pair<size_t, size_t> r)
    : kind(k), text(t), range(r) {}

bool Token::operator==(const Token& other) const {
  return (this->kind == other.kind) && (this->text == other.text);
}

SyntaxKind Token::Kind() const { return this->kind; }
std::string Token::Text() const { return this->text; }
std::pair<size_t, size_t> Token::Range() const { return this->range; }

std::ostream& operator<<(std::ostream& os, const Token& token) {
  const SyntaxKind kind = token.Kind();
  const std::string text = token.Text();
  const auto magic_kind = magic_enum::enum_name(kind);

  if (text == "\n")
    return os << fmt::format("Token({}, \'\\n\')", std::string(magic_kind));
  else
    return os << fmt::format("Token({}, \'{}\')", std::string(magic_kind), text);
}
}  // namespace aero::syntax::lexer