#include "nstd/tipe_data/peta.h"

#include <sstream>

#include "core/core.h"
#include "core/error.h"
#include "core/pointer.h"
#include "nstd/operasi/operasi.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/dinamis.h"

#define _PETA_ERROR_INVALID_KEY RTERROR("Peta tidak mendukung nilai kata kunci yang diberikan.")
#define _PETA_ERROR_INVALID_VALUE RTERROR("Peta tidak mendukung nilai yang diberikan.")
#define _PETA_ERROR_INVALID_KEY_OR_VALUE RTERROR("Peta tidak mendukung nilai atau kata kunci yang diberikan.")

#define _DEFINE_PETA_TAMBAH_FUNCTION(tipe_key, tipe_value) void NSTD peta::tambah(const tipe_key& key, const tipe_value& value) {\
  this->nilai[MPTR(tipe_key, key)] = MPTR(tipe_value, value);\
}

#define _PETA_COPY_CONSTRUCTOR_IF(tipe_data_key, tipe_data_value) if(PTR_CAST(key, tipe_data_key)) {\
      auto keyy = *cast_result_ptr;\
      if(PTR_CAST(value, tipe_data_value)) {\
        auto valuee = *cast_result_ptr;\
        this->tambah(keyy, valuee);\
      }\
    }

// Constructors
NSTD peta::peta(STD map<PTR(tipe_data), PTR(tipe_data)> nilai):
    nilai(STD move(nilai)) {}

// Copy constructor
NSTD peta::peta(const peta& nilai) {
  for (const auto& [key, value] : nilai.nilai) {
    _PETA_COPY_CONSTRUCTOR_IF(bilangan, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(bilangan, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(bilangan, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(bilangan, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(bilangan, peta)
		else _PETA_COPY_CONSTRUCTOR_IF(bilangan, dinamis)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, peta)
    else _PETA_COPY_CONSTRUCTOR_IF(kalimat, dinamis)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, peta)
    else _PETA_COPY_CONSTRUCTOR_IF(benarsalah, dinamis)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, peta)
    else _PETA_COPY_CONSTRUCTOR_IF(daftar, dinamis)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, peta)
    else _PETA_COPY_CONSTRUCTOR_IF(peta, dinamis)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, bilangan)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, kalimat)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, benarsalah)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, daftar)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, peta)
    else _PETA_COPY_CONSTRUCTOR_IF(dinamis, dinamis)

    else {throw _PETA_ERROR_INVALID_KEY_OR_VALUE;}
  }
}

// Move constructor
NSTD peta::peta(peta&& other) noexcept: nilai(STD move(other.nilai)) {}

NSTD benarsalah NSTD peta::berisiKunci(const PTR(tipe_data) & key) const {
  auto value = this->nilai.find(key);
  return static_cast<benarsalah>(value != this->nilai.end());
}

NSTD benarsalah NSTD peta::kosong() const {
  return benarsalah(this->nilai.empty());
}

NSTD benarsalah NSTD peta::tidakKosong() const {
  return benarsalah(!this->kosong());
}

NSTD bilangan NSTD peta::jumlahIsi() const {
  return bilangan(static_cast<TIPE_DATA_BILANGAN_BULAT>(this->nilai.size()));
}

NSTD kalimat NSTD peta::ubahKeKalimat() const {
  STD ostringstream stream;
  int index = 0;
  for(const auto& [key, value] : this->nilai) {
    if(index == 0) { stream << "{"; }
    if(PTR_CAST(key, bilangan)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(key, kalimat)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(key, benarsalah)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(key, daftar)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(key, peta)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(key, dinamis)) {
      stream << *cast_result_ptr;
    }
    stream << ": ";
    if(PTR_CAST(value, bilangan)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(value, kalimat)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(value, benarsalah)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(value, daftar)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(value, peta)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(value, dinamis)) {
      stream << *cast_result_ptr;
    }
    if(index < (this->jumlahIsi() - 1)) {
      stream << ", ";
    } else {
      stream << "}";
    }
    ++index;
  }
  if(index == 0) {
    stream << "{}";
  }
  return kalimat(stream.str());
}

_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(bilangan, dinamis);

_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(kalimat, dinamis);

_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(benarsalah, dinamis);

_DEFINE_PETA_TAMBAH_FUNCTION(daftar, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(daftar, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(daftar, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(daftar, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(daftar, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(daftar, dinamis);

_DEFINE_PETA_TAMBAH_FUNCTION(peta, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(peta, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(peta, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(peta, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(peta, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(peta, dinamis);

_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, bilangan);
_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, kalimat);
_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, benarsalah);
_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, daftar);
_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, peta);
_DEFINE_PETA_TAMBAH_FUNCTION(dinamis, dinamis);
