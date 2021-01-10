#include "syntax/parser/tree/stmt.h"

#include <fmt/core.h>

#include <cassert>
#include <magic_enum.hpp>

#include "syntax/parser/tree/expr.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;
using namespace aero::syntax::parser;

std::optional<CompletedMarker> VariableDecl(Parser &p) { return {}; }

std::optional<CompletedMarker> FunctionDecl(Parser &p) { return {}; }
}  // namespace

namespace aero::syntax::parser::tree::stmt {
std::optional<CompletedMarker> Stmt(Parser &p) { return expr::Expr(p); }
}  // namespace aero::syntax::parser::tree::stmt