#pragma once

#include <string>
#include <vector>
#include "lexer/token_type.h"

class Token {
  public:
    Token(
        std::string source, const TokenType& type, std::string value,
        const int& line, const int& startCharIndex, const int& endCharIndex
    );
    [[nodiscard]] std::string getSource() const;
    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getValue() const;
    [[nodiscard]] int getLine() const;
    [[nodiscard]] int getStartCharIndex() const;
    [[nodiscard]] int getEndCharIndex() const;
    [[nodiscard]] std::string toString() const;

  private:
    std::string source;
    TokenType type;
    std::string value;
    int line;
    int startCharIndex;
    int endCharIndex;
};

Token combineToken(const Token& token1, const Token& token2);

Token combineToken(const std::vector<Token>& tokens);
