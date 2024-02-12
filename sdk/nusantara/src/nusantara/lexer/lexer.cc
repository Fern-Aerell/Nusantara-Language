#include <nusantara/lexer/lexer.h>
#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/lexer/token_type_data.h>

#include <regex>

Lexer::Lexer(std::string source, std::string content):
    source(std::move(source)), content(std::move(content)) {}

bool Lexer::match(const std::string &pattern, std::string &match) {
  std::regex regexPattern("^" + pattern);
  std::smatch matches;
  if(std::regex_search(
         this->content, matches, regexPattern,
         std::regex_constants::match_continuous
     )) {
    match = matches.str();
    this->charIndex = this->realCharIndex;
    for(const char &character : match) {
      this->realCharIndex++;
      if(character == '\n') {
        this->line++;
        this->realCharIndex = 0;
      }
    }
    this->content.replace(0, match.length(), "");
    return true;
  } else {
    return false;
  }
}

Token Lexer::getNextToken() {
  std::string match;
  if(this->content.empty()) {
    return this->createToken(TokenType::AKHIR_DARI_FILE, match);
  }
  for(const TokenTypeData &tokenType : this->tokenTypes) {
    TokenType type = tokenType.getType();
    if(this->match(tokenType.getPattern(), match)) {
      if(type == TokenType::WHITESPACE ||
         type == TokenType::KOMENTAR_SATU_BARIS ||
         type == TokenType::KOMENTAR_BANYAK_BARIS) {
        return getNextToken();
      }
      return this->createToken(tokenType.getType(), match);
    }
  }
  match = content[0];
  this->match(match, match);
  return this->createToken(TokenType::TIDAK_DIKENALI, match);
}

Token Lexer::createToken(const TokenType &type, const std::string &value) {
  return {
      this->source,    type,
      value,           this->line,
      this->charIndex, static_cast<int>(this->charIndex + value.length() - 1)
  };
}
