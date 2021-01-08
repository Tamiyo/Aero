#ifndef AERO_AST_BUILDER_HPP
#define AERO_AST_BUILDER_HPP

#include <deque>

#include "syntax/ast/element.h"

namespace aero::syntax::ast {
class GreenNodeBuilder {
 public:
  GreenNodeBuilder() = default;

  void Token(SyntaxKind, std::string);
  void StartNode(SyntaxKind);
  void FinishNode();

  GreenNode Finish();

 private:
  // cache optimizations go here

  std::deque<GreenNode> parents;
  std::deque<GreenElement> children;
};
}  // namespace aero::syntax::ast

#endif