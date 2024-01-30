#pragma once

#include <string>

#include <token_type.h>

class Token
{
public:
  Token(std::string source, const TokenType &type, const int &charIndex,
        std::string value, const int &line);
  const std::string &getSource();
  TokenType getType();
  const std::string &getValue();
  [[nodiscard]] int getLine() const;
  [[nodiscard]] int getCharIndex() const;

private:
  std::string source;
  TokenType type;
  std::string value;
  int line;
  int charIndex;
};
