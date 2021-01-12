#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexLeftParenShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("(");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftParen, "(", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightParenShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(")");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightParen, ")", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLeftCurlyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("{");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftCurly, "{", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightCurlyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("}");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightCurly, "}", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLeftSquareShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("[");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftSquare, "[", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightSquareShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("]");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightSquare, "]", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSemicolonShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(";");
  std::vector<lexer::Token> expected = {{SyntaxKind::Semicolon, ";", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexColonShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(":");
  std::vector<lexer::Token> expected = {{SyntaxKind::Colon, ":", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCommaShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(",");
  std::vector<lexer::Token> expected = {{SyntaxKind::Comma, ",", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexUnderscoreShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("_");
  std::vector<lexer::Token> expected = {{SyntaxKind::Underscore, "_", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexEqualArrowShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("=>");
  std::vector<lexer::Token> expected = {{SyntaxKind::EqualArrow, "=>", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace