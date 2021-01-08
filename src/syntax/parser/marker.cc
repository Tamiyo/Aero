#include "syntax/parser/marker.h"

#include <spdlog/spdlog.h>

#include <cassert>

#include "syntax/parser/event.h"
#include "syntax/parser/parser.h"

namespace aero::syntax::parser {
// Completed Marker
CompletedMarker::CompletedMarker(size_t p) : pos(p) {}

Marker CompletedMarker::Precede(Parser &p) {
  Marker new_m = Start(p);

  Event *event = &p.events[this->pos];
  if (event->Type() == EventType::StartNode) {
    EventValue *inner = event->ValueUnwrappedRef();
    inner->SetForwardParent({(new_m.Pos() - this->pos)});
  } else {
    spdlog::error("CompletedMarker::precede should be unreachable");
    exit(1);
  }

  return new_m;
}

// Marker
Marker::Marker(size_t p) : bomb("Markers need to be completed") {
  this->pos = p;
}

Marker::~Marker() {
  if (bomb.Armed()) {
    spdlog::error("[ERROR] Bomb Exploded: {}!\n", bomb.Message());
    exit(1);
  }
}

size_t Marker::Pos() { return this->pos; }

void Marker::SetPos(size_t p) { this->pos = p; }

CompletedMarker Marker::Complete(Parser &p, SyntaxKind kind) {
  bomb.Defuse();
  Event *event_at_pos = &p.events[pos];

  assert(event_at_pos->Type() == EventType::Placeholder);

  event_at_pos->SetType(EventType::StartNode);
  event_at_pos->SetValue(EventValue(kind, std::nullopt));

  p.events.push_back(Event(EventType::FinishNode, std::nullopt));

  return CompletedMarker(pos);
}

// Bomb
Bomb::Bomb(std::string m) {
  this->message = m;
  this->armed = true;
}

void Bomb::Defuse() { this->armed = false; }

std::string Bomb::Message() { return this->message; }

bool Bomb::Armed() { return this->armed; }

}  // namespace aero::syntax::parser