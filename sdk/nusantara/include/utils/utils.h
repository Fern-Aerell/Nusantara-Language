#pragma once

#include <string>
#include <vector>

namespace utils {

  std::vector<std::string> split(
      const std::string &input, const char &delimiter
  );

  std::string readFile(const std::string &path);

  template<typename T>
  inline bool contains(const std::vector<T> &vec, const T &value) {
    return std::ranges::find(vec.begin(), vec.end(), value) != vec.end();
  }

}  // namespace utils
