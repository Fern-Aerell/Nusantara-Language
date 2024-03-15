#pragma once

#include <memory>
#include <string>
#include "ncpp/tipe_data/bilangan/_nilai_bilangan_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_bulat_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"

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
            [[nodiscard]] std::string ubah_ke_string() const;
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
            std::unique_ptr<_nilai_bilangan_> nilai;
            friend std::ostream& operator<<(std::ostream& ost, const bilangan& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
        protected:
            [[nodiscard]] _bilangan_bulat_& ambil_nilai_bulat() const;
            [[nodiscard]] _bilangan_desimal_& ambil_nilai_desimal() const;
    };
}
