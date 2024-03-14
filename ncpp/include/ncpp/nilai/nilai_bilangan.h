#pragma once

#include <string>

namespace ncpp {
    class nilai_bilangan {
        public:
            // Constructors
            nilai_bilangan() = default;
            // Destructor
            virtual ~nilai_bilangan() = default;
            // Copy constructor
            nilai_bilangan(const nilai_bilangan& other) = default;
            // Copy assignment operator
            nilai_bilangan& operator=(const nilai_bilangan& other) = default;
            // Move constructor
            nilai_bilangan(nilai_bilangan&& other) noexcept = default;
            // Move assignment operator
            nilai_bilangan& operator=(nilai_bilangan&& other) noexcept = default;

            [[nodiscard]] virtual std::string ubah_ke_string() const = 0;
        private:
    };

}