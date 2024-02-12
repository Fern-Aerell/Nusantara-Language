#pragma once

#include <nusantara/lexer/token_type.h>

#include <string>

#include "nusantara/core/core.h"

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

Token combineToken(nstd::konst<Token>& token1, nstd::konst<Token>& token2);

Token combineToken(nstd::konst<nstd::daftar<Token>>& tokens);
