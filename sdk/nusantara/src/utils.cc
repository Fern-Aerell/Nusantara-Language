#include <sstream>
#include <string>
#include <utils.h>
#include <vector>

namespace utils {
    std::vector<std::string> split(const std::string& input, const char& delimiter) {
        std::vector<std::string> result;
        std::istringstream stream(input);
        std::string str;
        while (std::getline(stream, str, delimiter)) {
            result.push_back(str);
        }
        return result;
    }
}