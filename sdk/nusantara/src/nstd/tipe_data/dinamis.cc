#include "nstd/tipe_data/dinamis.h"

#include <memory>

#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "core/pointer.h"
#include "core/string.h"
#include "nstd/operasi/operasi.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/bilangan.h"

#define _DINAMIS_CONSTRUCTOR(tipe, tipe_data) \
  NSTD dinamis::dinamis(const tipe& nilai): nilai(MPTR(tipe_data, nilai)) {}
#define _DINAMIS_CONSTRUCTOR_NILAI_MOVE(tipe, tipe_data) \
  NSTD dinamis::dinamis(tipe nilai): nilai(MPTR(tipe_data, STD move(nilai))) {}

#define _DINAMIS_VALUE this->nilai

#define _DEFINE_DINAMIS_IS_FUNCTION(tipe_data)                \
 NSTD benarsalah NSTD dinamis::is_##tipe_data() const {   \
    if(PTR_CAST(_DINAMIS_VALUE, tipe_data)) { return BENAR; } \
    return SALAH;                                             \
  }

#define _DINAMIS_ERROR_INVALID_VALUE RTERROR("Nilai dinamis tidak valid.")

#define _DINAMIS_AS_ERROR(as) \
  RTERROR(FMT("Nilai dinamis bukanlah sebuah {}.", as))

#define _DINAMIS_AS_ERROR_TIPE_CHECK(tipe_var, tipe_name, as_msg) \
  if(tipe_var == tipe_name) { throw _DINAMIS_AS_ERROR(as_msg); }

#define _DEFINE_DINAMIS_GET_FUNCTION(tipe_data)                                \
  const NSTD tipe_data& NSTD dinamis::get_##tipe_data() const {                         \
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

#define _DINAMIS_ERROR_OPERASI_TIDAK_VALID(operasi_name) RTERROR(FMT("Operasi {} tidak valid.", operasi_name))

// Constructor
NSTD dinamis::dinamis(): nilai(nullptr) {}
_DINAMIS_CONSTRUCTOR(int, bilangan)
_DINAMIS_CONSTRUCTOR(float, bilangan)
_DINAMIS_CONSTRUCTOR(double, bilangan)
_DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT, bilangan)
_DINAMIS_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL, bilangan)
_DINAMIS_CONSTRUCTOR(bool, benarsalah)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(bilangan, bilangan)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(STR, kalimat)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(kalimat, kalimat)
_DINAMIS_CONSTRUCTOR_NILAI_MOVE(benarsalah, benarsalah)
// Copy constructors
NSTD dinamis::dinamis(const dinamis& other) {
  if(other.is_bilangan()) {
    this->nilai = MPTR(bilangan, other.get_bilangan());
  }else if(other.is_kalimat()) {
    this->nilai = MPTR(kalimat, other.get_kalimat());
  }else if(other.is_benarsalah()) {
    this->nilai = MPTR(benarsalah, other.get_benarsalah());
  }else if(other.is_daftar()) {
    this->nilai = MPTR(daftar, other.get_daftar());
  }else if(other.is_peta()) {
    this->nilai = MPTR(peta, other.get_peta());
  }else{
    throw _DINAMIS_ERROR_INVALID_VALUE;
  }
}

ND bool NSTD dinamis::kosong() const { return _DINAMIS_VALUE == nullptr; }

ND bool NSTD dinamis::tidakKosong() const { return !this->kosong(); }

