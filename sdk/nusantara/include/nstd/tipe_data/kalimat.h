#pragma once

#include <string>
#include "nstd/tipe_data/tipe_data.h"

#define STD_FORMAT_ALIAS f
#define constexpr STD_FORMAT_ALIAS(nilai, argv) std::format(nilai, argv)

namespace nstd {
    class kalimat: public tipe_data {
        public:
            explicit kalimat(std::string nilai): nilai(std::move(nilai)) {}
            void replaceAll(const std::string& from, const std::string& too) {
                size_t pos = 0;
                while((pos = this->nilai.find(from, pos)) != std::string::npos) {
                    this->nilai.replace(pos, from.length(), too);
                    pos += too.length();
                }
            }
            [[nodiscard]] std::string ubahKeString() const {
                return nilai;
            }
        private:
            std::string nilai;
            friend std::ostream& operator<<(std::ostream& ost, const kalimat& obj) {
                return ost << obj.nilai;
            }
    };
}