#include "syntax/parser/marker.h"

#include <spdlog/spdlog.h>

#include <cassert>

#include "syntax/parser/event.h"
#include "syntax/parser/parser.h"

namespace aero::syntax::parser {
// Completed Marker
CompletedMarker::CompletedMarker(size_t p) : pos(p) {}

Marker CompletedMarker::Precede(Parser& p) {
  Marker new_m = p.Start();

  Event& event_at_pos = p.GetEventAt(pos);

  if (std::holds_alternative<EventStartNode>(event_at_pos.type)) {
    EventStartNode start = std::get<EventStartNode>(event_at_pos.type);
    start.forward_parent = {new_m.Pos() - pos};
    event_at_pos.type = start;
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

CompletedMarker Marker::Complete(Parser& p, SyntaxKind kind) {
  bomb.Defuse();

  Event& event_at_pos = p.GetEventAt(pos);

  assert(std::holds_alternative<EventPlaceholder>(event_at_pos.type));
  event_at_pos.type = {EventStartNode{kind, {}}};
  p.AddEvent(Event(EventFinishNode{}));

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