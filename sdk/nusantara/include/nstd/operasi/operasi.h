#pragma once

#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"

namespace nstd {
  benarsalah operator<(const int& nilaiX, const nstd::_bilangan_bulat& nilaiY);

  benarsalah operator<(
      const int& nilaiX, const nstd::_bilangan_desimal& nilaiY
  );

  benarsalah operator<(const int& nilaiX, const nstd::bilangan& nilaiY);
}  // namespace nstd
