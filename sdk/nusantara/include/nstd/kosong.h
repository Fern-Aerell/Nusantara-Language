#pragma once

#include <optional>
#include <stdexcept>

namespace nstd {

    template<typename  Tipe>
    using bisa_kosong = std::optional<Tipe>;

    template<typename Tipe>
    inline bool kosong(const bisa_kosong<Tipe>& variableMungkinKosong) {
        return !variableMungkinKosong.has_value();
    }

    template<typename Tipe>
    inline bool tidakKosong(const bisa_kosong<Tipe>& variableMungkinKosong) {
        return variableMungkinKosong.has_value();
    }

    template<typename Tipe>
    inline Tipe get(const bisa_kosong<Tipe>& variableMungkinKosong) {
        if(tidakKosong(variableMungkinKosong)) {
            return variableMungkinKosong.value();
        }
        throw std::runtime_error("Tidak dapat mengambil nilai dari variable kosong.");
    }

}