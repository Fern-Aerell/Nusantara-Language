#pragma once

#include "core/string.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"

namespace nstd {

  STR& operator+=(STR& nilaiX, const kalimat& nilaiY);

  benarsalah operator<(const int& nilaiX, const _bilangan_bulat& nilaiY);

  benarsalah operator<(const int& nilaiX, const _bilangan_desimal& nilaiY);

  benarsalah operator<(const int& nilaiX, const bilangan& nilaiY);
  
  bilangan operator+(const int& nilaiX, const _bilangan_bulat& nilaiY);

  bilangan operator+(const int& nilaiX, const _bilangan_desimal& nilaiY);

  bilangan operator+(const int& nilaiX, const bilangan& nilaiY);

  bilangan operator-(const int& nilaiX, const _bilangan_bulat& nilaiY);

  bilangan operator-(const int& nilaiX, const _bilangan_desimal& nilaiY);

  bilangan operator-(const int& nilaiX, const bilangan& nilaiY);
}  // namespace nstd
