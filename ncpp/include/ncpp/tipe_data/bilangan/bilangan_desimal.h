#pragma once

#include <mpfr.h>
#include <ostream>
#include <regex>
#include <string>
#include "ncpp/tipe_data/bilangan/nilai_bilangan.h"

namespace ncpp {
    class bilangan_bulat;
    class bilangan_desimal: public nilai_bilangan {
        public:
            // Constructors
						bilangan_desimal();
            explicit bilangan_desimal(const std::string& nilai);
						// Destructor
						~bilangan_desimal() override;
						// Copy constructor
				    bilangan_desimal(const bilangan_desimal& other);
				    // Copy assignment operator
				    bilangan_desimal& operator=(const bilangan_desimal& other);				    
						// Move constructor
				    bilangan_desimal(bilangan_desimal&& other) noexcept;
				    // Move assignment operator
    				bilangan_desimal& operator=(bilangan_desimal&& other) noexcept;
            static std::regex pattern();
            [[nodiscard]] std::string ubah_ke_string() const override;
						[[nodiscard]] std::string ubah_ke_string_tetap(const int& presisi) const;
						[[nodiscard]] std::string ubah_ke_string_presisi(const int& presisi) const;
            [[nodiscard]] const mpfr_t& ambil() const;
						static bilangan_desimal ubah(const bilangan_bulat& nilai);
            static const int basis;
            static const int presisi_string_bawaan;
            static const double toleransi;
            static const mpfr_rnd_t pembulatan;
            bilangan_desimal operator+(const bilangan_bulat& nilai) const;
            bilangan_desimal operator+(const bilangan_desimal& nilai) const;
            bilangan_desimal operator-(const bilangan_bulat& nilai) const;
            bilangan_desimal operator-(const bilangan_desimal& nilai) const;
            bilangan_desimal operator*(const bilangan_bulat& nilai) const;
            bilangan_desimal operator*(const bilangan_desimal& nilai) const;
            bilangan_desimal operator/(const bilangan_bulat& nilai) const;
            bilangan_desimal operator/(const bilangan_desimal& nilai) const;
            bilangan_desimal operator%(const bilangan_bulat& nilai) const;
            bilangan_desimal operator%(const bilangan_desimal& nilai) const;
            bilangan_desimal& operator++();
            bilangan_desimal operator++(int);
            bilangan_desimal& operator--();
            bilangan_desimal operator--(int);
            bool operator<(const bilangan_desimal& nilai) const;
            bool operator<(const bilangan_bulat& nilai) const;
            bool operator<=(const bilangan_desimal& nilai) const;
            bool operator<=(const bilangan_bulat& nilai) const;
            bool operator>(const bilangan_desimal& nilai) const;
            bool operator>(const bilangan_bulat& nilai) const;
            bool operator>=(const bilangan_desimal& nilai) const;
            bool operator>=(const bilangan_bulat& nilai) const;
            bool operator==(const bilangan_desimal& nilai) const;
            bool operator==(const bilangan_bulat& nilai) const;
            bool operator!=(const bilangan_desimal& nilai) const;
            bool operator!=(const bilangan_bulat& nilai) const;
            [[nodiscard]] int presisi() const;
            bilangan_desimal& operator+=(const bilangan_bulat& nilai);
            bilangan_desimal& operator+=(const bilangan_desimal& nilai);
            bilangan_desimal& operator-=(const bilangan_bulat& nilai);
            bilangan_desimal& operator-=(const bilangan_desimal& nilai);
            bilangan_desimal& operator*=(const bilangan_bulat& nilai);
            bilangan_desimal& operator*=(const bilangan_desimal& nilai);
            bilangan_desimal& operator/=(const bilangan_bulat& nilai);
            bilangan_desimal& operator/=(const bilangan_desimal& nilai);
            bilangan_desimal& operator%=(const bilangan_bulat& nilai);
            bilangan_desimal& operator%=(const bilangan_desimal& nilai);
        private:
             mpfr_t nilai;
             friend std::ostream& operator<<(std::ostream& ost, const bilangan_desimal& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}

template<>
struct std::is_arithmetic<ncpp::bilangan_desimal> : true_type {};
