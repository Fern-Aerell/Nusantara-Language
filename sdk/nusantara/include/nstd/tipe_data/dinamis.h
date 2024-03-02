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

#define __DINAMIS_CONSTRUCTOR(tipe) \
  explicit dinamis(const tipe& nilai)

#define __DINAMIS_CONSTRUCTOR_NILAI_MOVE(tipe) \
  explicit dinamis(tipe nilai)

#define __DEFINE_DINAMIS_IS_FUNCTION(tipe_data) \
   benarsalah is_##tipe_data() const

#define __DEFINE_DINAMIS_GET_FUNCTION(tipe_data) const tipe_data& get_##tipe_data() const;

namespace nstd {

  class identifikasi;

  class dinamis: public tipe_data {
    public:
      // Constructor
      dinamis();
      __DINAMIS_CONSTRUCTOR(int);
      __DINAMIS_CONSTRUCTOR(float);
      __DINAMIS_CONSTRUCTOR(double);
      __DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT);
      __DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL);
      __DINAMIS_CONSTRUCTOR(bool);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(bilangan);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(STR);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(kalimat);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(benarsalah);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(daftar);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(peta);
      __DINAMIS_CONSTRUCTOR_NILAI_MOVE(identifikasi);
      // Copy Constructor
      dinamis(const dinamis& other);

      ND bool kosong() const;

      ND bool tidakKosong() const;

      ND kalimat ubahKeKalimat() const;

      __DEFINE_DINAMIS_IS_FUNCTION(bilangan);
      __DEFINE_DINAMIS_IS_FUNCTION(kalimat);
      __DEFINE_DINAMIS_IS_FUNCTION(benarsalah);
      __DEFINE_DINAMIS_IS_FUNCTION(daftar);
      __DEFINE_DINAMIS_IS_FUNCTION(peta);

      __DEFINE_DINAMIS_GET_FUNCTION(bilangan);
      __DEFINE_DINAMIS_GET_FUNCTION(kalimat);
      __DEFINE_DINAMIS_GET_FUNCTION(benarsalah);
      __DEFINE_DINAMIS_GET_FUNCTION(daftar);
      __DEFINE_DINAMIS_GET_FUNCTION(peta);

      dinamis& operator=(const int& nilaiX);
      dinamis& operator=(const STR& nilaiX);
      dinamis& operator=(const dinamis& nilaiX);
      dinamis& operator=(const benarsalah& nilaiX);
      dinamis& operator++();
      dinamis& operator--();
      dinamis const operator++(int);
      dinamis const operator--(int);
      benarsalah operator!() const;
      dinamis operator~();
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, +, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, -, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, *, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, /, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, %, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, ==, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, !=, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, >, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, <, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, >=, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, <=, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, &&, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, ||, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, &, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, |, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, ^, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, <<, dinamis);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT(dinamis, >>, dinamis);

    private:
      PTR(tipe_data) nilai;

      friend std::ostream& operator<<(std::ostream& ost, const dinamis& obj) {
        return ost << obj.ubahKeKalimat();
      }
  };
}  // namespace nstd
