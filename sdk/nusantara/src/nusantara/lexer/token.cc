#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>

#include <format>

Token::Token(std::string source, const TokenType &type, std::string value,
             const int &line, const int &charIndex)
    : source(std::move(source)),
      type(type),
      value(std::move(value)),
      line(line),
      charIndex(charIndex) {}

std::string Token::getSource() const { return this->source; }

TokenType Token::getType() const { return this->type; }

std::string Token::getValue() const { return this->value; }

int Token::getLine() const { return this->line; }

int Token::getCharIndex() const { return this->charIndex; }

std::string Token::toString() const {
  return std::format("{}:{}:{} {} {}", this->getSource(), this->getLine(),
                     this->getCharIndex(), ::toString(this->getType()),
                     this->getValue());
}
