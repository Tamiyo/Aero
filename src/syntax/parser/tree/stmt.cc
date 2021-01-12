#include "syntax/parser/tree/stmt.h"

#include <fmt/core.h>

#include <cassert>

#include "syntax/parser/tree/expr.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;
using namespace aero::syntax::parser;

std::optional<CompletedMarker> VariableDecl(Parser &p) {
  assert(p.At(SyntaxKind::Identifier));

  Marker m = p.Start();
  p.Bump();

  p.Expect(SyntaxKind::Equal);

  tree::expr::Expr(p);

  return m.Complete(p, SyntaxKind::VariableDecl);
}
}  // namespace

namespace aero::syntax::parser::tree::stmt {
std::optional<CompletedMarker> Stmt(Parser &p) { return expr::Expr(p); }
}  // namespace aero::syntax::parser::tree::stmt