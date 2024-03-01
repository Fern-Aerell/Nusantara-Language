#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/dinamis.h"
#include "nstd/operasi/operasi.h"
#include "core/core.h"
#include "core/error.h"

#define _KALIMAT_ERROR_DINAMIS_BUKAN_KALIMAT RTERROR("Nilai dinamis bukanlah sebuah kalimat.")

NSTD kalimat::kalimat(STR nilai): nilai(std::move(nilai)) {}

void NSTD kalimat::replaceAll(const STR& from, const STR& too) {
  size_t pos = 0;
  while((pos = this->nilai.find(from, pos)) != STR::npos) {
    this->nilai.replace(pos, from.length(), too);
    pos += too.length();
  }
}

STR NSTD kalimat::ubahKeString() const { return nilai; }

NSTD kalimat& NSTD kalimat::operator+=(const STR& nilaiX) {
  this->nilai += nilaiX;
  return *this;
}

NSTD kalimat& NSTD kalimat::operator+=(const kalimat& nilaiX) {
  this->nilai += nilaiX.nilai;
  return *this;
}


NSTD kalimat& NSTD kalimat::operator+=(const dinamis& nilaiX) {
  if(nilaiX.is_kalimat()) {
    this->nilai += nilaiX.get_kalimat();
  }
  throw _KALIMAT_ERROR_DINAMIS_BUKAN_KALIMAT;
}

ND NSTD benarsalah NSTD kalimat::diAwali(const char& karakter) const {
  return benarsalah(this->nilai[0] == karakter);
}
