#ifndef AERO_PARSER_SOURCE_H
#define AERO_PARSER_SOURCE_H

#include <optional>
#include <vector>

#include "syntax/lexer/token.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
class Source {
 public:
  Source(const std::vector<lexer::Token> &);
  Source() = delete;
  Source(const Source &) = default;
  ~Source() = default;

  std::optional<lexer::Token> NextToken();
  std::optional<SyntaxKind> PeekKind();
  std::optional<SyntaxKind> PeekNKind(size_t);

 private:
  std::optional<SyntaxKind> PeekKindRaw();

  void EatTrivia();
  bool AtTrivia();

  std::vector<lexer::Token> tokens;
  size_t cursor;
};
}  // namespace aero::syntax::parser

#endif