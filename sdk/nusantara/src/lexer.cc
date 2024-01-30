#include "lexer.h"
#include "token_type.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>

std::string Lexer::toString(const TokenType& type) {
  auto result = std::find_if(
    this->tokenTypes.begin(), 
    this->tokenTypes.end(),
    [type](const TokenTypeData& data) {
      return data.getType() == type;
    }
  );
  if(result != Lexer::tokenTypes.end()) {
    return result->getName();
  }
  throw std::runtime_error("Tipe token tidak dapat diubah ke string.");
}

std::string Lexer::toString(const Token& token) {
  return std::format("{}:{}:{} {} {}", token.getSource(), token.getLine(), token.getCharIndex(), this->toString(token.getType()), token.getValue());
}

std::string Lexer::toString(const std::vector<Token>& tokens) {
  std::string result;
  for(const Token& token : tokens) {
    result += this->toString(token) + "\n";
  }
  return result;
}

bool Lexer::match(std::string& content, const std::string& pattern, std::string& match, int& line, int& realCharIndex, int& charIndex) {
  std::regex regexPattern("^" + pattern);
  std::smatch matches;
  if(std::regex_search(content, matches, regexPattern, std::regex_constants::match_continuous)) {
    match = matches.str();
    charIndex = realCharIndex;
    for(const char& character : match) {
      realCharIndex++;
      if(character == '\n') {
        line++;
        charIndex = 0;
      }
    }
    content.replace(0, match.length(), "");
    return true;
  }else{
    return false;
  }
}

void Lexer::createToken(std::vector<Token>& tokens, const std::string& source, const TokenType& type, std::string& match, int& line, int& charIndex) {
  tokens.emplace_back(
    source,
    type,
    match,
    line,
    charIndex
  );
  match.clear();
}

std::vector<Token> Lexer::inputFromFile(const std::string& filepath) {
  std::ifstream inputFile(filepath, std::ios::binary);
  if(!inputFile.is_open()) {
    throw std::runtime_error("Tidak dapat membuka file '" + filepath + "'.");
  }
  std::ostringstream oss;
  oss << inputFile.rdbuf();
  std::string resultString = oss.str();
  return Lexer::inputFromString(filepath, resultString);
}

std::vector<Token> Lexer::inputFromString(const std::string& source, std::string& content) {
  std::vector<Token> tokens;
  int line = 0;
  int charIndex = 0;
  int realCharIndex = 0;
  std::string match;
  while (!content.empty()) {
    for(const TokenTypeData& tokenType : Lexer::tokenTypes) {
      if(Lexer::match(content, tokenType.getPattern(), match, line, realCharIndex, charIndex)) {
        TokenType type = tokenType.getType();
        if(
          type == TokenType::AKHIR_DARI_FILE ||
          type == TokenType::WHITESPACE ||
          type == TokenType::KOMENTAR_SATU_BARIS ||
          type == TokenType::KOMENTAR_BANYAK_BARIS
        ) {continue;}
        Lexer::createToken(
          tokens, 
          source, 
          type, 
          match, 
          line, 
          charIndex
        );
        break;
      }
      throw std::runtime_error("Karakter tidak di kenal.");
    }
  }
  Lexer::createToken(
    tokens, 
    source, 
    TokenType::AKHIR_DARI_FILE, 
    match, 
    line, 
    charIndex
  );
  return tokens;
}
