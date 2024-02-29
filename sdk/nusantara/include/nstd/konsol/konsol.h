#pragma once

#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"

namespace nstd {
  class konsol {
    public:
      static void cetak(const bilangan& nilai);

      static void cetak(const kalimat& nilai);

    private:
  };
}  // namespace nstd
