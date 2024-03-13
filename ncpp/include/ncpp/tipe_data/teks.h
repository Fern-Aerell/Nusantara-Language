#pragma once

#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ncpp {
  class bilangan;
  class bilangan_bulat;
  class benarsalah;

  class teks {
    public:
      // Constructors
      teks();
      explicit teks(std::string nilai);
      teks(const size_t& jumlah, const char& nilai);

      template<typename... Args>
      explicit teks(const std::string& format, Args&&... args) {
        std::ostringstream stream;
        this->teks_format(stream, format, std::forward<Args>(args)...);
        this->nilai = stream.str();
      }

      // Destructor
      virtual ~teks() = default;
      // Copy constructor
      teks(const teks& other);
      // Copy assignment operator
      teks& operator=(const teks& other);
      // Move constructor
      teks(teks&& other) noexcept;
      // Move assignment operator
      teks& operator=(teks&& other) noexcept;
      teks operator+(const teks& other) const;
      teks& operator+=(const teks& other);
      teks operator*(const bilangan& other) const;
      teks& operator*=(const bilangan& other);
      teks operator*(const bilangan_bulat& other) const;
      teks& operator*=(const bilangan_bulat& other);
      bool operator==(const teks& other) const;
      bool operator!=(const teks& other) const;
      bool operator<(const teks& other) const;
      bool operator>(const teks& other) const;
      [[nodiscard]] std::string ubah_ke_string() const;
      [[nodiscard]] const char* ubah_ke_c_string() const;
      [[nodiscard]] size_t jumlah() const;
      char& operator[](const size_t& urutan);
      [[nodiscard]] size_t cari(const std::string& ini) const;
      [[nodiscard]] size_t cari(const std::string& ini, const size_t& urutan) const;
      void ganti(const std::string& ini, const std::string& kee);
      void ganti_semua(const std::string& ini, const std::string& kee);
    private:
      std::string nilai;

      friend std::ostream& operator<<(std::ostream& ost, const teks& data) {
        ost << data.nilai;
        return ost;
      }

      void teks_format(std::ostringstream& stream, const std::string& format);

      template<typename T, typename... Args>
      void teks_format(
          std::ostringstream& stream, const std::string& format, T nilai,
          Args... args
      ) {
        size_t openBrace = format.find('{');
        if(openBrace != std::string::npos) {
          size_t closeBrace = format.find('}', openBrace);
          if(closeBrace != std::string::npos) {
            stream << format.substr(0, openBrace) << nilai;
            this->teks_format(stream, format.substr(closeBrace + 1), args...);
            return;
          }
        }
        throw std::runtime_error(teks("Tidak dapat menemukan placeholder untuk '{}' pada teks '{}'.", nilai, format).ubah_ke_string());
      }
  };
}  // namespace ncpp
