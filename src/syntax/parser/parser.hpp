#ifndef AERO_PARSER_PARSER_HPP
#define AERO_PARSER_PARSER_HPP

#include <deque>
#include <optional>
#include <vector>

#include "syntax/lexer/token.hpp"
#include "syntax/parser/event.hpp"
#include "syntax/parser/source.hpp"
#include "syntax/syntax_kind.hpp"

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