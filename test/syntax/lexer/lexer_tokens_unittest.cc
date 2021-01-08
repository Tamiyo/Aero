#include "gtest/gtest.h"
#include "lexer.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexWhitespaceShouldPass) {
  std::vector<lexer::Token> tokens = LexInput(" ");
  std::vector<lexer::Token> expected = {{SyntaxKind::Whitespace, " "}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexNewlineShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("\n");
  std::vector<lexer::Token> expected = {{SyntaxKind::Newline, "\n"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexCommentShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("# comment");
  std::vector<lexer::Token> expected = {{SyntaxKind::Comment, "# comment"}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace