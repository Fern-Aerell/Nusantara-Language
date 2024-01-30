#include <token.h>

Token::Token(std::string source, const TokenType &type, const int &charIndex,
             std::string value, const int &line)
    : source(std::move(source)), type(type), value(std::move(value)),
      line(line), charIndex(charIndex)
{}

const std::string &Token::getSource() { return this->source; }

TokenType Token::getType() { return this->type; }

const std::string &Token::getValue() { return this->value; }

int Token::getLine() const { return this->line; }

int Token::getCharIndex() const { return this->charIndex; }
