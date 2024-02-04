#pragma once

#include <string>
#include <vector>

class ErrorInfo {
    public:
        explicit ErrorInfo(std::string source, const std::string& content);
        std::string inLine(
            const int& line, 
            const int& charIndex,
            const std::string& content,
            const std::string& msg
        );
    private:
        std::string source;
        std::vector<std::string> contentPerLine;
};