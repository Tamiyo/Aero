
#ifndef AERO_AST_ELEMENT_H
#define AERO_AST_ELEMENT_H

#include <deque>
#include <memory>
#include <variant>

#include "boost/functional/hash.hpp"
#include "fmt/ostream.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::ast {
struct GreenToken {
  SyntaxKind kind;
  std::string text;

  bool operator==(const GreenToken &) const;
};

struct GreenNode {
  SyntaxKind kind;
  size_t text_len;
  std::deque<std::shared_ptr<std::variant<GreenNode, GreenToken>>> children;

  bool operator==(const GreenNode &) const;
};

using GreenElement = std::variant<GreenNode, GreenToken>;

// For FMT Printing
std::ostream &operator<<(std::ostream &, const GreenToken &);
std::ostream &operator<<(std::ostream &, const GreenNode &);
std::ostream &operator<<(std::ostream &, const GreenElement &);
}  // namespace aero::syntax::ast

namespace std {
template <>
struct hash<aero::syntax::ast::GreenToken> {
  size_t operator()(const aero::syntax::ast::GreenToken &token) const {
    size_t res = 0;
    boost::hash_combine(res, token.text);
    boost::hash_combine(res, token.kind);
    return res;
  }
};

template <>
struct hash<aero::syntax::ast::GreenNode> {
  size_t operator()(const aero::syntax::ast::GreenNode &token) const {
    size_t res = 0;
    boost::hash_combine(res, token.text_len);
    boost::hash_combine(res, token.kind);
    boost::hash_combine(res, token.children);
    return res;
  }
};
}  // namespace std

#endif