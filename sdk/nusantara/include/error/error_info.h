#pragma once

#include <string>
#include <vector>

#include "lexer/token.h"


class ErrorInfo {
  public:
    explicit ErrorInfo(std::string source, const std::string& content);

    std::string inLine(const Token& token, const std::string& msg);

    std::string inLine(
        const std::vector<Token>& tokens, const std::string& msg
    );

  private:
    std::string source;
    std::vector<std::string> contentPerLine;
};
