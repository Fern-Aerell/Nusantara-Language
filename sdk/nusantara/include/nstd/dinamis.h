#pragma once

#include <any>
#include <format>
#include <stdexcept>
#include <string>
#include "bilangan.h"
#include "karakter.h"
#include "benarsalah.h"

namespace nstd {

    using dinamis = std::any;

    inline bool kosong(const dinamis& dinamis) {
        return !dinamis.has_value();
    }

    inline bool tidakKosong(const dinamis& dinamis) {
        return dinamis.has_value();
    }

    template<typename Tipe>
    inline bool is(const dinamis& dinamis) {
        if(tidakKosong(dinamis)) {
            return dinamis.type() == typeid(Tipe);
        }
        return false;
    }

    template<typename Tipe>
    inline Tipe as(const dinamis& dinamis) {
        if(tidakKosong(dinamis)) {
            if(is<Tipe>(dinamis)) {
                return std::any_cast<Tipe>(dinamis);
            }
        }
        throw std::runtime_error(std::format("dinamis bukan {}.", typeid(Tipe).name()));
    }

    inline std::string toString(const dinamis& dinamis) {
        if(tidakKosong(dinamis)) {
            if(is<int>(dinamis)) {
                return toString(as<int>(dinamis));
            }else if(is<double>(dinamis)) {
                return toString(as<double>(dinamis));
            }else if(is<char>(dinamis)) {
                return toString(as<char>(dinamis));
            }else if(is<std::string>(dinamis)) {
                return as<std::string>(dinamis);
            }else if(is<bool>(dinamis)) {
                return toString(as<bool>(dinamis));
            }else{
                throw std::runtime_error(
                    std::format(
                        "Tipe {} tidak bisa untuk di ubah ke string.\n",
                        dinamis.type().name()
                    )
                );
            }
        }
        return "kosong";
    }

}