#pragma once

#include <map>
#include "ncpp/struktur_data.h"
#include "ncpp/tipe_data/teks.h"

#define NAMA_STRUKTUR_DATA_PETA "peta"

namespace ncpp {
    template<typename Kata_Kunci, typename Nilai>
    class peta: public struktur_data<std::map<Kata_Kunci, Nilai>> {
        public:
            // Constructors
            peta()
            : 
                struktur_data<std::map<Kata_Kunci, Nilai>>(
                    NAMA_STRUKTUR_DATA_PETA
                ) 
            {}

            explicit peta(
                const std::map<Kata_Kunci, Nilai>& nilai
            )
            : 
                struktur_data<std::map<Kata_Kunci, Nilai>>(
                    NAMA_STRUKTUR_DATA_PETA,
                    nilai
                ) 
            {}

            peta(
                const batas_jumlah_maksimal& jumlah_maksimal, 
                const std::map<Kata_Kunci, Nilai>& nilai
            )
            : 
                struktur_data<std::map<Kata_Kunci, Nilai>>(
                    NAMA_STRUKTUR_DATA_PETA,
                    jumlah_maksimal,
                    nilai
                ) 
            {}

            peta(
                const batas_jumlah_minimal& jumlah_minimal, 
                const std::map<Kata_Kunci, Nilai>& nilai
            )
            : 
                struktur_data<std::map<Kata_Kunci, Nilai>>(
                    NAMA_STRUKTUR_DATA_PETA,
                    jumlah_minimal,
                    nilai
                )
            {}

            peta(
                const batas_jumlah& batas_jumlah,
                const std::map<Kata_Kunci, Nilai>& nilai
            )
            :
                struktur_data<std::map<Kata_Kunci, Nilai>>(
                    NAMA_STRUKTUR_DATA_PETA,
                    batas_jumlah,
                    nilai
                )
            {}

            // Destructor
            ~peta() = default;

            // Copy constructor
            peta(const peta& other) = default;

            // Copy assignment operator
            peta& operator=(const peta& other) = default;

            // Move constructor
            peta(peta&& other) noexcept = default;

            // Move assignment operator
            peta& operator=(peta&& other) noexcept = default;

            [[nodiscard]] teks ubah_ke_teks() const override {
                std::ostringstream stream;
                int index = 0;
                for(const auto& child : this->nilai) {
                    if(index == 0) { stream << "{"; }
                        stream << child.first << ": " << child.second;
                    if(index < static_cast<int>(this->jumlah() - 1)) {
                        stream << ", ";
                    } else {
                        stream << "}";
                    }
                    ++index;
                }
                if(index == 0) {
                    stream << "{}";
                }
                return teks(stream.str());
            }

            bool berisi_kata_kunci(const Kata_Kunci& nilai) const {
                return this->nilai.find(nilai) != this->nilai.end();
            }

            void tambah(const Kata_Kunci& kata_kunci, const Nilai& nilai) {
                this->nilai[kata_kunci] = nilai;
            }

            void hapus(const Kata_Kunci& kata_kunci) {
                if(this->berisi_kata_kunci(kata_kunci)) {
                    this->nilai.erase(kata_kunci);
                }else{
                    throw std::runtime_error(teks("Kamu mencoba menghapus data di map dengan kata kunci '{}', sementara data dengan kata kunci itu tidak ada.", kata_kunci).ubah_ke_string());
                }
            }

            Nilai& operator[](const Kata_Kunci& kata_kunci) {
                if(this->berisi_kata_kunci(kata_kunci)) {
                    return this->nilai[kata_kunci];
                }
                throw std::runtime_error(teks("Kamu mencoba mengambil data di map dengan kata kunci '{}', sementara data dengan kata kunci itu tidak ada.", kata_kunci).ubah_ke_string());
            }
        private:
        protected:
    };
}