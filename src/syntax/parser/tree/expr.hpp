#ifndef AERO_PARSER_TREE_EXPR_HPP
#define AERO_PARSER_TREE_EXPR_HPP

#include <optional>
#include <utility>

#include "syntax/parser/marker.hpp"
#include "syntax/parser/parser.hpp"
#include "syntax/syntax_kind.hpp"

namespace aero::syntax::parser::tree::Expr {
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
  Bang
};

std::optional<CompletedMarker> Expr(Parser &);

}  // namespace aero::syntax::parser::tree::Expr

#endif