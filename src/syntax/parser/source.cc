#include "syntax/parser/source.h"

namespace aero::syntax::parser {
Source::Source(const std::vector<lexer::Token> &t) {
  this->tokens = t;
  this->cursor = 0;
}

std::optional<lexer::Token> Source::NextToken() {
  EatTrivia();

  if (cursor < tokens.size()) {
    lexer::Token Token = tokens.at(cursor);
    cursor += 1;
    return std::optional<lexer::Token>{Token};
  } else {
    return std::nullopt;
  }
}

std::optional<SyntaxKind> Source::PeekKind() {
  EatTrivia();
  return PeekKindRaw();
}

std::optional<SyntaxKind> Source::PeekKindRaw() {
  if (cursor < tokens.size()) {
    return std::optional<SyntaxKind>{tokens[cursor].Kind()};
  } else {
    return std::nullopt;
  }
}

void Source::EatTrivia() {
  while (AtTrivia()) {
    cursor += 1;
  }
}

bool Source::AtTrivia() {
  std::optional<SyntaxKind> opt = PeekKindRaw();

  if (opt.has_value()) {
    return is_trivia(*opt);
  } else {
    return false;
  }
}
}  // namespace aero::syntax::parser