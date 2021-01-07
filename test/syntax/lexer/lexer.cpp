#include "syntax/lexer/lexer.hpp"

#include "gtest/gtest.h"
#include "syntax/lexer/token.hpp"
#include "syntax/syntax_kind.hpp"

TEST(LexerTest, ExpectIdentifier) {
  aero::syntax::lexer::Lexer l("myIdentifier");
  std::vector<aero::syntax::lexer::Token> tokens = l.Tokenize();
  std::vector<aero::syntax::lexer::Token> expected = {
      aero::syntax::lexer::Token(aero::syntax::SyntaxKind::Identifier,
                                 "myIdentifier")};

  ASSERT_EQ(tokens[0].Kind(), expected[0].Kind());
  ASSERT_EQ(tokens[0].Text(), expected[0].Text());
}