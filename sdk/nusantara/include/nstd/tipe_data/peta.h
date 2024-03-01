#pragma once

#include <map>

#include "core/core.h"
#include "core/pointer.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define __DECLARE_PETA_TAMBAH_FUNCTION(tipe_key, tipe_value) void tambah(const tipe_key& key, const tipe_value& value)

namespace nstd {

  class bilangan;
  class kalimat;
  class benarsalah;
  class daftar;
  class dinamis;

  class peta: public tipe_data {
    public:
      // Constructors
      explicit peta(STD map<PTR(tipe_data), PTR(tipe_data)> nilai);
      // Copy constructor
      peta(const peta& nilai);

      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(bilangan, dinamis);

      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(kalimat, dinamis);

      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(benarsalah, dinamis);

      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(daftar, dinamis);

      __DECLARE_PETA_TAMBAH_FUNCTION(peta, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(peta, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(peta, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(peta, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(peta, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(peta, dinamis);

      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, bilangan);
      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, kalimat);
      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, benarsalah);
      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, daftar);
      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, peta);
      __DECLARE_PETA_TAMBAH_FUNCTION(dinamis, dinamis);

      ND benarsalah berisiKunci(const PTR(tipe_data) & key) const;

      ND benarsalah kosong() const;

      ND benarsalah tidakKosong() const;

      ND bilangan jumlahIsi() const;

      ND kalimat ubahKeKalimat() const;

    private:
      STD map<PTR(tipe_data), PTR(tipe_data)> nilai;

      friend STD ostream& operator<<(STD ostream& ost, const peta& obj) {
        ost << obj.ubahKeKalimat();
        return ost;
      }
  };

}  // namespace nstd
