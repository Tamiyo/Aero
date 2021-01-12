#include "gtest/gtest.h"
#include "src/syntax/syntax_kind.h"
#include "test/syntax/lexer/lexer.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexI32TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("i32");
  std::vector<lexer::Token> expected = {{SyntaxKind::I32Ty, "i32", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexI64TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("i64");
  std::vector<lexer::Token> expected = {{SyntaxKind::I64Ty, "i64", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexF32TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("f32");
  std::vector<lexer::Token> expected = {{SyntaxKind::F32Ty, "f32", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexF64TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("f64");
  std::vector<lexer::Token> expected = {{SyntaxKind::F64Ty, "f64", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStrTyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("str");
  std::vector<lexer::Token> expected = {{SyntaxKind::StrTy, "str", {0, 3}}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBoolTyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("bool");
  std::vector<lexer::Token> expected = {{SyntaxKind::BoolTy, "bool", {0, 4}}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace