#include "nstd/tipe_data/daftar.h"

#include <memory>
#include <sstream>
#include <vector>

#include "core/core.h"
#include "nstd/operasi/operasi.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

NSTD daftar::daftar(std::vector<std::unique_ptr<tipe_data>> nilai):
    nilai(std::move(nilai)) {}

ND bool NSTD daftar::berisi(const std::unique_ptr<tipe_data>& nilai) const {
  return std::find(this->nilai.begin(), this->nilai.end(), nilai) !=
         this->nilai.end();
}

ND bool NSTD daftar::kosong() const { return this->nilai.empty(); }

ND bool NSTD daftar::tidakKosong() const { return !this->kosong(); }

ND NSTD bilangan NSTD daftar::jumlahIsi() const {
  return bilangan(static_cast<TIPE_DATA_BILANGAN_BULAT>(this->nilai.size()));
}

ND NSTD kalimat NSTD daftar::ubahKeKalimat() const {
  std::ostringstream stream;
  int index = 0;
  for(const std::unique_ptr<tipe_data>& child : this->nilai) {
    if(index == 0) { stream << "["; }
    stream << child;
    if(index < (this->jumlahIsi() - 1)) {
      stream << ", ";
    } else {
      stream << "]";
    }
    ++index;
  }
  return kalimat(stream.str());
}
