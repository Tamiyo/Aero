#include "gtest/gtest.h"
#include "lexer.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexLeftParenShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("(");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftParen, "("}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightParenShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(")");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightParen, ")"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLeftCurlyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("{");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftCurly, "{"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightCurlyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("}");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightCurly, "}"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLeftSquareShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("[");
  std::vector<lexer::Token> expected = {{SyntaxKind::LeftSquare, "["}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexRightSquareShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("]");
  std::vector<lexer::Token> expected = {{SyntaxKind::RightSquare, "]"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexSemicolonShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(";");
  std::vector<lexer::Token> expected = {{SyntaxKind::Semicolon, ";"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexColonShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(":");
  std::vector<lexer::Token> expected = {{SyntaxKind::Colon, ":"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCommaShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(",");
  std::vector<lexer::Token> expected = {{SyntaxKind::Comma, ","}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexUnderscoreShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("_");
  std::vector<lexer::Token> expected = {{SyntaxKind::Underscore, "_"}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace