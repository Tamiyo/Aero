#include "cli/cli.h"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <deque>
#include <iostream>
#include <vector>

#include "syntax/ast/element.h"
#include "syntax/ast/format.h"
#include "syntax/lexer/lexer.h"
#include "syntax/parser/parser.h"
#include "syntax/parser/sink.h"

namespace aero::cli {
void Cli() {
  for (;;) {
    // Read in user-input
    std::string input;
    fmt::print("aero-cli>> ");
    std::getline(std::cin, input);

    int i = system("clear");  // unsafe -- testing only
    if (i == -1) {
      spdlog::error("system clear operation failed");
    }

    fmt::print("::QUERY::\n{}\n", input);

    // Tokenize user input
    aero::syntax::lexer::Lexer lexer = aero::syntax::lexer::Lexer(input);
    std::vector<aero::syntax::lexer::Token> tokens = lexer.Tokenize();

    fmt::print("\n::Lexer Results::\n");
    for (auto token : tokens) {
      fmt::print("{}\n", token.Pretty());
    }

    // Parse user input
    aero::syntax::parser::Source source(tokens);

    aero::syntax::parser::Parser parser(source);
    parser.Parse();

    aero::syntax::parser::Sink sink(tokens, parser.Events());
    aero::syntax::ast::GreenNode node = sink.Finish();

    fmt::print("\n::AST Results::\n");
    fmt::print("{}", aero::syntax::ast::PrettyGreenNode(node, 0));
  }
}
}  // namespace aero::cli
