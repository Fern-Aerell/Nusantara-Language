#pragma once

#include <mpfr.h>
#include <ostream>
#include <regex>
#include <string>
#include "ncpp/tipe_data/bilangan/_nilai_bilangan_.h"

namespace ncpp {
    class _bilangan_bulat_;
    class _bilangan_desimal_: public _nilai_bilangan_ {
        public:
            // Constructors
						_bilangan_desimal_();
            explicit _bilangan_desimal_(const std::string& nilai);
						// Destructor
						~_bilangan_desimal_() override;
						// Copy constructor
				    _bilangan_desimal_(const _bilangan_desimal_& other);
				    // Copy assignment operator
				    _bilangan_desimal_& operator=(const _bilangan_desimal_& other);				    
						// Move constructor
				    _bilangan_desimal_(_bilangan_desimal_&& other) noexcept;
				    // Move assignment operator
    				_bilangan_desimal_& operator=(_bilangan_desimal_&& other) noexcept;
            static std::regex pattern();
            [[nodiscard]] std::string ubah_ke_string() const override;
						[[nodiscard]] std::string ubah_ke_string_tetap(const int& presisi) const;
						[[nodiscard]] std::string ubah_ke_string_presisi(const int& presisi) const;
            [[nodiscard]] const mpfr_t& ambil() const;
						static _bilangan_desimal_ ubah(const _bilangan_bulat_& nilai);
            static const int basis;
            static const int presisi_string_bawaan;
            static const double toleransi;
            static const mpfr_rnd_t pembulatan;
            _bilangan_desimal_ operator+(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator+(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_ operator-(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator-(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_ operator*(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator*(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_ operator/(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator/(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_ operator%(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator%(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_& operator++();
            _bilangan_desimal_ operator++(int);
            _bilangan_desimal_& operator--();
            _bilangan_desimal_ operator--(int);
            bool operator<(const _bilangan_desimal_& nilai) const;
            bool operator<(const _bilangan_bulat_& nilai) const;
            bool operator<=(const _bilangan_desimal_& nilai) const;
            bool operator<=(const _bilangan_bulat_& nilai) const;
            bool operator>(const _bilangan_desimal_& nilai) const;
            bool operator>(const _bilangan_bulat_& nilai) const;
            bool operator>=(const _bilangan_desimal_& nilai) const;
            bool operator>=(const _bilangan_bulat_& nilai) const;
            bool operator==(const _bilangan_desimal_& nilai) const;
            bool operator==(const _bilangan_bulat_& nilai) const;
            bool operator!=(const _bilangan_desimal_& nilai) const;
            bool operator!=(const _bilangan_bulat_& nilai) const;
            [[nodiscard]] int presisi() const;
            _bilangan_desimal_& operator+=(const _bilangan_bulat_& nilai);
            _bilangan_desimal_& operator+=(const _bilangan_desimal_& nilai);
            _bilangan_desimal_& operator-=(const _bilangan_bulat_& nilai);
            _bilangan_desimal_& operator-=(const _bilangan_desimal_& nilai);
            _bilangan_desimal_& operator*=(const _bilangan_bulat_& nilai);
            _bilangan_desimal_& operator*=(const _bilangan_desimal_& nilai);
            _bilangan_desimal_& operator/=(const _bilangan_bulat_& nilai);
            _bilangan_desimal_& operator/=(const _bilangan_desimal_& nilai);
            _bilangan_desimal_& operator%=(const _bilangan_bulat_& nilai);
            _bilangan_desimal_& operator%=(const _bilangan_desimal_& nilai);
        private:
             mpfr_t nilai;
             friend std::ostream& operator<<(std::ostream& ost, const _bilangan_desimal_& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}
