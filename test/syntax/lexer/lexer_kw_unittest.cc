#include "gtest/gtest.h"
#include "syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexAndKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("and");
  std::vector<lexer::Token> expected = {{SyntaxKind::AndKw, "and", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexOrKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("or");
  std::vector<lexer::Token> expected = {{SyntaxKind::OrKw, "or", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexIfKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("if");
  std::vector<lexer::Token> expected = {{SyntaxKind::IfKw, "if", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexElseKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("else");
  std::vector<lexer::Token> expected = {{SyntaxKind::ElseKw, "else", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexElifKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("elif");
  std::vector<lexer::Token> expected = {{SyntaxKind::ElifKw, "elif", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBreakKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("break");
  std::vector<lexer::Token> expected = {{SyntaxKind::BreakKw, "break", {0, 5}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexWhileKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("while");
  std::vector<lexer::Token> expected = {{SyntaxKind::WhileKw, "while", {0, 5}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexLoopKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("loop");
  std::vector<lexer::Token> expected = {{SyntaxKind::LoopKw, "loop", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexInKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("in");
  std::vector<lexer::Token> expected = {{SyntaxKind::InKw, "in", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexComponentKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("component");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::ComponentKw, "component", {0, 9}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexEnumKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("enum");
  std::vector<lexer::Token> expected = {{SyntaxKind::EnumKw, "enum", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStructKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("struct");
  std::vector<lexer::Token> expected = {
      {SyntaxKind::StructKw, "struct", {0, 6}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexImplKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("impl");
  std::vector<lexer::Token> expected = {{SyntaxKind::ImplKw, "impl", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexMyKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("my");
  std::vector<lexer::Token> expected = {{SyntaxKind::MyKw, "my", {0, 2}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexTrueKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("true");
  std::vector<lexer::Token> expected = {{SyntaxKind::TrueKw, "true", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexFalseKwShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("false");
  std::vector<lexer::Token> expected = {{SyntaxKind::FalseKw, "false", {0, 5}}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace