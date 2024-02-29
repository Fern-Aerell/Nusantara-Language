#include "nstd/tipe_data/kalimat.h"

#include "core/core.h"

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
