#include "syntax/lexer/lexer.hpp"

namespace aero::syntax::lexer {
Lexer::Lexer(std::string s) : input(s) {}

Token Lexer::MakeToken(std::string::iterator *it, SyntaxKind kind,
                       std::string text) {
  size_t text_length = text.size();
  std::advance(*it, text_length);
  return Token(kind, text);
}

char Lexer::Bump(std::string::iterator *itx) {
  char c = **itx;
  std::advance(*itx, 1);
  return c;
}

std::optional<char> Lexer::Nth(std::string::iterator *it, int n) {
  if (*it + n != input.end()) {
    return std::optional<char>{*(*it + n)};
  } else {
    return std::nullopt;
  }
}

Token Lexer::ConsumeString(std::string::iterator *it) {
  std::string result = "";
  std::string::iterator it_runner = *it;

  result.push_back(Bump(&it_runner));  // Consume first "
  while (it_runner != input.end() && *it_runner != '"') {
    result.push_back(Bump(&it_runner));
  }

  result.push_back(Bump(&it_runner));  // Consume last "

  return MakeToken(it, SyntaxKind::String, result);
}

Token Lexer::ConsumeNumeric(std::string::iterator *it) {
  std::string result = "";
  std::string::iterator it_runner = *it;
  while (it_runner != input.end() && isdigit(*it_runner)) {
    result.push_back(Bump(&it_runner));
  }

  if (*it_runner == '.') {
    result.push_back(Bump(&it_runner));
    while (it_runner != input.end() && isdigit(*it_runner)) {
      result.push_back(Bump(&it_runner));
    }
    return MakeToken(it, SyntaxKind::Float, result);
  } else {
    return MakeToken(it, SyntaxKind::Integer, result);
  }
}

Token Lexer::ConsumeIdentifier(std::string::iterator *it) {
  std::string result = "";
  std::string::iterator it_runner = *it;

  while (it_runner != input.end() && isalnum(*it_runner)) {
    result.push_back(Bump(&it_runner));
  }

  // Keywords
  if (result == "and") {
    return MakeToken(it, SyntaxKind::AndKw, result);
  } else if (result == "or") {
    return MakeToken(it, SyntaxKind::OrKw, result);
  } else if (result == "if") {
    return MakeToken(it, SyntaxKind::IfKw, result);
  } else if (result == "elif") {
    return MakeToken(it, SyntaxKind::ElifKw, result);
  } else if (result == "else") {
    return MakeToken(it, SyntaxKind::ElseKw, result);
  } else if (result == "break") {
    return MakeToken(it, SyntaxKind::BreakKw, result);
  } else if (result == "while") {
    return MakeToken(it, SyntaxKind::WhileKw, result);
  } else if (result == "loop") {
    return MakeToken(it, SyntaxKind::LoopKw, result);
  } else if (result == "for") {
    return MakeToken(it, SyntaxKind::ForKw, result);
  } else if (result == "in") {
    return MakeToken(it, SyntaxKind::InKw, result);
  } else if (result == "component") {
    return MakeToken(it, SyntaxKind::ComponentKw, result);
  } else if (result == "enum") {
    return MakeToken(it, SyntaxKind::EnumKw, result);
  } else if (result == "struct") {
    return MakeToken(it, SyntaxKind::StructKw, result);
  } else if (result == "impl") {
    return MakeToken(it, SyntaxKind::ImplKw, result);
  } else if (result == "my") {
    return MakeToken(it, SyntaxKind::MyKw, result);
  } else if (result == "true") {
    return MakeToken(it, SyntaxKind::TrueKw, result);
  } else if (result == "false") {
    return MakeToken(it, SyntaxKind::FalseKw, result);
  }

  // Builtin Types
  else if (result == "i32") {
    return MakeToken(it, SyntaxKind::I32Ty, result);
  } else if (result == "i64") {
    return MakeToken(it, SyntaxKind::I64Ty, result);
  } else if (result == "f32") {
    return MakeToken(it, SyntaxKind::F32Ty, result);
  } else if (result == "f64") {
    return MakeToken(it, SyntaxKind::F64Ty, result);
  } else if (result == "str") {
    return MakeToken(it, SyntaxKind::StrTy, result);
  } else if (result == "bool") {
    return MakeToken(it, SyntaxKind::BoolTy, result);
  } else {
    return MakeToken(it, SyntaxKind::Identifier, result);
  }
}

Token Lexer::ConsumeToken(std::string::iterator *it) {
  switch (**it) {
    case '(':
      return MakeToken(it, SyntaxKind::LeftParen, std::string("("));
    case ')':
      return MakeToken(it, SyntaxKind::RightParen, std::string(")"));
    case '{':
      return MakeToken(it, SyntaxKind::LeftCurly, std::string("{"));
    case '}':
      return MakeToken(it, SyntaxKind::RightCurly, std::string("}"));
    case '[':
      return MakeToken(it, SyntaxKind::LeftSquare, std::string("["));
    case ']':
      return MakeToken(it, SyntaxKind::RightSquare, std::string("]"));
    case ';':
      return MakeToken(it, SyntaxKind::Semicolon, std::string(";"));
    case ':':
      return MakeToken(it, SyntaxKind::Colon, std::string(":"));
    case '_':
      return MakeToken(it, SyntaxKind::Underscore, std::string("_"));
    case ' ':
      return MakeToken(it, SyntaxKind::Whitespace, std::string(" "));
    case '&':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::AmpEqual, std::string("&="));
      } else {
        return MakeToken(it, SyntaxKind::Amp, std::string("&"));
      }
    case '|':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::PipeEqual, std::string("|="));
      } else {
        return MakeToken(it, SyntaxKind::Pipe, std::string("|"));
      }
    case '+':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::PlusEqual, std::string("+="));
      } else {
        return MakeToken(it, SyntaxKind::Plus, std::string("+"));
      }
    case '-':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::MinusEqual, std::string("-="));
      } else {
        return MakeToken(it, SyntaxKind::Minus, std::string("-"));
      }
    case '*':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::StarEqual, std::string("*="));
      } else {
        return MakeToken(it, SyntaxKind::Star, std::string("*"));
      }
    case '/':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::SlashEqual, std::string("/="));
      } else {
        return MakeToken(it, SyntaxKind::Slash, std::string("/"));
      }
    case '%':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::ModEqual, std::string("%="));
      } else {
        return MakeToken(it, SyntaxKind::Mod, std::string("%"));
      }
    case '^':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::CaretEqual, std::string("^="));
      } else {
        return MakeToken(it, SyntaxKind::Caret, std::string("^"));
      }
    case '<':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::LessThanEqual, std::string("<="));
      } else if (Nth(it, 1).value_or(' ') == '<') {
        if (Nth(it, 2).value_or(' ') == '=') {
          return MakeToken(it, SyntaxKind::ShiftRightEqual, std::string("<<="));
        } else {
          return MakeToken(it, SyntaxKind::ShiftRight, std::string("<<"));
        }
      } else {
        return MakeToken(it, SyntaxKind::LessThan, std::string("<"));
      }
    case '>':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::GreaterThanEqual, std::string(">="));
      } else if (Nth(it, 1).value_or(' ') == '>') {
        if (Nth(it, 2).value_or(' ') == '=') {
          return MakeToken(it, SyntaxKind::ShiftLeftEqual, std::string(">>="));
        } else {
          return MakeToken(it, SyntaxKind::ShiftLeft, std::string(">>"));
        }
      } else {
        return MakeToken(it, SyntaxKind::GreaterThan, std::string(">"));
      }
    case '!':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::BangEqual, std::string("!="));
      } else {
        return MakeToken(it, SyntaxKind::Bang, std::string("!"));
      }
    case '=':
      if (Nth(it, 1).value_or(' ') == '=') {
        return MakeToken(it, SyntaxKind::EqualEqual, std::string("=="));
      } else {
        return MakeToken(it, SyntaxKind::Equal, std::string("="));
      }
    case '.':
      if (Nth(it, 1).value_or(' ') == '.') {
        return MakeToken(it, SyntaxKind::DotDot, std::string(".."));
      } else {
        return MakeToken(it, SyntaxKind::Dot, std::string("."));
      }
    case '\n':
      return MakeToken(it, SyntaxKind::Newline, std::string("\n"));
    case '\r':
      return MakeToken(it, SyntaxKind::Newline, std::string("\r\n"));
    case '"':
      return ConsumeString(it);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return ConsumeNumeric(it);
    default:
      return ConsumeIdentifier(it);
  };
}

std::vector<Token> Lexer::Tokenize() {
  std::vector<Token> tokens;
  std::string::iterator it = input.begin();

  while (it != input.end()) {
    Token Token = ConsumeToken(&it);
    tokens.push_back(Token);
  }

  return tokens;
}
}  // namespace aero::syntax::lexer