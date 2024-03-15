#pragma once

#include <gmp.h>
#include <ostream>
#include <regex>
#include <string>
#include "ncpp/tipe_data/bilangan/_nilai_bilangan_.h"

namespace ncpp {
    class _bilangan_desimal_;
    class _bilangan_bulat_: public _nilai_bilangan_ {
        public:
            // Constructors
						_bilangan_bulat_();
            explicit _bilangan_bulat_(const std::string& nilai);
						// Destructor
						~_bilangan_bulat_() override;
						// Copy constructor
				    _bilangan_bulat_(const _bilangan_bulat_& other);
						// Copy assignment operator
				    _bilangan_bulat_& operator=(const _bilangan_bulat_& other);
						// Move constructor
				    _bilangan_bulat_(_bilangan_bulat_&& other) noexcept;
						// Move assignment operator
				    _bilangan_bulat_& operator=(_bilangan_bulat_&& other) noexcept;
            static std::regex pattern();
            [[nodiscard]] std::string ubah_ke_string() const override;
            [[nodiscard]] const mpz_t& ambil() const;
						static _bilangan_bulat_ ubah(const _bilangan_desimal_& nilai);
            static const int basis;
            _bilangan_bulat_ operator+(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator+(const _bilangan_desimal_& nilai) const;
            _bilangan_bulat_ operator-(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator-(const _bilangan_desimal_& nilai) const;
            _bilangan_bulat_ operator*(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator*(const _bilangan_desimal_& nilai) const;
            _bilangan_desimal_ operator/(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator/(const _bilangan_desimal_& nilai) const;
            _bilangan_bulat_ operator%(const _bilangan_bulat_& nilai) const;
            _bilangan_desimal_ operator%(const _bilangan_desimal_& nilai) const;
            _bilangan_bulat_ operator~() const;
            _bilangan_bulat_& operator++();
            _bilangan_bulat_ operator++(int);
            _bilangan_bulat_& operator--();
            _bilangan_bulat_ operator--(int);
            _bilangan_bulat_ operator&(const _bilangan_bulat_& nilai) const;
            _bilangan_bulat_ operator^(const _bilangan_bulat_& nilai) const;
            _bilangan_bulat_ operator|(const _bilangan_bulat_& nilai) const;
            _bilangan_bulat_ operator<<(const _bilangan_bulat_& nilai) const;
            _bilangan_bulat_ operator>>(const _bilangan_bulat_& nilai) const;
            bool operator<(const _bilangan_bulat_& nilai) const;
            bool operator<(const _bilangan_desimal_& nilai) const;
            bool operator<=(const _bilangan_bulat_& nilai) const;
            bool operator<=(const _bilangan_desimal_& nilai) const;
            bool operator>(const _bilangan_bulat_& nilai) const;
            bool operator>(const _bilangan_desimal_& nilai) const;
            bool operator>=(const _bilangan_bulat_& nilai) const;
            bool operator>=(const _bilangan_desimal_& nilai) const;
            bool operator==(const _bilangan_bulat_& nilai) const;
            bool operator==(const _bilangan_desimal_& nilai) const;
            bool operator!=(const _bilangan_bulat_& nilai) const;
            bool operator!=(const _bilangan_desimal_& nilai) const;
            _bilangan_bulat_& operator+=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator-=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator*=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator/=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator%=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator&=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator^=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator|=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator<<=(const _bilangan_bulat_& nilai);
            _bilangan_bulat_& operator>>=(const _bilangan_bulat_& nilai);
        private:
            mpz_t nilai;
            friend std::ostream& operator<<(std::ostream& ost, const _bilangan_bulat_& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}
