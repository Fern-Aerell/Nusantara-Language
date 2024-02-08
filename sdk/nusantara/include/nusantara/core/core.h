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

    inline bool isKosong(const dinamis& dinamis) {
        return !dinamis.has_value();
    }

    inline bool isTidakAda(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return !dinamis.value().has_value();
        }
        return false;
    }

    inline bool isBulat(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(bulat);
        }
        return false;
    }

    inline bool isDesimal(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(desimal);
        }
        return false;
    }

    inline bool isKarakter(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(karakter);
        }
        return false;
    }

    inline bool isKalimat(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(kalimat);
        }
        return false;
    }

    inline bool isBenarSalah(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(benarsalah);
        }
        return false;
    }

    template<class Value>
    inline bool isDaftar(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(daftar<Value>);
        }
        return false;
    }

    template<class Key, class Value>
    inline bool isPeta(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            return dinamis.value().type() == typeid(peta<Key, Value>);
        }
        return false;
    }

    inline bulat asBulat(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isBulat(dinamis)) {
                return std::any_cast<bulat>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan bilangan bulat.");
    }

    inline desimal asDesimal(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isDesimal(dinamis)) {
                return std::any_cast<desimal>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan bilangan desimal.");
    }

    inline karakter asKarakter(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isKarakter(dinamis)) {
                return std::any_cast<karakter>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan karakter.");
    }

    inline kalimat asKalimat(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isKalimat(dinamis)) {
                return std::any_cast<kalimat>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan kalimat.");
    }

    inline benarsalah asBenarSalah(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isBenarSalah(dinamis)) {
                return std::any_cast<benarsalah>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan benar atau salah.");
    }

    template<class Value>
    inline daftar<Value> asDaftar(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isDaftar<Value>(dinamis)) {
                return std::any_cast<daftar<Value>>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan daftar atau bukan daftar dengan value yang di tentukan.");
    }

    template<class Key, class Value>
    inline peta<Key, Value> asPeta(const dinamis& dinamis) {
        if(!isKosong(dinamis)) {
            if(isPeta<Key, Value>(dinamis)) {
                return std::any_cast<peta<Key, Value>>(dinamis.value());
            }
        }
        throw std::runtime_error("dinamis bukan peta atau bukan peta dengan key atau value yang di tentukan.");
    }

    template<class Value>
    inline bool contains(konst<daftar<Value>>& daftar, konst<Value>& nilai) {
        return std::find(daftar.begin(), daftar.end(), nilai) != daftar.end();
    }
    
}