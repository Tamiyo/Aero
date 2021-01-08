#ifndef AERO_LEXER_TOKEN_H
#define AERO_LEXER_TOKEN_H

#include <string>

#include "syntax/syntax_kind.h"

namespace aero::syntax::lexer {
class Token {
 public:
  Token(SyntaxKind, std::string);

  bool operator==(const Token &) const;

  std::string Pretty();

  SyntaxKind Kind();
  std::string Text();

 private:
  SyntaxKind kind;
  std::string text;
};
}  // namespace aero::syntax::lexer

#endif