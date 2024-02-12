#pragma once

#include <string>
#include <vector>

#include "nusantara/core/core.h"
#include "nusantara/lexer/token.h"

class ErrorInfo {
  public:
    explicit ErrorInfo(std::string source, const std::string &content);

    nstd::kalimat inLine(
        nstd::konst<Token> &token, nstd::konst<nstd::kalimat> &msg
    );

    nstd::kalimat inLine(
        nstd::konst<nstd::daftar<Token>> &tokens,
        nstd::konst<nstd::kalimat> &msg
    );

  private:
    std::string source;
    std::vector<std::string> contentPerLine;
};
