#pragma once

#include <vcruntime_typeinfo.h>

#include <cstddef>
#include <regex>
#include <stdexcept>
#include <string>

#include "nstd/konsol.h"

namespace nstd {

  inline void replaceAll(
      std::string& str, const std::string& from, const std::string& to
  ) {
    size_t pos = 0;
    while((pos = str.find(from, pos)) != std::string::npos) {
      str.replace(pos, from.length(), to);
      pos += to.length();
    }
  }

  inline bool isInt(const std::string& str) {
    std::regex pattern("^[0-9]+$");
    return std::regex_match(str, pattern);
  }

  inline bool isDouble(const std::string& str) {
    std::regex pattern("^[0-9]+,[0-9]+$");
    return std::regex_match(str, pattern);
  }

  inline bool isChar(const std::string& str) {
    std::regex pattern("^.$");
    return std::regex_match(str, pattern);
  }

  inline int asInt(const std::string& str) {
    if(isInt(str)) { return std::stoi(str); }
    throw std::runtime_error("String bukan berformat int.");
  }

  inline double asDouble(const std::string& str) {
    if(isDouble(str)) {
      std::string nilai = str;
      nilai.replace(nilai.find(','), 1, ".");
      return std::stod(nilai);
    }
    throw std::runtime_error("String bukan berformat double.");
  }

  inline char asChar(const std::string& str) {
    if(isChar(str)) { return str[0]; }
    throw std::runtime_error("String bukan berformat char.");
  }

  inline std::string formatString(const std::string& str) {
    std::string valueStr = str;
    valueStr.pop_back();
    valueStr = valueStr.substr(1);
    for(size_t i = 0; i < valueStr.length(); ++i) {
      if(valueStr[i] == '\\') {
        if(valueStr[i + 1] == 'n') {
          if(valueStr[i - 1] != '\\') {
            valueStr[i] = '\n';
            valueStr.erase(i + 1, 1);
          } else {
            valueStr.replace(i, 1, "");
          }
        }
      }
    }
    return valueStr;
  }

}  // namespace nstd
