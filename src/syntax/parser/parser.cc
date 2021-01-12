#include "syntax/parser/parser.h"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <utility>

#include "magic_enum.hpp"
#include "syntax/parser/error.h"
#include "syntax/parser/marker.h"
#include "syntax/parser/tree/stmt.h"

namespace aero::syntax::parser {
Parser::Parser(Source s) : source(s) {}

Marker Parser::Start() {
  size_t pos = events.size();
  events.push_back(Event(event::Placeholder{}));

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

  // Looking at alternative implementations for this
  std::optional<lexer::Token> current_token = source.PeekToken();
  std::optional<SyntaxKind> found = {};
  std::pair<size_t, size_t> range;
  if (auto current_token = source.PeekToken()) {
    found = {(*current_token).Kind()};
    range = (*current_token).Range();
  } else {
    range = *source.LastTokenRange();
  }

  events.emplace_back(event::Error{ParseError{expected_kinds, found, range}});

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
  return std::find(std::begin(RECOVERY_SET), std::end(RECOVERY_SET),
                   Peek().value_or(SyntaxKind::Placeholder));
}

void Parser::Bump() {
  expected_kinds.clear();
  source.NextToken();
  events.push_back(Event(event::AddToken{}));
}

Event& Parser::GetEventAt(size_t pos) { return events.at(pos); }

void Parser::SetEventAt(size_t pos, Event event) { events.at(pos) = event; }

void Parser::AddEvent(Event event) { events.push_back(event); }

std::vector<Event>& Parser::Events() { return events; }

std::optional<SyntaxKind> Parser::Peek() { return source.PeekKind(); }
}  // namespace aero::syntax::parser