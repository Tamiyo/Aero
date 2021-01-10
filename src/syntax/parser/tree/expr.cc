#include "syntax/parser/tree/expr.h"

#include <spdlog/spdlog.h>

#include <cassert>
#include <cstdint>
#include <magic_enum.hpp>

#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;
using namespace aero::syntax::parser;
using namespace aero::syntax::parser::tree::expr;

std::optional<CompletedMarker> Lhs(Parser &p);

std::optional<Op> OpFromSyntaxKind(Parser &p) {
  if (p.At(SyntaxKind::Pipe)) {
    return {Op::Pipe};
  } else if (p.At(SyntaxKind::OrKw)) {
    return {Op::Or};
  } else if (p.At(SyntaxKind::OrKw)) {
    return {Op::Or};
  } else if (p.At(SyntaxKind::Amp)) {
    return {Op::Amp};
  } else if (p.At(SyntaxKind::AndKw)) {
    return {Op::And};
  } else if (p.At(SyntaxKind::EqualEqual)) {
    return {Op::EqualEqual};
  } else if (p.At(SyntaxKind::BangEqual)) {
    return {Op::BangEqual};
  } else if (p.At(SyntaxKind::LessThan)) {
    return {Op::LessThan};
  } else if (p.At(SyntaxKind::LessThanEqual)) {
    return {Op::LessThanEqual};
  } else if (p.At(SyntaxKind::GreaterThan)) {
    return {Op::GreaterThan};
  } else if (p.At(SyntaxKind::GreaterThanEqual)) {
    return {Op::GreaterThanEqual};
  } else if (p.At(SyntaxKind::Plus)) {
    return {Op::Add};
  } else if (p.At(SyntaxKind::Minus)) {
    return {Op::Sub};
  } else if (p.At(SyntaxKind::Star)) {
    return {Op::Mul};
  } else if (p.At(SyntaxKind::Slash)) {
    return {Op::Div};
  } else if (p.At(SyntaxKind::Mod)) {
    return {Op::Mod};
  } else if (p.At(SyntaxKind::Caret)) {
    return {Op::Pow};
  } else if (p.At(SyntaxKind::Bang)) {
    return {Op::Bang};
  } else {
    return {};
  }
}

std::pair<uint8_t, uint8_t> Precedence(Op &op) {
  switch (op) {
    case Op::Pipe:
    case Op::Or:
      return {3, 4};
    case Op::Amp:
    case Op::And:
      return {5, 6};
    case Op::EqualEqual:
    case Op::BangEqual:
      return {7, 8};
    case Op::LessThan:
    case Op::LessThanEqual:
    case Op::GreaterThan:
    case Op::GreaterThanEqual:
      return {9, 10};
    case Op::Add:
    case Op::Sub:
      return {11, 12};
    case Op::Mul:
    case Op::Div:
    case Op::Mod:
      return {13, 14};
    case Op::Pow:
      return {15, 16};
    case Op::Bang:
      return {17, 18};  // TODO: Fix this ordering
    default:
      return {0, 0};  // Impossible
  }
}

std::optional<CompletedMarker> ExprInner(Parser &p,
                                         uint8_t minimum_precedence) {
  if (auto lhs = Lhs(p)) {
    for (;;) {
      if (auto op = OpFromSyntaxKind(p)) {
        std::pair<uint8_t, uint8_t> precedence = Precedence(*op);

        if (precedence.first < minimum_precedence) {
          return std::nullopt;
        }

        p.Bump();

        Marker m = lhs->Precede(p);
        ExprInner(p, precedence.second);

        lhs.emplace(m.Complete(p, SyntaxKind::BinaryExpr));
      } else {
        break;
      }
    }
    return {lhs};
  }
  return std::nullopt;
}

CompletedMarker Literal(Parser &p) {
  Marker m = p.Start();
  p.Bump();
  return m.Complete(p, SyntaxKind::Literal);
}

CompletedMarker VariableRef(Parser &p) {
  assert(p.At(SyntaxKind::Identifier));

  Marker m = p.Start();
  p.Bump();
  return m.Complete(p, SyntaxKind::VariableRef);
}

CompletedMarker PrefixExpr(Parser &p) {
  Marker m = p.Start();
  return m.Complete(p, SyntaxKind::UnaryExpr);
}

CompletedMarker ParenExpr(Parser &p) {
  assert(p.At(SyntaxKind::LeftParen));
  Marker m = p.Start();

  p.Bump();
  ExprInner(p, 0);

  p.Expect(SyntaxKind::RightParen);
  return m.Complete(p, SyntaxKind::ParenExpr);
}

std::optional<CompletedMarker> Lhs(Parser &p) {
  if (p.At(SyntaxKind::Integer) || p.At(SyntaxKind::Float) ||
      p.At(SyntaxKind::String) || p.At(SyntaxKind::TrueKw) ||
      p.At(SyntaxKind::FalseKw)) {
    return {Literal(p)};
  } else if (p.At(SyntaxKind::Identifier)) {
    return {VariableRef(p)};
  } else if (p.At(SyntaxKind::Minus) || p.At(SyntaxKind::Bang)) {
    return {PrefixExpr(p)};
  } else if (p.At(SyntaxKind::LeftParen)) {
    return {ParenExpr(p)};
  } else {
    p.Error();
    return {};
  }
}
}  // namespace

namespace aero::syntax::parser::tree::expr {
std::optional<CompletedMarker> Expr(Parser &p) { return ExprInner(p, 0); }
}  // namespace aero::syntax::parser::tree::expr