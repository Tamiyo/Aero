#ifndef AERO_LEXER_TOKEN_H
#define AERO_LEXER_TOKEN_H

#include <fmt/ostream.h>

#include <string>
#include <utility>

#include "syntax/syntax_kind.h"

namespace aero::syntax::lexer {
class Token {
 public:
  Token(SyntaxKind, std::string, std::pair<size_t, size_t>);
  Token() = delete;
  Token(const Token &) = default;
  ~Token() = default;

  bool operator==(const Token &) const;

  SyntaxKind Kind() const;
  std::string Text() const;
  std::pair<size_t, size_t> Range() const;

 private:
  SyntaxKind kind;
  std::string text;
  std::pair<size_t, size_t> range;
};

std::ostream &operator<<(std::ostream &, const Token &);
}  // namespace aero::syntax::lexer

#endif