#pragma once

#include <iostream>

#include "nusantara/core/core.h"

namespace nstd {

class Konsol {
 public:
  static void cetak(konst<bulat> &bulat);
  static void cetak(konst<desimal> &desimal);
  static void cetak(konst<karakter> &karakter);
  static void cetak(konst<kalimat> &kalimat);
  static void cetak(konst<benarsalah> &benarsalah);
  static void cetak(konst<dinamis> &dinamis);
  template <class Value>
  static void cetak(konst<daftar<Value>> &daftar) {
    std::cout << nstd::ubahKeKalimat(daftar) << "\n";
  }
  template <class Key, class Value>
  static void cetak(konst<peta<Key, Value>> &peta) {
    std::cout << nstd::ubahKeKalimat(peta) << "\n";
  }

 private:
};

}  // namespace nstd