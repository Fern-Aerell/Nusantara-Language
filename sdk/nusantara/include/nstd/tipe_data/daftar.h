#pragma once

#include <memory>
#include <sstream>
#include <vector>
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"
#include "nstd/operasi/operasi.h"

namespace nstd {

    class daftar: public tipe_data {
        public:
            explicit daftar(std::vector<std::unique_ptr<tipe_data>> nilai): nilai(std::move(nilai)) {}
            template<typename Tipe>
            [[nodiscard]] bool berisi(const std::unique_ptr<tipe_data>& nilai) const {
                return std::find(this->nilai.begin(), this->nilai.end(), nilai) != this->nilai.end();
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
                for(const std::unique_ptr<tipe_data>& child : this->nilai) {
                if(index == 0) {
                    stream << "[";
                }
                stream << child;
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
            std::vector<std::unique_ptr<tipe_data>> nilai;
    };

}