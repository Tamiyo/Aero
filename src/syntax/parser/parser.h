#ifndef AERO_PARSER_PARSER_HPP
#define AERO_PARSER_PARSER_HPP

#include <deque>
#include <optional>
#include <vector>

#include "syntax/lexer/token.h"
#include "syntax/parser/event.h"
#include "syntax/parser/source.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
class Marker;

struct Parser {
  Source source;

  // Preferred O(1) push and pop AND random access ops.
  // This is why `deque` was chosen over `vector`.
  std::deque<Event> events;
};

void Parse(Parser &);

Marker Start(Parser &);

std::optional<SyntaxKind> Peek(Parser &);
bool PeekAt(Parser &, SyntaxKind);
bool AtEnd(Parser &);

void Bump(Parser &);

}  // namespace aero::syntax::parser

#endif