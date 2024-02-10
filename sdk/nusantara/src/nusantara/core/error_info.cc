#include <nusantara/core/error_info.h>
#include <nusantara/utils/utils.h>
#include <format>
#include <sstream>
#include <string>

ErrorInfo::ErrorInfo(std::string source, const std::string &content)
    : source(std::move(source)), contentPerLine(utils::split(content, '\n'))
{}

std::string
ErrorInfo::inLine(const int &line, const int &charIndex,
                  const std::string &content, const std::string &msg)
{
  std::ostringstream stringStream;
  stringStream << std::format("{}:{}:{}", this->source, line + 1,
                              charIndex + 1)
                    + "\n\n";
  std::string prefix = std::format("{}| ", line + 1);
  stringStream << std::format("{}{}", prefix, this->contentPerLine[line])
                    + "\n";
  stringStream << std::string(prefix.length() + charIndex
                                + ((content.length() > 0) ? 0 : 1),
                              ' ')
                    + std::string(
                      (content.length() > 0) ? content.length() : 1, '^')
                    + "\n";
  stringStream << msg;
  return stringStream.str();
}