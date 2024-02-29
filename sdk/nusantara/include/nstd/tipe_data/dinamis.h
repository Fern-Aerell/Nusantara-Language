#pragma once

#include "core/core.h"
#include "core/pointer.h"
#include "core/string.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"

#define __DINAMIS_CONSTRUCTOR(tipe, tipe_data) \
  explicit dinamis(const tipe& nilai)
#define __DINAMIS_CONSTRUCTOR_NILAI_MOVE(tipe, tipe_data) \
  explicit dinamis(tipe nilai)

#define __DEFINE_DINAMIS_IS_FUNCTION(tipe_data) \
  ND benarsalah is_##tipe_data() const

#define __DEFINE_DINAMIS_AS_FUNCTION(tipe_data) ND tipe_data& as_##tipe_data();

namespace nstd {

  class dinamis {
    public:
      // Constructor
      dinamis();
      __DINAMIS_CONSTRUCTOR(int, bilangan);
      __DINAMIS_CONSTRUCTOR(float, bilangan);
      __DINAMIS_CONSTRUCTOR(double, bilangan);
      __DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT, bilangan);
      __DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL, bilangan);
      __DINAMIS_CONSTRUCTOR(bool, benarsalah);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(STR, kalimat);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(kalimat, kalimat);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(bilangan, bilangan);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(benarsalah, benarsalah);
      explicit dinamis(PTR(tipe_data) nilai);

      ND bool kosong() const;

      ND bool tidakKosong() const;

      ND kalimat ubahKeKalimat() const;

      __DEFINE_DINAMIS_IS_FUNCTION(bilangan);
      __DEFINE_DINAMIS_IS_FUNCTION(kalimat);
      __DEFINE_DINAMIS_IS_FUNCTION(benarsalah);
      __DEFINE_DINAMIS_IS_FUNCTION(daftar);
      __DEFINE_DINAMIS_IS_FUNCTION(peta);

      __DEFINE_DINAMIS_AS_FUNCTION(bilangan);
      __DEFINE_DINAMIS_AS_FUNCTION(kalimat);
      __DEFINE_DINAMIS_AS_FUNCTION(benarsalah);
      __DEFINE_DINAMIS_AS_FUNCTION(daftar);
      __DEFINE_DINAMIS_AS_FUNCTION(peta);

      dinamis& operator=(const int& nilaiX);

      dinamis& operator=(const STR& nilaiX);

    private:
      SPTR(tipe_data) nilai;

      friend std::ostream& operator<<(std::ostream& ost, const dinamis& obj) {
        return ost << obj.ubahKeKalimat();
      }
  };
}  // namespace nstd
