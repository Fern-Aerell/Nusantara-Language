#include "nstd/tipe_data/benarsalah.h"

#include <regex>

#include "core/core.h"
#include "core/error.h"
#include "nstd/tipe_data/kalimat.h"

#define _BENARSALAH_ERROR_INVALID_VALUE \
  RTERROR("nilai benar atau salah tidak valid.")

NSTD benarsalah::benarsalah(const bool& nilai): nilai(nilai) {}

ND NSTD kalimat NSTD benarsalah::ubahKeKalimat() const {
  return kalimat(this->nilai ? "benar" : "salah");
}

NSTD benarsalah NSTD benarsalah::ubah(const NSTD kalimat& nilai) {
  const STD regex pattern("^(benar|salah)$");
  const STD string str = nilai.ubahKeString();
  if(STD regex_match(str, pattern)) { return benarsalah(str == "benar"); }
  throw _BENARSALAH_ERROR_INVALID_VALUE;
}

NSTD benarsalah::operator bool() const { return this->nilai; }

NSTD benarsalah NSTD benarsalah::operator!() const {
  return benarsalah(!this->nilai);
}
