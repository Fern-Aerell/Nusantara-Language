#pragma once

#include <string>

namespace ncpp {
    class _nilai_bilangan_ {
        public:
            // Constructors
            _nilai_bilangan_() = default;
            // Destructor
            virtual ~_nilai_bilangan_() = default;
            // Copy constructor
            _nilai_bilangan_(const _nilai_bilangan_& other) = default;
            // Copy assignment operator
            _nilai_bilangan_& operator=(const _nilai_bilangan_& other) = default;
            // Move constructor
            _nilai_bilangan_(_nilai_bilangan_&& other) noexcept = default;
            // Move assignment operator
            _nilai_bilangan_& operator=(_nilai_bilangan_&& other) noexcept = default;

            [[nodiscard]] virtual std::string ubah_ke_string() const = 0;
        private:
    };

}