#pragma once

#include <algorithm>
#include <any>
#include <map>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#define benar true
#define salah false

namespace nstd {

// Bisa Kosong
template <class Tipe>
using bisa_kosong = std::optional<Tipe>;

// Konst
template <class Tipe>
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
template <class Value>
using daftar = std::vector<Value>;

// Peta
template <class Key, class Value>
using peta = std::map<Key, Value>;

// Dinamis
using dinamis = bisa_kosong<std::any>;

template <class Tipe>
benarsalah isKosong(const bisa_kosong<Tipe> &tipe) {
  return !tipe.has_value();
}

benarsalah isKosong(const dinamis &dinamis);

benarsalah isTidakAda(const dinamis &dinamis);

benarsalah isBulat(const dinamis &dinamis);

benarsalah isDesimal(const dinamis &dinamis);

benarsalah isKarakter(const dinamis &dinamis);

benarsalah isKalimat(const dinamis &dinamis);

benarsalah isBenarSalah(const dinamis &dinamis);

template <class Value>
benarsalah isDaftar(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(daftar<Value>);
  }
  return false;
}

template <class Key, class Value>
benarsalah isPeta(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(peta<Key, Value>);
  }
  return false;
}

bulat asBulat(const dinamis &dinamis);

desimal asDesimal(const dinamis &dinamis);

karakter asKarakter(const dinamis &dinamis);

kalimat asKalimat(const dinamis &dinamis);

benarsalah asBenarSalah(const dinamis &dinamis);

template <class Value>
daftar<Value> asDaftar(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isDaftar<Value>(dinamis)) {
      return std::any_cast<daftar<Value>>(dinamis.value());
    }
  }
  throw std::runtime_error(
      "dinamis bukan daftar atau bukan daftar dengan value yang di tentukan.");
}

template <class Key, class Value>
peta<Key, Value> asPeta(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isPeta<Key, Value>(dinamis)) {
      return std::any_cast<peta<Key, Value>>(dinamis.value());
    }
  }
  throw std::runtime_error(
      "dinamis bukan peta atau bukan peta dengan key "
      "atau value yang di tentukan.");
}

template <class Value>
benarsalah contains(konst<daftar<Value>> &daftar, konst<Value> &nilai) {
  return std::find(daftar.begin(), daftar.end(), nilai) != daftar.end();
}

kalimat ubahKeKalimat(konst<bulat> &bulat);

kalimat ubahKeKalimat(konst<desimal> &desimal);

kalimat ubahKeKalimat(konst<karakter> &karakter);

kalimat ubahKeKalimat(konst<benarsalah> &benarsalah);

template <class Value>
kalimat ubahKeKalimat(konst<daftar<Value>> &daftar) {
  std::ostringstream stream;
  int index = 0;
  for (konst<Value> &child : daftar) {
    if (index == 0) {
      stream << "["
             << "\n";
    }
    stream << " [" << index << "]=" << child;
    if (index < (daftar.size() - 1)) {
      stream << ","
             << "\n";
    } else {
      stream << "\n"
             << "]";
    }
    ++index;
  }
  return stream.str();
}

template <class Key, class Value>
kalimat ubahKeKalimat(konst<peta<Key, Value>> &peta) {
  std::ostringstream stream;
  int index = 0;
  for (const auto &pair : peta) {
    if (index == 0) {
      stream << "["
             << "\n";
    }
    stream << " [" << pair.first << "]=" << pair.second;
    if (index < (peta.size() - 1)) {
      stream << ","
             << "\n";
    } else {
      stream << "\n"
             << "]";
    }
    ++index;
  }
  return stream.str();
}

kalimat ubahKeKalimat(konst<dinamis> &dinamis);

}  // namespace nstd
