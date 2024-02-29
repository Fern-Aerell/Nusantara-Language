#pragma once

#include <map>

#include "core/core.h"
#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

namespace nstd {

  class peta: public tipe_data {
    public:
      explicit peta(STD map<PTR(tipe_data), PTR(tipe_data)> nilai);

      ND benarsalah berisiKunci(const PTR(tipe_data) & key) const;

      ND benarsalah kosong() const;

      ND benarsalah tidakKosong() const;

      ND bilangan jumlahIsi() const;

      ND kalimat ubahKeKalimat() const;

    private:
      STD map<PTR(tipe_data), PTR(tipe_data)> nilai;
  };

}  // namespace nstd
