#include "syntax/parser/tree/stmt.h"

#include "syntax/parser/tree/expr.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser::tree::stmt {
std::optional<CompletedMarker> Stmt(Parser &p) {
  if (auto peeked = Peek(p)) {
    switch (*peeked) {
      default:
        return expr::Expr(p);
    }
  } else {
    return std::nullopt;
  }
}
}  // namespace aero::syntax::parser::tree::stmt