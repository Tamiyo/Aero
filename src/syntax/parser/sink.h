#ifndef AERO_PARSER_SINK_H
#define AERO_PARSER_SINK_H

#include <deque>
#include <vector>

#include "syntax/ast/builder.h"
#include "syntax/ast/element.h"
#include "syntax/lexer/token.h"
#include "syntax/parser/event.h"

namespace aero::syntax::parser {
class Sink {
 public:
  Sink(std::vector<lexer::Token>, std::deque<Event>);
  Sink() = delete;
  Sink(const Sink &) = default;
  ~Sink() = default;

  ast::GreenNode Finish();  // This should actually be a GreenNode

 private:
  void EatTrivia();
  void Token();

  std::vector<lexer::Token> tokens;
  size_t cursor;
  std::deque<Event> events;
  ast::GreenNodeBuilder builder;
};
}  // namespace aero::syntax::parser

#endif