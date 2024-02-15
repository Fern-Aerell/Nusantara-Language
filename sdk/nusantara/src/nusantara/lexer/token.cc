#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>

#include <cstddef>
#include <format>
#include <stdexcept>

Token::Token(
    std::string source, const TokenType& type, std::string value,
    const int& line, const int& startCharIndex, const int& endCharIndex
):
    source(std::move(source)),
    type(type),
    value(std::move(value)),
    line(line),
    startCharIndex(startCharIndex),
    endCharIndex(endCharIndex) {}

std::string Token::getSource() const { return this->source; }

TokenType Token::getType() const { return this->type; }

std::string Token::getValue() const { return this->value; }

int Token::getLine() const { return this->line; }

int Token::getStartCharIndex() const { return this->startCharIndex; }

int Token::getEndCharIndex() const { return this->endCharIndex; }

std::string Token::toString() const {
  return std::format(
      "{}[Baris {}, Karakter {} sampai {}]: {} {}", this->getSource(),
      this->getLine(), this->getStartCharIndex(), this->getEndCharIndex(),
      ::toString(this->getType()), this->getValue()
  );
}

Token combineToken(const Token& token1, const Token& token2) {
  if(token1.getSource() != token2.getSource()) {
    throw std::runtime_error(
        "Tidak dapat menggabungkan token dengan source yang berbeda."
    );
  }
  if(token1.getLine() != token2.getLine()) {
    throw std::runtime_error(
        "Tidak dapat menggabungkan token dengan line yang berbeda."
    );
  }
  TokenType type = TokenType::TIDAK_DIKENALI;
  std::string source = token1.getSource();
  int line = token1.getLine();
  int startCharIndex = token1.getStartCharIndex();
  int endCharIndex = token2.getEndCharIndex();
  std::string value = token1.getValue() + token2.getValue();
  return {source, type, value, line, startCharIndex, endCharIndex};
}

Token combineToken(const nstd::daftar<Token>& tokens) {
  if(tokens.size() < 2) {
    throw std::runtime_error("Daftar harus berisi token sebanyak 2 atau lebih."
    );
  }
  Token token1 = tokens[0];
  for(size_t index = 1; index < tokens.size(); ++index) {
    token1 = combineToken(token1, tokens[index]);
  }
  return token1;
}
