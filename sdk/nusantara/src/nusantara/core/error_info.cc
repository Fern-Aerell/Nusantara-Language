#include <nusantara/core/error_info.h>
#include <nusantara/utils/utils.h>

#include <cstddef>
#include <format>
#include <sstream>
#include <string>

#include "nusantara/core/core.h"
#include "nusantara/lexer/token.h"

ErrorInfo::ErrorInfo(std::string source, const std::string &content)
    : source(std::move(source)), contentPerLine(utils::split(content, '\n')) {}

std::string ErrorInfo::inLine(const int &line, const int &charIndex,
                              const std::string &content,
                              const std::string &msg) {
  std::ostringstream stringStream;
  stringStream << std::format("{}:{}:{}", this->source, line + 1,
                              charIndex + 1) +
                      "\n\n";
  std::string prefix = std::format("{}| ", line + 1);
  stringStream << std::format("{}{}", prefix, this->contentPerLine[line]) +
                      "\n";
  stringStream << std::string(prefix.length() + charIndex +
                                  ((content.length() > 0) ? 0 : 1),
                              ' ') +
                      std::string((content.length() > 0) ? content.length() : 1,
                                  '^') +
                      "\n";
  stringStream << msg;
  return stringStream.str();
}

nstd::kalimat ErrorInfo::inLine(nstd::konst<nstd::daftar<Token>> &tokens,
                                nstd::konst<nstd::kalimat> &msg) {
  std::ostringstream stream;
  //   nstd::benarsalah awal = benar;
  //   nstd::kalimat sourceReal;
  //   nstd::kalimat valueReal;
  //   size_t lineReal = 0;
  //   size_t charIndexReal = 0;
  //   size_t line = 0;
  //   size_t charIndex = 0;
  //   size_t startIndex = 0;
  //   size_t endIndex = 0;
  //   nstd::kalimat codePrefix;
  //   for (nstd::konst<Token> &token : tokens) {
  //     if (!awal && token.getLine() != lineReal) {
  //       codePrefix = std::format("{}| ", line);
  //       stream << std::format("{}:{}:{}\n\n", sourceReal, line, charIndex);
  //       stream << std::format("{}{}\n", codePrefix,
  //                             this->contentPerLine[lineReal]);
  //       stream << nstd::kalimat(codePrefix.length() + charIndexReal +
  //                                   ((valueReal.length() > 0) ? 0 : 1),
  //                               ' ');
  //       stream << nstd::kalimat((valueReal.length() > 0) ? valueReal.length()
  //       : 1,
  //                               '^')
  //              << "\n";
  //     }
  //     lineReal = token.getLine();
  //     sourceReal = token.getSource();
  //     valueReal = token.getValue();
  //     charIndexReal = token.getCharIndex();
  //     line = lineReal + 1;
  //     charIndex = charIndexReal + 1;
  //     awal = salah;
  //   }
  stream << msg << "\n";
  return stream.str();
}