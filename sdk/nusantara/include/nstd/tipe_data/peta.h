#pragma once

#include <map>
#include <sstream>
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"
#include "nstd/operasi/operasi.h"

namespace nstd {

    class peta: public tipe_data {
        public:
            explicit peta(std::map<std::unique_ptr<tipe_data>, std::unique_ptr<tipe_data>> nilai): nilai(std::move(nilai)) {}
            [[nodiscard]] bool berisiKunci(const std::unique_ptr<tipe_data>& key) const {
                auto value = this->nilai.find(key);
                return static_cast<bool>(value != this->nilai.end());
            }
            [[nodiscard]] bool kosong() const {
                return this->nilai.empty();
            }
            [[nodiscard]] bool tidakKosong() const {
                return !this->kosong();
            }
            [[nodiscard]] bilangan jumlahIsi() const {
                return bilangan(static_cast<TIPE_DATA_BILANGAN_BULAT>(this->nilai.size()));
            }
            [[nodiscard]] kalimat ubahKeKalimat() const {
                std::ostringstream stream;
                int index = 0;
                for(const auto& pair : this->nilai) {
                if(index == 0) {
                    stream << "{";
                }
                stream << pair.first << ": " << pair.second;
                if(index < (this->jumlahIsi() - 1)) {
                    stream << ", ";
                } else {
                    stream << "]";
                }
                ++index;
                }
                return kalimat(stream.str());
            }
        private:
            std::map<std::unique_ptr<tipe_data>, std::unique_ptr<tipe_data>> nilai;
    };
    
}