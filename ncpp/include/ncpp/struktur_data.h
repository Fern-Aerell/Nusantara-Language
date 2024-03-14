#pragma once

#include <string>
#include "ncpp/batas_jumlah.h"

namespace ncpp {
    template<typename Tipe_Struktur>
    class struktur_data {
        public:
            // Constructors
            explicit struktur_data(
                std::string nama_struktur_data
            )
            : 
            nama_struktur_data(std::move(nama_struktur_data)),
            nilai({})
            {}
            
            explicit struktur_data(
                std::string nama_struktur_data, 
                const Tipe_Struktur& nilai
            )
            : 
            nama_struktur_data(std::move(nama_struktur_data)),
            nilai(nilai)
            {}

            struktur_data(
                std::string nama_struktur_data, 
                const batas_jumlah_maksimal& jumlah_maksimal, 
                const Tipe_Struktur& nilai
            )
            : 
            nama_struktur_data(std::move(nama_struktur_data)),
            batas_jumlah(jumlah_maksimal),
            nilai(nilai)
            {
                this->validasi_jumlah();
            }

            struktur_data(
                std::string nama_struktur_data, 
                const batas_jumlah_minimal& jumlah_minimal, 
                const Tipe_Struktur& nilai
            )
            : 
            nama_struktur_data(std::move(nama_struktur_data)) ,
            batas_jumlah(jumlah_minimal), 
            nilai(nilai)
            {
                this->validasi_jumlah();
            }

            struktur_data(
                std::string nama_struktur_data,
                const batas_jumlah& batas_jumlah,
                const Tipe_Struktur& nilai
            )
            :
            nama_struktur_data(std::move(nama_struktur_data)),
            batas_jumlah(batas_jumlah), 
            nilai(nilai)
            {
                this->validasi_jumlah();
            }

            // Destructor
            virtual ~struktur_data() = default;

            // Copy constructor
            struktur_data(
                const struktur_data& other
            )
            : 
            nama_struktur_data(other.nama_struktur_data), 
            batas_jumlah(other.batas_jumlah),
            nilai(other.nilai)
            {}

            // Copy assignment operator
            struktur_data& operator=(const struktur_data& other) {
                if(this == &other) {return *this;}
                this->nama_struktur_data = other.nama_struktur_data;
                this->batas_jumlah = other.batas_jumlah;
                this->nilai = other.nilai;
                return *this;
            }

            // Move constructor
            struktur_data(
                struktur_data&& other
            ) noexcept
            : 
            nama_struktur_data(std::move(other.nama_struktur_data)), 
            batas_jumlah(std::move(other.batas_jumlah)),
            nilai(std::move(other.nilai))
            {}

            // Move assignment operator
            struktur_data& operator=(struktur_data&& other) noexcept {
                this->nama_struktur_data = std::move(other.nama_struktur_data);
                this->batas_jumlah = std::move(other.batas_jumlah);
                this->nilai = std::move(other.nilai);
                return *this;
            }

            [[nodiscard]] size_t jumlah() const {
                return this->nilai.size();
            }
            [[nodiscard]] bool ini_kosong() const {
                return this->jumlah() == 0;
            }
            [[nodiscard]] bool ini_tidak_kosong() const {
                return this->jumlah() > 0;
            }
            Tipe_Struktur::const_iterator begin() const {
                return this->nilai.begin();
            }
            Tipe_Struktur::const_iterator end() const {
                return this->nilai.end();
            }
            [[nodiscard]] virtual std::string ubah_ke_string() const = 0;
            bool operator==(const struktur_data& other) {
                return this->nama_struktur_data == other.nama_struktur_data &&
                    this->batas_jumlah == other.batas_jumlah &&
                    this->nilai == other.nilai;
            }
            bool operator!=(const struktur_data& other) {
                return !(*this == other);
            }
            [[nodiscard]] bool ada_batas_jumlah() const {
                return this->ada_batas_jumlah_minimal() || this->ada_batas_jumlah_maksimal();
            }
            [[nodiscard]] bool ada_batas_jumlah_minimal() const {
                return this->batas_jumlah.min.batasan;
            }
            [[nodiscard]] bool ada_batas_jumlah_maksimal() const {
                return this->batas_jumlah.max.batasan;
            }
            [[nodiscard]] size_t batas_jumlah_minimal() const {
                if(this->ada_batas_jumlah_minimal()) {
                    return this->batas_jumlah.min.jumlah;
                }
                throw std::runtime_error(teks("Tidak ada batas jumlah minimal pada {}.", this->nama_struktur_data).ubah_ke_string());
            }
            [[nodiscard]] size_t batas_jumlah_maksimal() const {
                if(this->ada_batas_jumlah_maksimal()) {
                    return this->batas_jumlah.max.jumlah;
                }
                throw std::runtime_error(teks("Tidak ada batas jumlah maksimal pada {}.", this->nama_struktur_data).ubah_ke_string());
            }
        private:
            std::string nama_struktur_data;
            batas_jumlah batas_jumlah;
            void validasi_jumlah() {
                if(this->batas_jumlah.min.batasan) {
                    const size_t& jumlah_minimal = this->batas_jumlah.min.jumlah;
                    if(this->jumlah() < jumlah_minimal) {
                        throw std::runtime_error(teks("Jumlah data yang ada di {} minimal {} data, sementara kamu baru mengisi {} data.", this->nama_struktur_data, jumlah_minimal, this->jumlah()).ubah_ke_string());
                    }
                }
                if(this->batas_jumlah.max.batasan) {
                    const size_t& jumlah_maksimal = this->batas_jumlah.max.jumlah;
                    if(this->jumlah() > jumlah_maksimal) {
                        throw std::runtime_error(teks("Jumlah data yang ada di {} maksimal {} data, sementara kamu mengisinya dengan {} data.", this->nama_struktur_data, jumlah_maksimal, this->jumlah()).ubah_ke_string());
                    }
                }
            }
            friend std::ostream& operator<<(std::ostream& ost, const struktur_data& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
        protected:
            Tipe_Struktur nilai;
    };
}