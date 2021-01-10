#include "syntax_kind.h"

#include <magic_enum.hpp>

namespace aero::syntax {
bool IsTrivia(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::Whitespace:
    case SyntaxKind::Newline:
    case SyntaxKind::Comment:
      return true;
    default:
      return false;
  }
}

bool IsType(SyntaxKind kind) {
  switch (kind) {
    case SyntaxKind::I32Ty:
    case SyntaxKind::I64Ty:
    case SyntaxKind::F32Ty:
    case SyntaxKind::F64Ty:
    case SyntaxKind::StrTy:
    case SyntaxKind::BoolTy:
    case SyntaxKind::Identifier:
      return true;
    default:
      return false;
  }
}
}  // namespace aero::syntax
