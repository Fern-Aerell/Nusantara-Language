#pragma once

#include <string>

#include <token_type.h>

class Token
{
public:
  Token(
    std::string source, 
    const TokenType &type, 
    std::string value, 
    const int &line,
    const int &charIndex
        );
  [[nodiscard]] std::string getSource() const;
  [[nodiscard]] TokenType getType() const;
  [[nodiscard]] std::string getValue() const;
  [[nodiscard]] int getLine() const;
  [[nodiscard]] int getCharIndex() const;
private:
  std::string source;
  TokenType type;
  std::string value;
  int line;
  int charIndex;
};
