#include "syntax/parser/parser.h"

#include <algorithm>

#include "syntax/parser/marker.h"
#include "syntax/parser/tree/stmt.h"

namespace aero::syntax::parser {
Parser::Parser(Source s) : source(s) {}

Marker Parser::Start() {
  size_t pos = events.size();
  events.push_back(Event(EventPlaceholder{}));

  return Marker(pos);
}

void Parser::Parse() {
  Marker m = Start();

  tree::stmt::Stmt(*this);

  m.Complete(*this, SyntaxKind::Root);
}

void Parser::Expect(SyntaxKind kind) {
  if (At(kind)) {
    Bump();
  } else {
    Error();
  }
}

void Parser::Error() {
  if (!AtSet() && !AtEnd()) {
    Marker m = Start();
    Bump();
    m.Complete(*this, SyntaxKind::Error);
  }
}

bool Parser::At(SyntaxKind kind) {
  expected_kinds.push_back(context::FromSyntaxKind(kind));
  return Peek().value_or(SyntaxKind::Placeholder) == kind;
}

bool Parser::AtExact(SyntaxKind kind) {
  expected_kinds.push_back({context::Syntax{kind}});
  return Peek().value_or(SyntaxKind::Placeholder) == kind;
}

bool Parser::AtLiteral() {
  if (At(SyntaxKind::Integer) || At(SyntaxKind::Float) ||
      At(SyntaxKind::String) || At(SyntaxKind::TrueKw) ||
      At(SyntaxKind::FalseKw)) {
    return true;
  } else {
    return false;
  }
}

bool Parser::AtEnd() { return !Peek().has_value(); }

bool Parser::AtSet() {
  // return std::find(std::begin(recovery), std::end(recovery),
  //                  Peek().value_or(SyntaxKind::Placeholder));
  return true;
}

void Parser::Bump() {
  expected_kinds.clear();
  source.NextToken();
  events.push_back(Event(EventAddToken{}));
}

Event& Parser::GetEventAt(size_t pos) { return events.at(pos); }

void Parser::SetEventAt(size_t pos, Event event) {
  events.at(pos) = event;
}

void Parser::AddEvent(Event event) { events.push_back(event); }

std::vector<Event>& Parser::Events() { return events; }

std::optional<SyntaxKind> Parser::Peek() { return source.PeekKind(); }
}  // namespace aero::syntax::parser