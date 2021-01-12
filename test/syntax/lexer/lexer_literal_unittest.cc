#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexIdentifierShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("ident");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::Identifier, "ident", {0, 5}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFloatShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("23.95");
  std::vector<lexer::Token> expected = {{SyntaxKind::Float, "23.95", {0, 5}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFloatLeadingZeroShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("0.95");
  std::vector<lexer::Token> expected = {{SyntaxKind::Float, "0.95", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexIntegerShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("12");
  std::vector<lexer::Token> expected = {{SyntaxKind::Integer, "12", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStringShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("\"Hello!\"");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::String, "\"Hello!\"", {0, 8}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMultipleLiteralsShouldPass) {
  std::vector<lexer::Token> tokens =
      LexInput("ident 23.95 12 \"Hello!\"");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::Identifier, "ident", {0, 5}},
      {SyntaxKind::Whitespace, " ", {0, 1}},
      {SyntaxKind::Float, "23.95", {0, 5}},
      {SyntaxKind::Whitespace, " ", {0, 1}},
      {SyntaxKind::Integer, "12", {0, 2}},
      {SyntaxKind::Whitespace, " ", {0, 1}},
      {SyntaxKind::String, "\"Hello!\"", {0, 8}}};
  ASSERT_EQ(tokens, expected);
}
}  // namespace