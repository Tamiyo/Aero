#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexWhitespaceShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(" ");
  std::vector<lexer::Token> expected = {{SyntaxKind::Whitespace, " ", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexNewlineShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("\n");
  std::vector<lexer::Token> expected = {{SyntaxKind::Newline, "\n", {0, 1}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCommentShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("# comment");
  std::vector<lexer::Token> expected = {{SyntaxKind::Comment, "# comment", {0, 9}}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace