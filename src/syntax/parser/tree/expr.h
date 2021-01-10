#ifndef AERO_PARSER_TREE_EXPR_H
#define AERO_PARSER_TREE_EXPR_H

#include <optional>

#include "syntax/parser/marker.h"
#include "syntax/parser/parser.h"

namespace aero::syntax::parser::tree::expr {
enum class Op {
  Pipe = 1,
  Or,
  Amp,
  And,
  EqualEqual,
  BangEqual,
  LessThan,
  LessThanEqual,
  GreaterThan,
  GreaterThanEqual,
  Add,
  Sub,
  Mul,
  Div,
  Mod,
  Pow,
  Bang,
};

std::optional<CompletedMarker> Expr(Parser &);
}  // namespace aero::syntax::parser::tree::expr

#endif