#ifndef AERO_PARSER_SOURCE_HPP
#define AERO_PARSER_SOURCE_HPP

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

 private:
  std::optional<SyntaxKind> PeekKindRaw();

  void EatTrivia();
  bool AtTrivia();

  std::vector<lexer::Token> tokens;
  size_t cursor;
};
}  // namespace aero::syntax::parser

#endif