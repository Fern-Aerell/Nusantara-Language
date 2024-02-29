#pragma once

#include <ostream>

#include "core/core.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define BENAR NSTD benarsalah(true)
#define SALAH NSTD benarsalah(false)

namespace nstd {

  class benarsalah: public tipe_data {
    public:
      explicit benarsalah(const bool& nilai);

      ND kalimat ubahKeKalimat() const;

      static benarsalah ubah(const kalimat& nilai);

      explicit operator bool() const;

    private:
      bool nilai;

      friend STD ostream& operator<<(
          STD ostream& ost, const NSTD benarsalah& obj
      ) {
        ost << obj.ubahKeKalimat();
        return ost;
      }
  };
}  // namespace nstd
