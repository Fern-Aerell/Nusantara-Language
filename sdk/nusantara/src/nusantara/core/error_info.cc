#include <nusantara/core/error_info.h>
#include <nusantara/utils/utils.h>

#include <cstddef>
#include <format>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "nusantara/lexer/token.h"
#include "nusantara/lexer/token_type.h"
#include "nstd/konsol.h"
#include "nstd/daftar.h"

ErrorInfo::ErrorInfo(std::string source, const std::string &content):
    source(std::move(source)), contentPerLine(utils::split(content, '\n')) {}

std::string ErrorInfo::inLine(
    const Token& token, const std::string& msg
) {
  std::ostringstream stream;
  std::string realSource = token.getSource();
  TokenType realType = token.getType();
  std::string realValue = token.getValue();
  int realLine = token.getLine();
  int realStartCharIndex = token.getStartCharIndex();
  int realEndCharIndex = token.getEndCharIndex();

  int line = realLine + 1;
  int startCharIndex = realStartCharIndex + 1;
  int endCharIndex = realEndCharIndex + 1;

  std::string prefix = std::format("{}| ", line);
  stream << std::format(
      "{}[Baris {}, Karakter {} sampai {}]:\n\n", realSource, line,
      startCharIndex, endCharIndex
  );
  nstd::cetak(std::format(
      "contentPerLine size {}, realLine {}", this->contentPerLine.size(),
      realLine
  ));
  stream << std::format(
      "{}{}\n", prefix,
      this->contentPerLine
          [realLine >= this->contentPerLine.size() ? realLine - 1 : realLine]
  );
  int arrowCount = (realEndCharIndex - realStartCharIndex);
  stream << std::string(prefix.length() + realStartCharIndex, ' ');
  stream << std::string((arrowCount > 0) ? arrowCount : 1, '^') + "\n";
  stream << msg;
  return stream.str();
}

std::string ErrorInfo::inLine(
    const nstd::daftar<Token>& tokens, const std::string& msg
) {
  if(tokens.empty()) { throw std::runtime_error("Daftar tidak boleh kosong."); }
  std::ostringstream stream;
  Token token1 = tokens[0];
  if(tokens.size() > 1) {
    for(size_t index = 1; index < tokens.size(); ++index) {
      if(token1.getSource() == tokens[index].getSource() &&
         token1.getLine() == tokens[index].getLine()) {
        token1 = combineToken(token1, tokens[index]);
      } else {
        stream << this->inLine(token1, "") << "\n";
        token1 = tokens[index];
      }
    }
  }
  stream << this->inLine(token1, "") << "\n";
  stream << msg;
  return stream.str();
}
