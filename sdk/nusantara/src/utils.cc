#include <algorithm>
#include <cstddef>
#include <format>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <sstream>
#include <stdexcept>
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
    std::string readFile(const std::string& path) {
        // Buka file untuk dibaca dalam mode binary
        std::ifstream file(path, std::ios::binary);
        // Pastikan file terbuka dengan sukses
        if(!file.is_open()) {
            throw std::runtime_error(std::format("Gagal membuka file '{}'.", path));
        }
        // Tentukan ukuran buffer berdasarkan ukuran file
        file.seekg(0, std::ios::end); // Pindahkan posisi ke akhir file
        std::streampos fileSize = file.tellg(); // Dapatkan ukuran file
        file.seekg(0, std::ios::beg);  // Kembalikan posisi ke awal file
        // Menggunakan vector untuk buffer
        std::vector<char> buffer(fileSize);
        // String untuk menyimpan isi file
        std::stringstream content;
        // Loop membaca file hingga EOF
        while (file.read(buffer.data(), static_cast<long long>(buffer.size()))) {
            // Tambahkan data dari buffer ke dalam string
            content.write(buffer.data(), file.gcount());
        }
        // Tutup file
        file.close();
        // Kembalikan string yang berisi isi file
        return content.str();
    }
}