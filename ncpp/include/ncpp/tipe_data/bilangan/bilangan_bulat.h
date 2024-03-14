#pragma once

#include <gmp.h>
#include <ostream>
#include <regex>
#include <string>
#include "ncpp/nilai/nilai_bilangan.h"

namespace ncpp {
    class bilangan_desimal;
    class bilangan_bulat: public nilai_bilangan {
        public:
            // Constructors
						bilangan_bulat();
            explicit bilangan_bulat(const std::string& nilai);
						// Destructor
						~bilangan_bulat() override;
						// Copy constructor
				    bilangan_bulat(const bilangan_bulat& other);
						// Copy assignment operator
				    bilangan_bulat& operator=(const bilangan_bulat& other);
						// Move constructor
				    bilangan_bulat(bilangan_bulat&& other) noexcept;
						// Move assignment operator
				    bilangan_bulat& operator=(bilangan_bulat&& other) noexcept;
            static std::regex pattern();
            [[nodiscard]] std::string ubah_ke_string() const override;
            [[nodiscard]] const mpz_t& ambil() const;
						static bilangan_bulat ubah(const bilangan_desimal& nilai);
            static const int basis;
            bilangan_bulat operator+(const bilangan_bulat& nilai) const;
            bilangan_desimal operator+(const bilangan_desimal& nilai) const;
            bilangan_bulat operator-(const bilangan_bulat& nilai) const;
            bilangan_desimal operator-(const bilangan_desimal& nilai) const;
            bilangan_bulat operator*(const bilangan_bulat& nilai) const;
            bilangan_desimal operator*(const bilangan_desimal& nilai) const;
            bilangan_desimal operator/(const bilangan_bulat& nilai) const;
            bilangan_desimal operator/(const bilangan_desimal& nilai) const;
            bilangan_bulat operator%(const bilangan_bulat& nilai) const;
            bilangan_desimal operator%(const bilangan_desimal& nilai) const;
            bilangan_bulat operator~() const;
            bilangan_bulat& operator++();
            bilangan_bulat operator++(int);
            bilangan_bulat& operator--();
            bilangan_bulat operator--(int);
            bilangan_bulat operator&(const bilangan_bulat& nilai) const;
            bilangan_bulat operator^(const bilangan_bulat& nilai) const;
            bilangan_bulat operator|(const bilangan_bulat& nilai) const;
            bilangan_bulat operator<<(const bilangan_bulat& nilai) const;
            bilangan_bulat operator>>(const bilangan_bulat& nilai) const;
            bool operator<(const bilangan_bulat& nilai) const;
            bool operator<(const bilangan_desimal& nilai) const;
            bool operator<=(const bilangan_bulat& nilai) const;
            bool operator<=(const bilangan_desimal& nilai) const;
            bool operator>(const bilangan_bulat& nilai) const;
            bool operator>(const bilangan_desimal& nilai) const;
            bool operator>=(const bilangan_bulat& nilai) const;
            bool operator>=(const bilangan_desimal& nilai) const;
            bool operator==(const bilangan_bulat& nilai) const;
            bool operator==(const bilangan_desimal& nilai) const;
            bool operator!=(const bilangan_bulat& nilai) const;
            bool operator!=(const bilangan_desimal& nilai) const;
            bilangan_bulat& operator+=(const bilangan_bulat& nilai);
            bilangan_bulat& operator-=(const bilangan_bulat& nilai);
            bilangan_bulat& operator*=(const bilangan_bulat& nilai);
            bilangan_bulat& operator/=(const bilangan_bulat& nilai);
            bilangan_bulat& operator%=(const bilangan_bulat& nilai);
            bilangan_bulat& operator&=(const bilangan_bulat& nilai);
            bilangan_bulat& operator^=(const bilangan_bulat& nilai);
            bilangan_bulat& operator|=(const bilangan_bulat& nilai);
            bilangan_bulat& operator<<=(const bilangan_bulat& nilai);
            bilangan_bulat& operator>>=(const bilangan_bulat& nilai);
        private:
            mpz_t nilai;
            friend std::ostream& operator<<(std::ostream& ost, const bilangan_bulat& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}
