#pragma once

#include <algorithm>
#include <any>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#define benar true
#define salah false

namespace nstd {

    // Bisa Kosong
    template<class Tipe>
    using bisa_kosong = std::optional<Tipe>;

    // Konst
    template<class Tipe>
    using konst = const Tipe;

    // Bulat
    using bulat = int;

    // Desimal
    using desimal = double;

    // Karakter
    using karakter = char;

    // Kalimat
    using kalimat = std::string;

    // BenarSalah
    using benarsalah = bool;

    // Daftar
    template<class Value>
    using daftar = std::vector<Value>;

    // Peta
    template<class Key, class Value>
    using peta = std::map<Key, Value>;

    // Dinamis
    using dinamis = bisa_kosong<std::any>;

    template<class Tipe>
    inline bool isKosong(const bisa_kosong<Tipe>& tipe) {
        return !tipe.has_value();
    }

    inline bool isKosong(const dinamis& dynamic) {
        return !dynamic.has_value();
    }

    inline bool isTidakAda(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return !dynamic.value().has_value();
        }
        return false;
    }

    inline bool isBulat(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(bulat);
        }
        return false;
    }

    inline bool isDesimal(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(desimal);
        }
        return false;
    }

    inline bool isKarakter(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(karakter);
        }
        return false;
    }

    inline bool isKalimat(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(kalimat);
        }
        return false;
    }

    inline bool isBenarSalah(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(benarsalah);
        }
        return false;
    }

    template<class Value>
    inline bool isDaftar(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(daftar<Value>);
        }
        return false;
    }

    template<class Key, class Value>
    inline bool isPeta(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            return dynamic.value().type() == typeid(peta<Key, Value>);
        }
        return false;
    }

    inline bulat asBulat(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isBulat(dynamic)) {
                return std::any_cast<bulat>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan bilangan bulat.");
    }

    inline desimal asDesimal(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isDesimal(dynamic)) {
                return std::any_cast<desimal>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan bilangan desimal.");
    }

    inline karakter asKarakter(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isKarakter(dynamic)) {
                return std::any_cast<karakter>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan karakter.");
    }

    inline kalimat asKalimat(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isKalimat(dynamic)) {
                return std::any_cast<kalimat>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan kalimat.");
    }

    inline benarsalah asBenarSalah(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isBenarSalah(dynamic)) {
                return std::any_cast<benarsalah>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan benar atau salah.");
    }

    template<class Value>
    inline daftar<Value> asDaftar(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isDaftar<Value>(dynamic)) {
                return std::any_cast<daftar<Value>>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan daftar atau bukan daftar dengan value yang di tentukan.");
    }

    template<class Key, class Value>
    inline peta<Key, Value> asPeta(const dinamis& dynamic) {
        if(!isKosong(dynamic)) {
            if(isPeta<Key, Value>(dynamic)) {
                return std::any_cast<peta<Key, Value>>(dynamic.value());
            }
        }
        throw std::runtime_error("dynamic bukan peta atau bukan peta dengan key atau value yang di tentukan.");
    }

    template<class Value>
    inline bool contains(konst<daftar<Value>>& daftar, konst<Value>& nilai) {
        return std::find(daftar.begin(), daftar.end(), nilai) != daftar.end();
    }
    
}