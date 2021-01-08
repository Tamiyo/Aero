#ifndef AERO_LEXER_LEXER_H
#define AERO_LEXER_LEXER_H

#include <iterator>
#include <optional>
#include <string>
#include <vector>

#include "syntax/lexer/token.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::lexer {
class Lexer {
 public:
  Lexer(std::string);
  Lexer() = default;

  std::vector<Token> Tokenize();

 private:
  Token MakeToken(std::string::iterator *, SyntaxKind, std::string);

  char Bump(std::string::iterator *);
  std::optional<char> Nth(std::string::iterator *, int);

  Token ConsumeComment(std::string::iterator *);
  Token ConsumeToken(std::string::iterator *);
  Token ConsumeString(std::string::iterator *);
  Token ConsumeNumeric(std::string::iterator *);
  Token ConsumeIdentifier(std::string::iterator *);

  std::string input;
};
}  // namespace aero::syntax::lexer

#endif