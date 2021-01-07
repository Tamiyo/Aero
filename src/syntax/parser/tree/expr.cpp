#include "syntax/parser/tree/expr.hpp"

#include <spdlog/spdlog.h>

#include <cassert>
#include <cstdint>
#include <magic_enum.hpp>

namespace {
using namespace aero::syntax;
using namespace aero::syntax::parser;
using namespace aero::syntax::parser::tree::Expr;

std::optional<CompletedMarker> Lhs(Parser &p);

std::optional<Op> OpFromSyntaxKind(const SyntaxKind &kind) {
  switch (kind) {
    case SyntaxKind::Pipe:
      return {Op::Pipe};
    case SyntaxKind::OrKw:
      return {Op::Or};
    case SyntaxKind::Amp:
      return {Op::Amp};
    case SyntaxKind::AndKw:
      return {Op::And};
    case SyntaxKind::EqualEqual:
      return {Op::EqualEqual};
    case SyntaxKind::BangEqual:
      return {Op::BangEqual};
    case SyntaxKind::LessThan:
      return {Op::LessThan};
    case SyntaxKind::LessThanEqual:
      return {Op::LessThanEqual};
    case SyntaxKind::GreaterThan:
      return {Op::GreaterThan};
    case SyntaxKind::GreaterThanEqual:
      return {Op::GreaterThanEqual};
    case SyntaxKind::Plus:
      return {Op::Add};
    case SyntaxKind::Minus:
      return {Op::Sub};
    case SyntaxKind::Star:
      return {Op::Mul};
    case SyntaxKind::Slash:
      return {Op::Div};
    case SyntaxKind::Mod:
      return {Op::Mod};
    case SyntaxKind::Caret:
      return {Op::Pow};
    case SyntaxKind::Bang:
      return {Op::Bang};
    default:
      return std::nullopt;
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
  if (auto l = Lhs(p); l) {
    for (;;) {
      if (auto peeked = Peek(p); peeked) {
        if (auto op = OpFromSyntaxKind(*peeked); op) {
          std::pair<uint8_t, uint8_t> binding_precedence = Precedence(*op);

          if (binding_precedence.first < minimum_precedence) {
            return std::nullopt;
          }

          Bump(p);

          Marker m = l->Precede(p);
          ExprInner(p, binding_precedence.second);
          *l = m.Complete(p, SyntaxKind::BinaryExpr);
        } else {
          return std::nullopt;
        }
      } else {
        return std::nullopt;
      }
    }
    return {l};
  }
  return std::nullopt;
}

CompletedMarker Literal(Parser &p) {
  Marker m = Start(p);
  Bump(p);
  return m.Complete(p, SyntaxKind::Literal);
}

CompletedMarker VariableRef(Parser &p) {
  assert(PeekAt(p, SyntaxKind::Identifier));

  Marker m = Start(p);
  Bump(p);
  return m.Complete(p, SyntaxKind::VariableRef);
}

CompletedMarker PrefixExpr(Parser &p) {
  Marker m = Start(p);

  if (auto peeked = Peek(p); peeked) {
    if (auto op = OpFromSyntaxKind(*peeked); op) {
      std::pair<uint8_t, uint8_t> binding_precedence = Precedence(*op);
      Bump(p);

      ExprInner(p, binding_precedence.second);
      return m.Complete(p, SyntaxKind::UnaryExpr);
    } else {
      spdlog::error("Couldn't convert op from {}",
                    magic_enum::enum_name(*peeked));
      exit(1);
    }
  } else {
    spdlog::error("Parser at end of input!");
    exit(1);
  }
}

CompletedMarker ParenExpr(Parser &p) {
  assert(PeekAt(p, SyntaxKind::LeftParen));
  Marker m = Start(p);

  Bump(p);
  ExprInner(p, 0);

  assert(PeekAt(p, SyntaxKind::RightParen));
  Bump(p);

  return m.Complete(p, SyntaxKind::ParenExpr);
}

std::optional<CompletedMarker> Lhs(Parser &p) {
  if (auto peeked = Peek(p); peeked) {
    switch (*peeked) {
      case SyntaxKind::Integer:
      case SyntaxKind::Float:
      case SyntaxKind::String:
      case SyntaxKind::TrueKw:
      case SyntaxKind::FalseKw:
        return {Literal(p)};
      case SyntaxKind::Identifier:
        return {VariableRef(p)};
      case SyntaxKind::Minus:
      case SyntaxKind::Bang:
        return {PrefixExpr(p)};
      case SyntaxKind::LeftParen:
        return {ParenExpr(p)};
      default:
        return std::nullopt;  //  impossible
    }
  } else {
    return std::nullopt;
  }
}
}  // namespace

namespace aero::syntax::parser::tree::Expr {
std::optional<CompletedMarker> Expr(Parser &p) { return ExprInner(p, 0); }

}  // namespace aero::syntax::parser::tree::Expr