ND NSTD kalimat NSTD dinamis::ubahKeKalimat() const {
  if(PTR_CAST(_DINAMIS_VALUE, bilangan)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  if(PTR_CAST(_DINAMIS_VALUE, kalimat)) {
    return *cast_result_ptr;
  }
  if(PTR_CAST(_DINAMIS_VALUE, benarsalah)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  if(PTR_CAST(_DINAMIS_VALUE, daftar)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  if(PTR_CAST(_DINAMIS_VALUE, peta)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  throw _DINAMIS_ERROR_INVALID_VALUE;
}

_DEFINE_DINAMIS_IS_FUNCTION(bilangan);
_DEFINE_DINAMIS_IS_FUNCTION(kalimat);
_DEFINE_DINAMIS_IS_FUNCTION(benarsalah);
_DEFINE_DINAMIS_IS_FUNCTION(daftar);
_DEFINE_DINAMIS_IS_FUNCTION(peta);

_DEFINE_DINAMIS_GET_FUNCTION(bilangan);
_DEFINE_DINAMIS_GET_FUNCTION(kalimat);
_DEFINE_DINAMIS_GET_FUNCTION(benarsalah);
_DEFINE_DINAMIS_GET_FUNCTION(daftar);
_DEFINE_DINAMIS_GET_FUNCTION(peta);

NSTD dinamis& NSTD dinamis::operator=(const int& nilaiX) {
  this->nilai = MPTR(bilangan, nilaiX);
  return *this;
}

NSTD dinamis& NSTD dinamis::operator=(const STR& nilaiX) {
  this->nilai = MPTR(kalimat, nilaiX);
  return *this;
}

NSTD dinamis& NSTD dinamis::operator=(const dinamis& nilaiX) {
  if(this == &nilaiX) {return *this;}
  if(nilaiX.is_bilangan()) {
    this->nilai = MPTR(bilangan, nilaiX.get_bilangan());
  }else if(nilaiX.is_kalimat()) {
    this->nilai = MPTR(kalimat, nilaiX.get_kalimat());
  }else if(nilaiX.is_benarsalah()) {
    this->nilai = MPTR(benarsalah, nilaiX.get_benarsalah());
  }else if(nilaiX.is_daftar()) {
    this->nilai = MPTR(daftar, nilaiX.get_daftar());
  }else if(nilaiX.is_peta()) {
    this->nilai = MPTR(peta, nilaiX.get_peta());
  }else{
    throw _DINAMIS_ERROR_INVALID_VALUE;
  }
  return *this;
}

NSTD dinamis& NSTD dinamis::operator++() {
  if(this->is_bilangan()) {
    this->nilai = MPTR(bilangan, 1 + this->get_bilangan());
    return *this;
  }
  throw _DINAMIS_AS_ERROR("bilangan");
}

NSTD dinamis const NSTD dinamis::operator++(int) {
  if(this->is_bilangan()) {
    dinamis temp = *this;
    this->nilai = MPTR(bilangan, 1 + this->get_bilangan());
    return temp;
  }
  throw _DINAMIS_AS_ERROR("bilangan");
}

NSTD dinamis& NSTD dinamis::operator--() {
  if(this->is_bilangan()) {
    this->nilai = MPTR(bilangan, 1 - this->get_bilangan());
    return *this;
  }
  throw _DINAMIS_AS_ERROR("bilangan");
}

NSTD dinamis const NSTD dinamis::operator--(int) {
  if(this->is_bilangan()) {
    dinamis temp = *this;
    this->nilai = MPTR(bilangan, 1 - this->get_bilangan());
    return temp;
  }
  throw _DINAMIS_AS_ERROR("bilangan");
}

NSTD benarsalah NSTD dinamis::operator!() const {
  if(this->is_benarsalah()) {
    return !this->get_benarsalah();
  }
  throw _DINAMIS_AS_ERROR("benar atau salah");
}

NSTD dinamis NSTD dinamis::operator~() {
  if(this->is_bilangan()) {
    dinamis temp = *this;
    temp.nilai = MPTR(bilangan, ~temp.get_bilangan());
    return temp;
  }
  throw _DINAMIS_AS_ERROR("bilangan bulat");
}

NSTD dinamis NSTD dinamis::operator+(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() + nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("penjumlahan");
}

NSTD dinamis NSTD dinamis::operator-(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() - nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("pengurangan");
}

NSTD dinamis NSTD dinamis::operator*(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() * nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("perkalian");
}

NSTD dinamis NSTD dinamis::operator/(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() / nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("pembagian");
}

NSTD dinamis NSTD dinamis::operator%(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() % nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("sisa pembagian");
}

NSTD dinamis NSTD dinamis::operator==(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() == nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("persamaan");
}

NSTD dinamis NSTD dinamis::operator!=(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() != nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("pertidaksamaan");
}

NSTD dinamis NSTD dinamis::operator>(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() > nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("lebih besar dari");
}

NSTD dinamis NSTD dinamis::operator<(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() < nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("lebih kecil dari");
}

NSTD dinamis NSTD dinamis::operator>=(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() >= nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("lebih besar dari sama dengan");
}

NSTD dinamis NSTD dinamis::operator<=(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() <= nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("lebih kecil dari sama dengan");
}

NSTD dinamis NSTD dinamis::operator&&(const dinamis& nilaiX) const {
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("dan");
}

NSTD dinamis NSTD dinamis::operator||(const dinamis& nilaiX) const {
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("atau");
}

NSTD dinamis NSTD dinamis::operator&(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() & nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("and bit");
}

NSTD dinamis NSTD dinamis::operator|(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() | nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("or bit");
}

NSTD dinamis NSTD dinamis::operator^(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() ^ nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("xor bit");
}

NSTD dinamis NSTD dinamis::operator<<(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() << nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("geser kiri bit");
}

NSTD dinamis NSTD dinamis::operator>>(const dinamis& nilaiX) const {
  if(this->is_bilangan() && nilaiX.is_bilangan()) {
    return dinamis(this->get_bilangan() >> nilaiX.get_bilangan());
  }
  throw _DINAMIS_ERROR_OPERASI_TIDAK_VALID("geser kanan bit");
}
