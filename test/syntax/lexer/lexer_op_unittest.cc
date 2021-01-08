#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexAmpShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("&");
  std::vector<lexer::Token> expected = {{SyntaxKind::Amp, "&"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPipeShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("|");
  std::vector<lexer::Token> expected = {{SyntaxKind::Pipe, "|"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPlusShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("+");
  std::vector<lexer::Token> expected = {{SyntaxKind::Plus, "+"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMinusShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("-");
  std::vector<lexer::Token> expected = {{SyntaxKind::Minus, "-"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStarShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("*");
  std::vector<lexer::Token> expected = {{SyntaxKind::Star, "*"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSlashShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("/");
  std::vector<lexer::Token> expected = {{SyntaxKind::Slash, "/"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexModShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("%");
  std::vector<lexer::Token> expected = {{SyntaxKind::Mod, "%"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCaretShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("^");
  std::vector<lexer::Token> expected = {{SyntaxKind::Caret, "^"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexDotShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(".");
  std::vector<lexer::Token> expected = {{SyntaxKind::Dot, "."}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLessThanShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<");
  std::vector<lexer::Token> expected = {{SyntaxKind::LessThan, "<"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexGreaterThanShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">");
  std::vector<lexer::Token> expected = {{SyntaxKind::GreaterThan, ">"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("=");
  std::vector<lexer::Token> expected = {{SyntaxKind::Equal, "="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBangShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("!");
  std::vector<lexer::Token> expected = {{SyntaxKind::Bang, "!"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftLeftShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<<");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftLeft, "<<"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftRightShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">>");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftRight, ">>"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexDotDotShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("..");
  std::vector<lexer::Token> expected = {{SyntaxKind::DotDot, ".."}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexEqualEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("==");
  std::vector<lexer::Token> expected = {{SyntaxKind::EqualEqual, "=="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBangEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("!=");
  std::vector<lexer::Token> expected = {{SyntaxKind::BangEqual, "!="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLessThanEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<=");
  std::vector<lexer::Token> expected = {{SyntaxKind::LessThanEqual, "<="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexGreaterThanEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">=");
  std::vector<lexer::Token> expected = {{SyntaxKind::GreaterThanEqual, ">="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPlusEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("+=");
  std::vector<lexer::Token> expected = {{SyntaxKind::PlusEqual, "+="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMinusEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("-=");
  std::vector<lexer::Token> expected = {{SyntaxKind::MinusEqual, "-="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStarEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("*=");
  std::vector<lexer::Token> expected = {{SyntaxKind::StarEqual, "*="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSlashEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("/=");
  std::vector<lexer::Token> expected = {{SyntaxKind::SlashEqual, "/="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexModEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("%=");
  std::vector<lexer::Token> expected = {{SyntaxKind::ModEqual, "%="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftLeftEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("<<=");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftLeftEqual, "<<="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexShiftRightEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(">>=");
  std::vector<lexer::Token> expected = {{SyntaxKind::ShiftRightEqual, ">>="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexAmpEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("&=");
  std::vector<lexer::Token> expected = {{SyntaxKind::AmpEqual, "&="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexPipeEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("|=");
  std::vector<lexer::Token> expected = {{SyntaxKind::PipeEqual, "|="}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCaretEqualShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("^=");
  std::vector<lexer::Token> expected = {{SyntaxKind::CaretEqual, "^="}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace