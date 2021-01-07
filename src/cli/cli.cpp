#include "cli/cli.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <deque>
#include <iostream>
#include <vector>

#include "syntax/ast/element.hpp"
#include "syntax/ast/format.hpp"
#include "syntax/lexer/lexer.hpp"
#include "syntax/parser/parser.hpp"
#include "syntax/parser/sink.hpp"

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
    for (auto Token : tokens) {
      fmt::print("{}\n", Token.Pretty());
    }

    // Parse user input
    aero::syntax::parser::Source source(tokens);

    aero::syntax::parser::Parser parser{source, {}};
    aero::syntax::parser::Parse(parser);

    aero::syntax::parser::Sink sink(tokens, parser.events);
    aero::syntax::ast::GreenNode node = sink.Finish();

    fmt::print("\n::AST Results::\n");
    fmt::print("{}", aero::syntax::ast::PrettyGreenNode(node, 0));
  }
}
}  // namespace aero::cli
