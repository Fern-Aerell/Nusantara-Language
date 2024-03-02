#include "nstd/tipe_data/daftar.h"

#include <sstream>
#include <vector>
#include <algorithm>

#include "core/core.h"
#include "core/error.h"
#include "core/pointer.h"
#include "nstd/operasi/operasi.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"
#include "nstd/tipe_data/dinamis.h"

#define _DAFTAR_ERROR_TIPE_DATA RTERROR("Daftar tidak mendukung tipe data yang diberikan.")

#define _DEFINE_DAFTAR_TAMBAH_FUNCTION(tipe) void NSTD daftar::tambah(const tipe& nilai) {\
  this->nilai.push_back(MPTR(tipe, nilai));\
}

// Constructors
NSTD daftar::daftar(STD vector<PTR(tipe_data)> nilai):
    nilai(STD move(nilai)) {}

// Copy constructor
NSTD daftar::daftar(const daftar& nilai) {
  for(const auto& elem : nilai.nilai) {
    if(PTR_CAST(elem, bilangan)) {
      this->tambah(*cast_result_ptr);
    } else if(PTR_CAST(elem, kalimat)) {
      this->tambah(*cast_result_ptr);
    } else if(PTR_CAST(elem, benarsalah)) {
      this->tambah(*cast_result_ptr);
    } else if(PTR_CAST(elem, daftar)) {
      this->tambah(*cast_result_ptr);
    } else if(PTR_CAST(elem, peta)) {
      this->tambah(*cast_result_ptr);
    } else if(PTR_CAST(elem, dinamis)) {
      this->tambah(*cast_result_ptr);
    }
    throw _DAFTAR_ERROR_TIPE_DATA;
  }
}

// Move constructor
NSTD daftar::daftar(daftar&& other) noexcept: nilai(STD move(other.nilai)) {}

_DEFINE_DAFTAR_TAMBAH_FUNCTION(bilangan)
_DEFINE_DAFTAR_TAMBAH_FUNCTION(kalimat)
_DEFINE_DAFTAR_TAMBAH_FUNCTION(benarsalah)
_DEFINE_DAFTAR_TAMBAH_FUNCTION(daftar)
_DEFINE_DAFTAR_TAMBAH_FUNCTION(peta)

void NSTD daftar::tambah(const dinamis& nilai) {
  if(nilai.is_bilangan()) {
    this->tambah(nilai.get_bilangan());
  }else if(nilai.is_kalimat()) {
    this->tambah(nilai.get_kalimat());
  }else if(nilai.is_benarsalah()) {
    this->tambah(nilai.get_benarsalah());
  }else if(nilai.is_daftar()) {
    this->tambah(nilai.get_daftar());
  }else if(nilai.is_peta()) {
    this->tambah(nilai.get_peta());
  }
  throw _DAFTAR_ERROR_TIPE_DATA;
}

ND bool NSTD daftar::berisi(const PTR(tipe_data)& nilai) const {
  return STD find(this->nilai.begin(), this->nilai.end(), nilai) !=
         this->nilai.end();
}

ND bool NSTD daftar::kosong() const { return this->nilai.empty(); }

ND bool NSTD daftar::tidakKosong() const { return !this->kosong(); }

ND NSTD bilangan NSTD daftar::jumlahIsi() const {
  return bilangan(static_cast<TIPE_DATA_BILANGAN_BULAT>(this->nilai.size()));
}

ND NSTD kalimat NSTD daftar::ubahKeKalimat() const {
  STD ostringstream stream;
  int index = 0;
  for(const PTR(tipe_data)& child : this->nilai) {
    if(index == 0) { stream << "["; }
    if(PTR_CAST(child, bilangan)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(child, kalimat)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(child, benarsalah)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(child, daftar)) {
      stream << *cast_result_ptr;
    }else if(PTR_CAST(child, peta)) {
      stream << *cast_result_ptr;
    }
    if(index < (this->jumlahIsi() - 1)) {
      stream << ", ";
    } else {
      stream << "]";
    }
    ++index;
  }
  if(index == 0) {
    stream << "[]";
  }
  return kalimat(stream.str());
}
