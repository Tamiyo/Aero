#include "gtest/gtest.h"
#include "lexer.h"
#include "syntax/syntax_kind.h"

namespace {
using namespace aero::syntax;

TEST(AeroLexer, LexI32TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("i32");
  std::vector<lexer::Token> expected = {{SyntaxKind::I32Ty, "i32"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexI64TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("i64");
  std::vector<lexer::Token> expected = {{SyntaxKind::I64Ty, "i64"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexF32TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("f32");
  std::vector<lexer::Token> expected = {{SyntaxKind::F32Ty, "f32"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexF64TyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("f64");
  std::vector<lexer::Token> expected = {{SyntaxKind::F64Ty, "f64"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexStrTyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("str");
  std::vector<lexer::Token> expected = {{SyntaxKind::StrTy, "str"}};

  ASSERT_EQ(tokens, expected);
}

TEST(AeroLexer, LexBoolTyShouldPass) {
  std::vector<lexer::Token> tokens = LexInput("bool");
  std::vector<lexer::Token> expected = {{SyntaxKind::BoolTy, "bool"}};

  ASSERT_EQ(tokens, expected);
}
}  // namespace