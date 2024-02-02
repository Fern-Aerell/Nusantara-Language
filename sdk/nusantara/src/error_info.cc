#include <error_info.h>
#include <format>
#include <sstream>
#include <string>
#include <utils.h>

ErrorInfo::ErrorInfo(
    std::string source,
    const std::string& content
): 
source(std::move(source)),
contentPerLine(utils::split(content, '\n')) 
{}

std::string ErrorInfo::inLine(
    const int& line, 
    const int& charIndex,
    const std::string& content,
    const std::string& msg
) {
    std::ostringstream stringStream;
    stringStream << std::format("{}:{}:{}", this->source, line + 1, charIndex + 1) + "\n\n";
    std::string prefix = std::format("{}| ", line + 1);
    stringStream << std::format("{}{}", prefix, this->contentPerLine[line]) + "\n";
    stringStream << std::string(prefix.length() + charIndex, ' ') + std::string(content.length(), '^') + "\n";
    stringStream << std::string(prefix.length() + charIndex + ((content.length() / 2) - msg.length() / 2), ' ') + msg + "\n";
    return stringStream.str();
}