#include "syntax/parser/parser.hpp"

#include "syntax/parser/marker.hpp"
#include "syntax/parser/tree/expr.hpp"

namespace aero::syntax::parser {
Marker Start(Parser &p) {
  size_t pos = p.events.size();
  p.events.push_back(Event(EventType::Placeholder, std::nullopt));

  return Marker(pos);
}

std::optional<SyntaxKind> Peek(Parser &p) { return p.source.PeekKind(); }

bool PeekAt(Parser &p, SyntaxKind kind) {
  if (auto peeked = Peek(p); peeked) {
    return *peeked == kind;
  } else {
    return false;
  }
}

bool AtEnd(Parser &p) { return Peek(p) == std::nullopt; }

void Bump(Parser &p) {
  p.source.NextToken();
  p.events.push_back(Event(EventType::AddToken, std::nullopt));
}

void Parse(Parser &p) {
  Marker m = Start(p);

  // AST Here!
  tree::Expr::Expr(p);

  m.Complete(p, SyntaxKind::Root);
}
}  // namespace aero::syntax::parser