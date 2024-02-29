#include "nstd/tipe_data/dinamis.h"

#include <memory>

#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "core/pointer.h"
#include "core/string.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"

#define _DINAMIS_CONSTRUCTOR(tipe, tipe_data) \
  NSTD dinamis::dinamis(const tipe& nilai): nilai(MSPTR(tipe_data, nilai)) {}
#define _DINAMIS_CONSTRUCTOR_NILAI_MOVE(tipe, tipe_data) \
  NSTD dinamis::dinamis(tipe nilai): nilai(MSPTR(tipe_data, STD move(nilai))) {}

#define _DINAMIS_VALUE this->nilai

#define _DEFINE_DINAMIS_IS_FUNCTION(tipe_data)                \
  ND NSTD benarsalah NSTD dinamis::is_##tipe_data() const {   \
    if(PTR_CAST(_DINAMIS_VALUE, tipe_data)) { return BENAR; } \
    return SALAH;                                             \
  }

#define _DINAMIS_ERROR_INVALID_VALUE RTERROR("Nilai dinamis tidak valid.")

#define _DINAMIS_AS_ERROR(as) \
  RTERROR(FMT("Nilai dinamis bukanlah sebuah {}.", as))

#define _DINAMIS_AS_ERROR_TIPE_CHECK(tipe_var, tipe_name, as_msg) \
  if(tipe_var == tipe_name) { throw _DINAMIS_AS_ERROR(as_msg); }

#define _DEFINE_DINAMIS_AS_FUNCTION(tipe_data)                                \
  ND NSTD tipe_data& NSTD dinamis::as_##tipe_data() {                         \
    if(this->is_##tipe_data()) {                                              \
      if(PTR_CAST(_DINAMIS_VALUE, tipe_data)) { return *cast_result_ptr; }    \
    }                                                                         \
    STR tipe_name(typeid(tipe_data).name());                                  \
    _DINAMIS_AS_ERROR_TIPE_CHECK(                                             \
        tipe_name, "class nstd::bilangan", "bilangan"                         \
    )                                                                         \
    _DINAMIS_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::kalimat", "kalimat") \
    _DINAMIS_AS_ERROR_TIPE_CHECK(                                             \
        tipe_name, "class nstd::benarsalah", "benar atau salah"               \
    )                                                                         \
    _DINAMIS_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::daftar", "daftar")   \
    _DINAMIS_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::peta", "peta")       \
    throw _DINAMIS_ERROR_INVALID_VALUE;                                       \
  }

NSTD dinamis::dinamis(): nilai(nullptr) {}
_DINAMIS_CONSTRUCTOR(int, bilangan)
_DINAMIS_CONSTRUCTOR(float, bilangan)
_DINAMIS_CONSTRUCTOR(double, bilangan)
_DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT, bilangan)
_DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL, bilangan)
_DINAMIS_CONSTRUCTOR(bool, benarsalah)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(STR, kalimat)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(kalimat, kalimat)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(bilangan, bilangan)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(benarsalah, benarsalah)

NSTD dinamis::dinamis(PTR(tipe_data) nilai): nilai(std::move(nilai)) {}

ND bool NSTD dinamis::kosong() const { return _DINAMIS_VALUE == nullptr; }

ND bool NSTD dinamis::tidakKosong() const { return !this->kosong(); }

ND NSTD kalimat NSTD dinamis::ubahKeKalimat() const {
  if(PTR_CAST(_DINAMIS_VALUE, bilangan)) {
    return cast_result_ptr->ubahKeKalimat();
  } else if(PTR_CAST(_DINAMIS_VALUE, kalimat)) {
    return *cast_result_ptr;
  } else if(PTR_CAST(_DINAMIS_VALUE, benarsalah)) {
    return cast_result_ptr->ubahKeKalimat();
  } else if(PTR_CAST(_DINAMIS_VALUE, daftar)) {
    return cast_result_ptr->ubahKeKalimat();
  } else if(PTR_CAST(_DINAMIS_VALUE, peta)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  throw _DINAMIS_ERROR_INVALID_VALUE;
}

_DEFINE_DINAMIS_IS_FUNCTION(bilangan);
_DEFINE_DINAMIS_IS_FUNCTION(kalimat);
_DEFINE_DINAMIS_IS_FUNCTION(benarsalah);
_DEFINE_DINAMIS_IS_FUNCTION(daftar);
_DEFINE_DINAMIS_IS_FUNCTION(peta);
_DEFINE_DINAMIS_AS_FUNCTION(bilangan);
_DEFINE_DINAMIS_AS_FUNCTION(kalimat);
_DEFINE_DINAMIS_AS_FUNCTION(benarsalah);
_DEFINE_DINAMIS_AS_FUNCTION(daftar);
_DEFINE_DINAMIS_AS_FUNCTION(peta);

NSTD dinamis& NSTD dinamis::operator=(const int& nilaiX) {
  this->nilai = MSPTR(bilangan, nilaiX);
  return *this;
}

NSTD dinamis& NSTD dinamis::operator=(const STR& nilaiX) {
  this->nilai = MSPTR(kalimat, nilaiX);
  return *this;
}
