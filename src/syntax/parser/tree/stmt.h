#ifndef AERO_PARSER_TREE_STMT_H
#define AERO_PARSER_TREE_STMT_H

#include <optional>

#include "syntax/parser/marker.h"
#include "syntax/parser/parser.h"
#include "syntax/syntax_kind.h"

namespace aero::syntax::parser::tree::stmt {
std::optional<CompletedMarker> Stmt(Parser &);
}  // namespace aero::syntax::parser::tree::stmt

#endif