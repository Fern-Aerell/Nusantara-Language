#pragma once

#include <memory>
#include <string>
#include "ncpp/nilai/nilai_bilangan.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"
#include "ncpp/tipe_data/teks.h"

namespace ncpp {
    class bilangan {
        public:
            // Constructors
            bilangan();
            explicit bilangan(const std::string& nilai);
            // Destructor
            virtual ~bilangan() = default;
            // Copy constructor
            bilangan(const bilangan& other);
            // Copy assignment operator
            bilangan& operator=(const bilangan& other);
            // Move constructor
            bilangan(bilangan&& other) noexcept;
            // Move assignment operator
            bilangan& operator=(bilangan&& other) noexcept;
            [[nodiscard]] bool ini_bulat() const;
            [[nodiscard]] bool ini_desimal() const;
            [[nodiscard]] teks ubah_ke_teks() const;
            bilangan operator+(const bilangan& nilai) const;
            bilangan operator-(const bilangan& nilai) const;
            bilangan operator*(const bilangan& nilai) const;
            bilangan operator/(const bilangan& nilai) const;
            bilangan operator%(const bilangan& nilai) const;
            bilangan operator~() const;
            bilangan& operator++();
            bilangan operator++(int);
            bilangan& operator--();
            bilangan operator--(int);
            bilangan operator&(const bilangan& nilai) const;
            bilangan operator^(const bilangan& nilai) const;
            bilangan operator|(const bilangan& nilai) const;
            bilangan operator<<(const bilangan& nilai) const;
            bilangan operator>>(const bilangan& nilai) const;
            bool operator<(const bilangan& nilai) const;
            bool operator<=(const bilangan& nilai) const;
            bool operator>(const bilangan& nilai) const;
            bool operator>=(const bilangan& nilai) const;
            bool operator==(const bilangan& nilai) const;
            bool operator!=(const bilangan& nilai) const;
            bilangan& operator+=(const bilangan& nilai);
            bilangan& operator-=(const bilangan& nilai);
            bilangan& operator*=(const bilangan& nilai);
            bilangan& operator/=(const bilangan& nilai);
            bilangan& operator%=(const bilangan& nilai);
            bilangan& operator&=(const bilangan& nilai);
            bilangan& operator^=(const bilangan& nilai);
            bilangan& operator|=(const bilangan& nilai);
            bilangan& operator<<=(const bilangan& nilai);
            bilangan& operator>>=(const bilangan& nilai);
        private:
            std::unique_ptr<nilai_bilangan> nilai;
            [[nodiscard]] bilangan_bulat& ambil_nilai_bulat() const;
            [[nodiscard]] bilangan_desimal& ambil_nilai_desimal() const;
            friend std::ostream& operator<<(std::ostream& ost, const bilangan& data) { 
                ost << data.ubah_ke_teks();
                return ost;
            }
    };
}
