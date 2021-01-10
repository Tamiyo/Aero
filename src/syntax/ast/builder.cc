#include "syntax/ast/builder.h"

#include <spdlog/spdlog.h>

#include <cassert>
#include <iterator>
#include <vector>

namespace aero::syntax::ast {
void GreenNodeBuilder::Token(SyntaxKind kind, std::string text) {
  // Cache optimizations here
  GreenElement e = GreenElement(GreenToken{kind, text});
  children.push_back(e);
}

void GreenNodeBuilder::StartNode(SyntaxKind kind) {
  size_t text_len = children.size();
  parents.push_back(GreenNode{kind, text_len, {}});
}

void GreenNodeBuilder::FinishNode() {
  GreenNode parent = parents.back();
  parents.pop_back();

  std::deque<GreenElement>::iterator middle(children.begin());
  std::advance(middle, parent.text_len);

  std::deque<std::shared_ptr<GreenElement>> node_children;
  for (auto x : std::vector<GreenElement>(middle, children.end())) {
    node_children.push_back(std::make_shared<GreenElement>(x));
  }

  children.erase(middle, children.end());

  GreenNode new_child{parent.kind, parent.text_len, node_children};
  children.push_back(new_child);
}

GreenNode GreenNodeBuilder::Finish() {
  if (children.size() != 1) {
    spdlog::error("Parents Size: {}\n", parents.size());
    spdlog::error("Expected children to only have one element : HAD {}",
                  children.size());
    exit(1);
  }

  GreenElement element = children.back();
  children.pop_back();

  if (auto el = std::get_if<GreenNode>(&element)) {
    return *el;
  } else {
    spdlog::error("Expected GreenNode to be last element, not GreenToken");
    exit(1);
  }
}
}  // namespace aero::syntax::ast