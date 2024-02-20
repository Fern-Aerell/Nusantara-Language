#pragma once

#include <string>

#include "lexer/token_type.h"

class TokenTypeData {
  public:
    TokenTypeData(std::string name, const TokenType &type, std::string pattern);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getPattern() const;

  private:
    std::string name;
    TokenType type;
    std::string pattern;
};
