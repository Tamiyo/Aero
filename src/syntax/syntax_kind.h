#ifndef AERO_SYNTAX_SYNTAX_KIND_H
#define AERO_SYNTAX_SYNTAX_KIND_H

#include "fmt/ostream.h"
#include "magic_enum.hpp"

namespace aero::syntax {
enum class SyntaxKind {
  // Punctuation
  LeftParen = 1,
  RightParen,
  LeftCurly,
  RightCurly,
  LeftSquare,
  RightSquare,
  Semicolon,
  Colon,
  Comma,
  Underscore,
  EqualArrow,

  // Literals
  __LITERALS,
  Integer,
  Float,
  String,

  // Tokens
  __TOKENS,
  Whitespace,
  Newline,
  Identifier,
  Comment,

  // Operators
  __OPERATORS,
  Amp,
  Pipe,
  Plus,
  Minus,
  Star,
  Slash,
  Mod,
  Caret,
  Dot,
  LessThan,
  GreaterThan,
  Equal,
  Bang,
  ShiftLeft,
  ShiftRight,
  DotDot,
  EqualEqual,
  BangEqual,
  LessThanEqual,
  GreaterThanEqual,
  PlusEqual,
  MinusEqual,
  StarEqual,
  SlashEqual,
  ModEqual,
  ShiftLeftEqual,
  ShiftRightEqual,
  AmpEqual,
  PipeEqual,
  CaretEqual,

  // Keywords
  __KEYWORDS,
  AndKw,
  OrKw,
  IfKw,
  ElseKw,
  ElifKw,
  BreakKw,
  WhileKw,
  LoopKw,
  ForKw,
  InKw,
  ComponentKw,
  EnumKw,
  StructKw,
  ImplKw,
  MyKw,
  TrueKw,
  FalseKw,

  // Builtin Types
  __TYPES,
  I32Ty,
  I64Ty,
  F32Ty,
  F64Ty,
  StrTy,
  BoolTy,

  // Nodes
  __NODES,
  Root,
  Error,
  Placeholder,

  BinaryExpr,
  UnaryExpr,
  ParenExpr,
  Literal,
  VariableRef,

  VariableDecl,
  FunctionDecl,
};

std::ostream& operator<<(std::ostream&, const SyntaxKind&);

bool IsTrivia(SyntaxKind);
bool IsType(SyntaxKind);
}  // namespace aero::syntax

#endif