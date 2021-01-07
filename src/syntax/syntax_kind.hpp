#ifndef AERO_SYNTAX_SYNTAX_KIND_HPP
#define AERO_SYNTAX_SYNTAX_KIND_HPP

namespace aero::syntax {
enum class SyntaxKind {
  // Literals
  Integer = 1,
  Float,
  String,

  // Tokens
  Whitespace,
  Newline,
  Identifier,
  Comment,

  // Punctuation
  LeftParen,
  RightParen,
  LeftCurly,
  RightCurly,
  LeftSquare,
  RightSquare,
  Semicolon,
  Colon,
  Comma,
  Underscore,
  DashArrow,
  EqualArrow,

  // Operators
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
  I32Ty,
  I64Ty,
  F32Ty,
  F64Ty,
  StrTy,
  BoolTy,

  // Nodes
  Root,
  BinaryExpr,
  UnaryExpr,
  ParenExpr,
  Literal,
  VariableRef,
};

bool is_trivia(SyntaxKind);
}  // namespace aero::syntax

#endif