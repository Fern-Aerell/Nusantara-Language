#pragma once

#include <vector>

#include "core/core.h"
#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"

#define __DECLARE_DAFTAR_TAMBAH_FUNCTION(tipe) void tambah(const tipe& nilai)

namespace nstd {

  class daftar: public tipe_data {
    public:
      // Constructors
      explicit daftar(STD vector<PTR(tipe_data)> nilai);
      // Copy constructor
      daftar(const daftar& nilai);
      // Move constructor
      daftar(daftar&& other) noexcept;

      ND bool berisi(const PTR(tipe_data)& nilai) const;

      ND bool kosong() const;

      ND bool tidakKosong() const;

      ND bilangan jumlahIsi() const;

      ND kalimat ubahKeKalimat() const;

      __DECLARE_DAFTAR_TAMBAH_FUNCTION(bilangan);
      __DECLARE_DAFTAR_TAMBAH_FUNCTION(kalimat);
      __DECLARE_DAFTAR_TAMBAH_FUNCTION(benarsalah);
      __DECLARE_DAFTAR_TAMBAH_FUNCTION(daftar);
      __DECLARE_DAFTAR_TAMBAH_FUNCTION(peta);
      __DECLARE_DAFTAR_TAMBAH_FUNCTION(dinamis);

    private:
      STD vector<PTR(tipe_data)> nilai;

      friend STD ostream& operator<<(STD ostream& ost, const daftar& obj) {
        return ost << obj.ubahKeKalimat();
      }
  };

}  // namespace nstd
