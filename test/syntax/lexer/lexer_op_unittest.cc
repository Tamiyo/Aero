#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexAmpShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("&");
  std::vector<lexer::Token> expected = {{SyntaxKind::Amp, "&", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPipeShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("|");
  std::vector<lexer::Token> expected = {{SyntaxKind::Pipe, "|", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPlusShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("+");
  std::vector<lexer::Token> expected = {{SyntaxKind::Plus, "+", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMinusShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("-");
  std::vector<lexer::Token> expected = {{SyntaxKind::Minus, "-", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStarShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("*");
  std::vector<lexer::Token> expected = {{SyntaxKind::Star, "*", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSlashShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("/");
  std::vector<lexer::Token> expected = {{SyntaxKind::Slash, "/", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexModShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("%");
  std::vector<lexer::Token> expected = {{SyntaxKind::Mod, "%", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCaretShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("^");
  std::vector<lexer::Token> expected = {{SyntaxKind::Caret, "^", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexDotShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(".");
  std::vector<lexer::Token> expected = {{SyntaxKind::Dot, ".", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLessThanShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<");
  std::vector<lexer::Token> expected = {{SyntaxKind::LessThan, "<", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexGreaterThanShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">");
  std::vector<lexer::Token> expected = {{SyntaxKind::GreaterThan, ">", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("=");
  std::vector<lexer::Token> expected = {{SyntaxKind::Equal, "=", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBangShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("!");
  std::vector<lexer::Token> expected = {{SyntaxKind::Bang, "!", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftLeftShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<<");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftLeft, "<<", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftRightShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">>");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftRight, ">>", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexDotDotShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("..");
  std::vector<lexer::Token> expected = {{SyntaxKind::DotDot, "..", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexEqualEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("==");
  std::vector<lexer::Token> expected = {{SyntaxKind::EqualEqual, "==", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBangEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("!=");
  std::vector<lexer::Token> expected = {{SyntaxKind::BangEqual, "!=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLessThanEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<=");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::LessThanEqual, "<=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexGreaterThanEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">=");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::GreaterThanEqual, ">=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPlusEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("+=");
  std::vector<lexer::Token> expected = {{SyntaxKind::PlusEqual, "+=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMinusEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("-=");
  std::vector<lexer::Token> expected = {{SyntaxKind::MinusEqual, "-=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStarEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("*=");
  std::vector<lexer::Token> expected = {{SyntaxKind::StarEqual, "*=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSlashEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("/=");
  std::vector<lexer::Token> expected = {{SyntaxKind::SlashEqual, "/=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexModEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("%=");
  std::vector<lexer::Token> expected = {{SyntaxKind::ModEqual, "%=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftLeftEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<<=");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::ShiftLeftEqual, "<<=", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftRightEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">>=");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::ShiftRightEqual, ">>=", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexAmpEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("&=");
  std::vector<lexer::Token> expected = {{SyntaxKind::AmpEqual, "&=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPipeEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("|=");
  std::vector<lexer::Token> expected = {{SyntaxKind::PipeEqual, "|=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCaretEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("^=");
  std::vector<lexer::Token> expected = {{SyntaxKind::CaretEqual, "^=", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace