#include "utils/utils.h"

#include <format>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace utils {
  std::vector<std::string> split(
      const std::string &input, const char &delimiter
  ) {
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string str;
    while(std::getline(stream, str, delimiter)) { result.push_back(str); }
    return result;
  }

  std::string readFile(const std::string &path) {
    // Buka file untuk dibaca dalam mode binary
    std::ifstream file(path, std::ios::binary);

    // Pastikan file terbuka dengan sukses
    if(!file.is_open()) {
      throw std::runtime_error("Gagal membuka file '" + path + "'.");
    }

    // Dapatkan ukuran file
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Jika file size 0 atau lebih kecil dari 0, maka return string kosong
    if(fileSize <= 0) { return ""; }

    // Alokasikan buffer string
    std::string buffer;
		buffer.reserve(fileSize);

    // Baca file dan masukkan ke dalam buffer string
    std::streamsize bytesRead = file.readsome(
        buffer.data(), static_cast<std::streamsize>(buffer.size())
    );

    // Jika terjadi error saat membaca file
    if(bytesRead < 0) {
      throw std::runtime_error("Gagal membaca file '" + path + "'.");
    }

    // Kembalikan string yang berisi isi file
    return buffer.substr(0, bytesRead);
  }

}  // namespace utils
