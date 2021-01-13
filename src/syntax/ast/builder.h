#ifndef AERO_AST_BUILDER_H
#define AERO_AST_BUILDER_H

#include <deque>
#include <unordered_set>

#include "syntax/ast/element.h"

// Built upon Rust's Rowan implementation 
namespace aero::syntax::ast {
class GreenNodeBuilder {
 public:
  GreenNodeBuilder() = default;

  void Token(SyntaxKind, std::string);
  void StartNode(SyntaxKind);
  void FinishNode();

  GreenNode Finish();

 private:
  // cache optimizations
  std::unordered_set<GreenNode> nodes;
  std::unordered_set<GreenToken> tokens;

  std::deque<GreenNode> parents;
  std::deque<GreenElement> children;
};
}  // namespace aero::syntax::ast

#endif