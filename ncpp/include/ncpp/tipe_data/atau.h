#pragma once

#include <sstream>
#include <string>
#include <type_traits>
#include <variant>

namespace ncpp {
    template<typename... Tipe>
    class atau {
        public:

            template<
                typename Tipe1,
                typename = std::enable_if_t<std::disjunction_v<std::is_same<Tipe1, Tipe>...>>
            >
            atau(const Tipe1& nilai): nilai(nilai) {
                static_assert(sizeof...(Tipe) >= 2, "Minimal tentukan 2 tipe data yang berbeda untuk tipe data atau.");
            }

            ~atau() = default;

            atau(const atau& other): nilai(other.nilai) {};

            atau(atau&& other) noexcept : nilai(std::move(other.nilai)) {};

            atau& operator=(const atau& other) {
                if(this == &other) {return *this;}
                this->nilai = other.nilai;
                return *this;
            }

            atau& operator=(atau&& other)  noexcept {
                this->nilai = std::move(other.nilai);
                return *this;
            }

            [[nodiscard]] std::string ubah_ke_string() const {
                return std::visit([](auto&& arg) {
                    std::ostringstream stream;
                    stream << arg;
                    return stream.str();
                }, nilai);
            }

        private:
            std::variant<Tipe...> nilai;

            friend std::ostream& operator<<(std::ostream& ost, const atau& data) {
                ost << data.ubah_ke_string();
                return ost;
            }
        protected:
    };
}