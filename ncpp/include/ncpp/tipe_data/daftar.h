#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "ncpp/struktur_data.h"
#include "ncpp/tipe_data/teks.h"

#define NAMA_STRUKTUR_DATA_DAFTAR "daftar"

namespace ncpp {
    template<typename Tipe>
    class daftar: public struktur_data<std::vector<Tipe>> {
        public:
            // Constructors
            daftar()
            : 
                struktur_data<std::vector<Tipe>>(
                    NAMA_STRUKTUR_DATA_DAFTAR
                ) 
            {}

            explicit daftar(
                const std::vector<Tipe>& nilai
            )
            : 
                struktur_data<std::vector<Tipe>>(
                    NAMA_STRUKTUR_DATA_DAFTAR,
                    nilai
                ) 
            {}

            daftar(
                const batas_jumlah_maksimal& jumlah_maksimal, 
                const std::vector<Tipe>& nilai
            )
            : 
                struktur_data<std::vector<Tipe>>(
                    NAMA_STRUKTUR_DATA_DAFTAR,
                    jumlah_maksimal,
                    nilai
                ) 
            {}

            daftar(
                const batas_jumlah_minimal& jumlah_minimal, 
                const std::vector<Tipe>& nilai
            )
            : 
                struktur_data<std::vector<Tipe>>(
                    NAMA_STRUKTUR_DATA_DAFTAR,
                    jumlah_minimal,
                    nilai
                )
            {}

            daftar(
                const batas_jumlah& batas_jumlah,
                const std::vector<Tipe>& nilai
            )
            :
                struktur_data<std::vector<Tipe>>(
                    NAMA_STRUKTUR_DATA_DAFTAR,
                    batas_jumlah,
                    nilai
                )
            {}

            // Destructor
            ~daftar() = default;

            // Copy constructor
            daftar(const daftar& other) = default;

            // Copy assignment operator
            daftar& operator=(const daftar& other) = default;

            // Move constructor
            daftar(daftar&& other) noexcept = default;

            // Move assignment operator
            daftar& operator=(daftar&& other) noexcept = default;

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
                return std::find(this->begin(), this->end(), nilai) != this->end();
            }

            void tambah(const Tipe& nilai) {
                this->nilai.push_back(nilai);
            }

            void hapus(const size_t& urutan) {
                if(urutan <= 0) {
                    throw std::runtime_error("Urutan di daftar dimulai dari 1 bukan 0.");
                }
                if(urutan > this->jumlah()) {
                    throw std::runtime_error(teks("Kamu mencoba menghapus data urutan {} di daftar, sementara daftar hanya memiliki {} data.", urutan, this->jumlah()).ubah_ke_string());
                }
                size_t urutan_mod = urutan - 1;
                this->nilai.erase(this->begin() + urutan_mod);
            }

            Tipe& operator[](const size_t& urutan) {
                if(urutan <= 0) {
                    throw std::runtime_error("Urutan di daftar dimulai dari 1 bukan 0.");
                }
                if(urutan > this->jumlah()) {
                    throw std::runtime_error(teks("Kamu mencoba mengambil data urutan {} di daftar, sementara daftar hanya memiliki {} data.", urutan, this->jumlah()).ubah_ke_string());
                }
                size_t urutan_mod = urutan - 1;
                return this->nilai[urutan_mod];
            }

        private:
        protected:
    };
}