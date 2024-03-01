#pragma once

#include <ostream>

#include "core/core.h"
#include "core/string.h"
#include "nstd/tipe_data/tipe_data.h"

namespace nstd {

  class dinamis;

  class benarsalah;

  class bilangan;

  class kalimat: public tipe_data {
    public:
      explicit kalimat(STR nilai);

      void replaceAll(const STR& from, const STR& too);

      ND STR ubahKeString() const;

      kalimat& operator+=(const STR& nilaiX);

      kalimat& operator+=(const kalimat& nilaiX);

      kalimat& operator+=(const dinamis& nilaiX);

      kalimat operator*(const bilangan& nilaiX) const;

      kalimat operator+(const kalimat& nilaiX) const;

      ND benarsalah diAwali(const char& karakter) const;

    private:
      STR nilai;

      friend STD ostream& operator<<(STD ostream& ost, const kalimat& obj) {
        ost << obj.nilai;
        return ost;
      }
  };
}  // namespace nstd
