#pragma once

#include <ostream>
#include <regex>
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define BENAR benarsalah(true)
#define SALAH benarsalah(false)

namespace nstd {
    class nilai_benarsalah_tidak_valid_exception: public std::exception {
        public:
            [[nodiscard]] const char * what() const override {
                return "nilai benar atau salah tidak valid.";
            }
    };
    class benarsalah: public tipe_data {
        public:
            explicit benarsalah(const bool& nilai): nilai(nilai) {}
            [[nodiscard]] kalimat ubahKeKalimat() const {
                return kalimat(this->nilai ? "benar" : "salah");
            }
            static benarsalah ubah(const kalimat& nilai) {
                const std::regex pattern("^(benar|salah)$");
                const std::string str = nilai.ubahKeString();
                if(std::regex_match(str, pattern)) {
                    return benarsalah(str == "benar");
                }
                throw nilai_benarsalah_tidak_valid_exception();
            }
            explicit operator bool() const {
                return this->nilai;
            }
        private:
            bool nilai;
            friend std::ostream& operator<<(std::ostream& ost, const benarsalah& obj) {
                return ost << obj.ubahKeKalimat();
            }
    };
}