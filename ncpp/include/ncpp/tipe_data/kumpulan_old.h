#pragma once

#include <unordered_set>
#include "ncpp/batas_jumlah.h"
#include "ncpp/struktur_data.h"

#define NAMA_STRUKTUR_DATA_KUMPULAN "kumpulan"

namespace ncpp {
    template<typename Tipe>
    class kumpulan: public struktur_data<std::unordered_set<Tipe>> {
        public:
            // Constructors
            kumpulan()
            : 
                struktur_data<std::unordered_set<Tipe>>(
                    NAMA_STRUKTUR_DATA_KUMPULAN
                ) 
            {}

            explicit kumpulan(
                const std::unordered_set<Tipe>& nilai
            )
            : 
                struktur_data<std::unordered_set<Tipe>>(
                    NAMA_STRUKTUR_DATA_KUMPULAN,
                    nilai
                ) 
            {}

            kumpulan(
                const batas_jumlah_maksimal& jumlah_maksimal, 
                const std::unordered_set<Tipe>& nilai
            )
            : 
                struktur_data<std::unordered_set<Tipe>>(
                    NAMA_STRUKTUR_DATA_KUMPULAN,
                    jumlah_maksimal,
                    nilai
                ) 
            {}

            kumpulan(
                const batas_jumlah_minimal& jumlah_minimal, 
                const std::unordered_set<Tipe>& nilai
            )
            : 
                struktur_data<std::unordered_set<Tipe>>(
                    NAMA_STRUKTUR_DATA_KUMPULAN,
                    jumlah_minimal,
                    nilai
                )
            {}

            kumpulan(
                const batas_jumlah& batas_jumlah,
                const std::unordered_set<Tipe>& nilai
            )
            :
                struktur_data<std::unordered_set<Tipe>>(
                    NAMA_STRUKTUR_DATA_KUMPULAN,
                    batas_jumlah,
                    nilai
                )
            {}

            // Destructor
            ~kumpulan() = default;

            // Copy constructor
            kumpulan(const kumpulan& other) = default;

            // Copy assignment operator
            kumpulan& operator=(const kumpulan& other) = default;

            // Move constructor
            kumpulan(kumpulan&& other) noexcept = default;

            // Move assignment operator
            kumpulan& operator=(kumpulan&& other) noexcept = default;
            
            [[nodiscard]] teks ubah_ke_teks() const override {
                std::ostringstream stream;
                int index = 0;
                for(const auto& child : this->nilai) {
                    if(index == 0) { stream << "["; }
                        stream << child;
                    if(index < static_cast<int>(this->jumlah() - 1)) {
                        stream << ", ";
                    } else {
                        stream << "]";
                    }
                    ++index;
                }
                if(index == 0) {
                    stream << "[]";
                }
                return teks(stream.str());
            }

            bool berisi(const Tipe& nilai) const {
                return this->nilai.find(nilai) != this->end();
            }

            void tambah(const Tipe& nilai) {
                if(this->berisi(nilai)) {
                    throw std::runtime_error(teks("Data '{}' sudah ada di kumpulan.", nilai).ubah_ke_string());
                }
                this->nilai.insert(nilai);
            }

            void hapus(const Tipe& nilai) {
                if(this->berisi(nilai)) {
                    this->nilai.erase(nilai);
                }else{
                    throw std::runtime_error(teks("Data '{}' tidak ada di kumpulan.", nilai).ubah_ke_string());
                }
            }
        private:
        protected:
    };
}