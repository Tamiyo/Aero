#ifndef AERO_PARSER_MARKER_H
#define AERO_PARSER_MARKER_H

#include <optional>
#include <string>
#include <variant>

#include "fmt/ostream.h"
#include "syntax/parser/parser.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser {
class Marker;
class CompletedMarker;

class Bomb {
 public:
  Bomb(std::string);
  Bomb() = delete;
  Bomb(const Bomb &) = default;
  ~Bomb() = default;

  void Defuse();

  std::string Message();
  bool Armed();

 private:
  std::string message;
  bool armed;
};

class CompletedMarker {
 public:
  CompletedMarker(size_t);
  CompletedMarker() = delete;
  CompletedMarker(const CompletedMarker &) = default;
  ~CompletedMarker() = default;

  size_t Pos() const;

  Marker Precede(Parser &);

 private:
  size_t pos;
};

std::ostream &operator<<(std::ostream &, const CompletedMarker &);

class Marker {
 public:
  Marker(size_t);
  Marker() = delete;
  Marker(const Marker &) = default;
  ~Marker();

  CompletedMarker Complete(Parser &, SyntaxKind);

  size_t Pos() const;
  void SetPos(size_t);

 private:
  size_t pos;

  Bomb bomb;
};

std::ostream &operator<<(std::ostream &, const Marker &);
}  // namespace aero::syntax::parser

#endif