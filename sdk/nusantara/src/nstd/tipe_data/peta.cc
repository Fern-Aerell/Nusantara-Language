#include "nstd/tipe_data/peta.h"

#include <sstream>

#include "nstd/operasi/operasi.h"

NSTD peta::peta(STD map<PTR(tipe_data), PTR(tipe_data)> nilai):
    nilai(STD move(nilai)) {}

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
  for(const auto& pair : this->nilai) {
    if(index == 0) { stream << "{"; }
    stream << pair.first << ": " << pair.second;
    if(index < (this->jumlahIsi() - 1)) {
      stream << ", ";
    } else {
      stream << "]";
    }
    ++index;
  }
  return kalimat(stream.str());
}
