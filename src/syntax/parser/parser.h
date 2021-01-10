#ifndef AERO_PARSER_PARSER_H
#define AERO_PARSER_PARSER_H

#include <deque>
#include <optional>
#include <vector>

#include "syntax/lexer/token.h"
#include "syntax/parser/context/token_kind.h"
#include "syntax/parser/event.h"
#include "syntax/parser/source.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
class Marker;

class Parser {
 public:
  Parser(Source);
  Parser() = delete;
  Parser(const Parser&) = default;
  ~Parser() = default;

  Marker Start();

  void Parse();

  void Expect(SyntaxKind);
  void Error();

  bool At(SyntaxKind);
  bool AtExact(SyntaxKind);
  bool AtLiteral();
  bool AtEnd();
  bool AtSet();

  void Bump();

  Event& GetEventAt(size_t);
  void SetEventAt(size_t, Event);
  void AddEvent(Event);
  std::vector<Event>& Events();

 private:
  std::optional<SyntaxKind> Peek();

  Source source;
  std::vector<Event> events;
  std::vector<context::TokenKind> expected_kinds;
};
}  // namespace aero::syntax::parser

#endif