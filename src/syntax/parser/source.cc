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
    return {};
  }
}

std::optional<SyntaxKind> Source::PeekKind() {
  EatTrivia();
  return PeekKindRaw();
}

std::optional<SyntaxKind> Source::PeekNKind(size_t n) {
  size_t runner = cursor;
  size_t i = 0;

  while (runner < tokens.size() && i < n) {
    while (IsTrivia(tokens[runner].Kind())) {
      runner += 1;
    }
    runner += 1;
    i += 1;
  }
  while (runner < tokens.size() && IsTrivia(tokens[runner].Kind())) {
    runner += 1;
  }
  if (runner < tokens.size()) {
    return {tokens[runner].Kind()};
  } else {
    return {};
  }
}

std::optional<lexer::Token> Source::PeekToken() {
  EatTrivia();
  return PeekTokenRaw();
}

std::optional<std::pair<size_t, size_t>> Source::LastTokenRange() {
  if (tokens.size() > 0) {
    return {tokens.back().Range()};
  } else {
    return {};
  }
}

std::optional<lexer::Token> Source::PeekTokenRaw() {
  if (cursor < tokens.size()) {
    return {tokens.at(cursor)};
  } else {
    return {};
  }
}

std::optional<SyntaxKind> Source::PeekKindRaw() {
  if (cursor < tokens.size()) {
    return {tokens.at(cursor).Kind()};
  } else {
    return {};
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
    return IsTrivia(*opt);
  } else {
    return false;
  }
}
}  // namespace aero::syntax::parser