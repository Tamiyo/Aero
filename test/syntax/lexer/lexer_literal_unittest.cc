#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexIdentifierShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("ident");
  std::vector<lexer::Token> expected = {{SyntaxKind::Identifier, "ident"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFloatShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("23.95");
  std::vector<lexer::Token> expected = {{SyntaxKind::Float, "23.95"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFloatLeadingZeroShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("0.95");
  std::vector<lexer::Token> expected = {{SyntaxKind::Float, "0.95"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexIntegerShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("12");
  std::vector<lexer::Token> expected = {{SyntaxKind::Integer, "12"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStringShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("\"Hello!\"");
  std::vector<lexer::Token> expected = {{SyntaxKind::String, "\"Hello!\""}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMultipleLiteralsShouldPass) {
  std::vector<lexer::Token> tokens =
      LexInput("ident 23.95 12 \"Hello World!\"");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::Identifier, "ident"},
      {SyntaxKind::Whitespace, " "},
      {SyntaxKind::Float, "23.95"},
      {SyntaxKind::Whitespace, " "},
      {SyntaxKind::Integer, "12"},
      {SyntaxKind::Whitespace, " "},
      {SyntaxKind::String, "\"Hello World!\""},
  };

  ASSERT_EQ(tokens, expected);
}
}  // namespace