#pragma once

#include <iostream>

#include "benarsalah.h"
#include "bilangan.h"
#include "dinamis.h"
#include "karakter.h"

namespace nstd {

  template<typename Tipe>
  inline void cetak(const Tipe& nilai) {
    std::cout << toString(nilai) << "\n";
  }

}  // namespace nstd
