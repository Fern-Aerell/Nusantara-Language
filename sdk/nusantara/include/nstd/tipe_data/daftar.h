#pragma once

#include <memory>
#include <vector>

#include "core/core.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

namespace nstd {

  class daftar: public tipe_data {
    public:
      explicit daftar(std::vector<std::unique_ptr<tipe_data>> nilai);

      ND bool berisi(const std::unique_ptr<tipe_data>& nilai) const;

      ND bool kosong() const;

      ND bool tidakKosong() const;

      ND bilangan jumlahIsi() const;

      ND kalimat ubahKeKalimat() const;

    private:
      std::vector<std::unique_ptr<tipe_data>> nilai;
  };

}  // namespace nstd
