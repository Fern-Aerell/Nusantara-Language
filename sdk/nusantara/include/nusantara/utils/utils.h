#pragma once

#include <string>
#include <vector>

namespace utils {

  std::vector<std::string> split(
      const std::string &input, const char &delimiter
  );

  std::string readFile(const std::string &path);
  
}  // namespace utils
