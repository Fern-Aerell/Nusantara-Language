#pragma once

#include <cstddef>
#include <regex>
#include <stdexcept>
#include <string>

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
    std::regex pattern("^-?[0-9]+$");
    return std::regex_match(str, pattern);
  }

  inline bool isFloat(const std::string& str) {
    std::regex pattern("^-?[0-9]+,[0-9]{1,7}$");
    return std::regex_match(str, pattern);
  }

  inline bool isDouble(const std::string& str) {
    std::regex pattern("^-?[0-9]+,[0-9]{1,16}$");
    return std::regex_match(str, pattern);
  }

  inline bool isChar(const std::string& str) {
    std::regex pattern("^.$");
    return std::regex_match(str, pattern);
  }

  inline bool isBool(const std::string& str) {
    std::regex pattern("^(benar|salah)$");
    return std::regex_match(str, pattern);
  }

  inline int toInt(const std::string& str) {
    if(isInt(str)) { return std::stoi(str); }
    throw std::runtime_error("String bukan berformat int.");
  }

  inline float toFloat(const std::string& str) {
    if(isFloat(str)) {
      std::string nilai = str;
      nilai.replace(nilai.find(','), 1, ".");
      return std::stof(nilai);
    }
    throw std::runtime_error("String bukan berformat float.");
  }

  inline double toDouble(const std::string& str) {
    if(isDouble(str)) {
      std::string nilai = str;
      nilai.replace(nilai.find(','), 1, ".");
      return std::stod(nilai);
    }
    throw std::runtime_error("String bukan berformat double.");
  }

  inline char toChar(const std::string& str) {
    if(isChar(str)) { return str[0]; }
    throw std::runtime_error("String bukan berformat char.");
  }

  inline bool toBool(const std::string& str) {
    if(isBool(str)) {
      if(str == "benar") {
        return true;
      } else if(str == "salah") {
        return false;
      }
    }
    throw std::runtime_error("String bukan berformat bool.");
  }

}  // namespace nstd
