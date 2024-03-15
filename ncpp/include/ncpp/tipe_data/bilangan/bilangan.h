#pragma once

#include <memory>
#include "ncpp/tipe_data/bilangan/nilai_bilangan.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"

namespace ncpp {	
    class bilangan {
        public:	
						enum class tipe {
							bulat,
							desimal
						};
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
            std::unique_ptr<nilai_bilangan> nilai;
            friend std::ostream& operator<<(std::ostream& ost, const bilangan& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
        protected:
            [[nodiscard]] bilangan_bulat& ambil_nilai_bulat() const;
            [[nodiscard]] bilangan_desimal& ambil_nilai_desimal() const;
    };
}
