#include "syntax_kind.h"

#include <magic_enum.hpp>

namespace aero::syntax {
bool is_trivia(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::Whitespace:
    case SyntaxKind::Newline:
    case SyntaxKind::Comment:
      return true;
    default:
      return false;
  }
}
}  // namespace aero::syntax