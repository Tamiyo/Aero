#include "lexer.h"

std::vector<aero::syntax::lexer::Token> LexInput(std::string input) {
  aero::syntax::lexer::Lexer lexer(input);
  return lexer.Tokenize();
}