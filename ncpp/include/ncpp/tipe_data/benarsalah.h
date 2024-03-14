#pragma once

#include <string>

namespace ncpp {
    class benarsalah {
        public:
            // Constructors
            benarsalah();
            explicit benarsalah(const std::string& nilai);
            // Destructor
            virtual ~benarsalah() = default;
            // Copy constructor
            benarsalah(const benarsalah& other);
            // Copy assignment operator
            benarsalah& operator=(const benarsalah& other);
            // Move constructor
            benarsalah(benarsalah&& other) noexcept;
            // Move assignment operator
            benarsalah& operator=(benarsalah&& other) noexcept;
            [[nodiscard]] std::string ubah_ke_string() const;
            explicit operator bool() const;
            static benarsalah benar();
            static benarsalah salah();
            benarsalah operator==(const benarsalah& nilai) const;
            benarsalah operator!=(const benarsalah& nilai) const;
            benarsalah operator!() const;
            benarsalah operator&&(const benarsalah& nilai) const;
            benarsalah operator||(const benarsalah& nilai) const;
        private:
            bool nilai;
            friend std::ostream& operator<<(std::ostream& ost, const benarsalah& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}
