#pragma once

#include <string>

#include <token_type.h>

class TokenTypeData
{
public:
  TokenTypeData(std::string name, const TokenType &type, std::string pattern);
  const std::string &getName();
  const TokenType &getType();
  const std::string &getPattern();

private:
  std::string name;
  TokenType type;
  std::string pattern;
};
