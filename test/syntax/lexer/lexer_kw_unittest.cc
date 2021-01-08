#include "gtest/gtest.h"
#include "lexer.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexAndKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("and");
  std::vector<lexer::Token> expected = {{SyntaxKind::AndKw, "and"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexOrKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("or");
  std::vector<lexer::Token> expected = {{SyntaxKind::OrKw, "or"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexIfKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("if");
  std::vector<lexer::Token> expected = {{SyntaxKind::IfKw, "if"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexElseKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("else");
  std::vector<lexer::Token> expected = {{SyntaxKind::ElseKw, "else"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexElifKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("elif");
  std::vector<lexer::Token> expected = {{SyntaxKind::ElifKw, "elif"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBreakKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("break");
  std::vector<lexer::Token> expected = {{SyntaxKind::BreakKw, "break"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexWhileKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("while");
  std::vector<lexer::Token> expected = {{SyntaxKind::WhileKw, "while"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLoopKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("loop");
  std::vector<lexer::Token> expected = {{SyntaxKind::LoopKw, "loop"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexInKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("in");
  std::vector<lexer::Token> expected = {{SyntaxKind::InKw, "in"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexComponentKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("component");
  std::vector<lexer::Token> expected = {{SyntaxKind::ComponentKw, "component"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexEnumKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("enum");
  std::vector<lexer::Token> expected = {{SyntaxKind::EnumKw, "enum"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStructKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("struct");
  std::vector<lexer::Token> expected = {{SyntaxKind::StructKw, "struct"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexImplKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("impl");
  std::vector<lexer::Token> expected = {{SyntaxKind::ImplKw, "impl"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMyKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("my");
  std::vector<lexer::Token> expected = {{SyntaxKind::MyKw, "my"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexTrueKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("true");
  std::vector<lexer::Token> expected = {{SyntaxKind::TrueKw, "true"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFalseKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("false");
  std::vector<lexer::Token> expected = {{SyntaxKind::FalseKw, "false"}};

  ASSERT_EQ(tokens, expected);
}
}