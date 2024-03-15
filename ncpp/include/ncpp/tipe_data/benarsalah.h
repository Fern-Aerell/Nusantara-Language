#pragma once

#include <string>

#define benar ncpp::benarsalah(true)
#define salah ncpp::benarsalah(false)

namespace ncpp {

    class benarsalah {
        public:
            // Constructors
            benarsalah();
						benarsalah(const bool& nilai);
            // Destructor
            virtual ~benarsalah() = default;
            // Copy constructor
            benarsalah(const benarsalah& other);
            // Copy assignment operator
            benarsalah& operator=(const benarsalah& other);
            benarsalah& operator=(const bool& other);
            // Move constructor
            benarsalah(benarsalah&& other) noexcept;
            // Move assignment operator
            benarsalah& operator=(benarsalah&& other) noexcept;
            [[nodiscard]] std::string ubah_ke_string() const;
						[[nodiscard]] bool ubah_ke_bool() const;
            explicit operator bool() const;
            bool operator==(const benarsalah& nilai) const;
            bool operator==(const bool& nilai) const;
            bool operator!=(const benarsalah& nilai) const;
            bool operator!=(const bool& nilai) const;
            bool operator!() const;
            bool operator&&(const benarsalah& nilai) const;
            bool operator&&(const bool& nilai) const;
            bool operator||(const benarsalah& nilai) const;
            bool operator||(const bool& nilai) const;
        private:
            bool nilai;
            friend std::ostream& operator<<(std::ostream& ost, const benarsalah& data) { 
                ost << data.ubah_ke_string();
                return ost;
            }
    };
}

bool operator==(const bool& nilai_x, const ncpp::benarsalah& nilai_y);
bool operator!=(const bool& nilai_x, const ncpp::benarsalah& nilai_y);
bool operator&&(const bool& nilai_x, const ncpp::benarsalah& nilai_y);
bool operator||(const bool& nilai_x, const ncpp::benarsalah& nilai_y);
