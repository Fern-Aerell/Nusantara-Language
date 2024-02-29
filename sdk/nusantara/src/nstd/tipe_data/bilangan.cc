#include "nstd/tipe_data/bilangan.h"

#include <memory>
#include <regex>
#include <string>

#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/kalimat.h"

#define TIPE_DATA_BILANGAN_BULAT long long int
#define TIPE_DATA_BILANGAN_DESIMAL long double

// BILANGAN BULAT MACRO
#define _BILANGAN_BULAT_PATTERN "^-?[0-9]+$"
#define _BILANGAN_BULAT_CONSTRUCTOR(type) \
  NSTD _bilangan_bulat::_bilangan_bulat(const type& nilai): nilai(nilai) {}

// BILANGAN DESIMAL MACRO
#define _BILANGAN_DESIMAL_PATTERN "^-?[0-9]+,[0-9]+$"
#define _BILANGAN_DESIMAL_CONSTRUCTOR(type) \
  NSTD _bilangan_desimal::_bilangan_desimal(const type& nilai): nilai(nilai) {}

// BILANGAN MACRO
#define _BILANGAN_VALUE this->nilai
#define _BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(type) \
  NSTD bilangan::bilangan(const type& nilai):      \
      nilai(MPTR(__BILANGAN_BULAT, nilai)) {}
#define _BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(type) \
  NSTD bilangan::bilangan(const type& nilai):        \
      nilai(MPTR(__BILANGAN_DESIMAL, nilai)) {}

#define _BILANGAN_ERROR_INVALID_CAST(tipe) \
  RTERROR(FMT("Nilai bilangan bukanlah bilangan {}.", tipe))
#define _BILANGAN_ERROR_INVALID_CAST_BULAT _BILANGAN_ERROR_INVALID_CAST("bulat")
#define _BILANGAN_ERROR_INVALID_CAST_DESIMAL \
  _BILANGAN_ERROR_INVALID_CAST("desimal")
#define _BILANGAN_ERROR_INVALID_VALUE RTERROR("Nilai bilangan tidak valid.")
#define _BILANGAN_ERROR_KALIMAT_INVALID_VALUE \
  RTERROR("Nilai kalimat bukanlah nilai bilangan yang valid.")

#define _DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, nilai_bilangan) \
  NSTD __BILANGAN& NSTD bilangan::operator=(const tipe& nilaiX) {       \
    this->nilai = MPTR(nilai_bilangan, nilaiX);                         \
    return *this;                                                       \
  }

#define _DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(tipe) \
  _DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, __BILANGAN_BULAT)
#define _DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(tipe) \
  _DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, __BILANGAN_DESIMAL)

_BILANGAN_BULAT_CONSTRUCTOR(int)
_BILANGAN_BULAT_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT)

const TIPE_DATA_BILANGAN_BULAT& NSTD _bilangan_bulat::ambilNilai() const {
  return this->nilai;
}

NSTD kalimat NSTD _bilangan_bulat::ubahKeKalimat() const {
  return kalimat(STD to_string(this->nilai));
}

NSTD _bilangan_bulat NSTD _bilangan_bulat::operator-(const int& nilaiX) const {
  return _bilangan_bulat(this->nilai - nilaiX);
}

_BILANGAN_DESIMAL_CONSTRUCTOR(float)
_BILANGAN_DESIMAL_CONSTRUCTOR(double)
_BILANGAN_DESIMAL_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL)

const TIPE_DATA_BILANGAN_DESIMAL& NSTD _bilangan_desimal::ambilNilai() const {
  return this->nilai;
}

NSTD kalimat NSTD _bilangan_desimal::ubahKeKalimat() const {
  STD string str = STD to_string(this->nilai);
  size_t pos = str.find('.');
  if(pos != STD string::npos) {
    size_t end = str.find_last_not_of('0');
    if(end == pos) {
      str.erase(pos);  // Hapus koma
    } else if(end != STD string::npos && end > pos) {
      str.erase(end + 1);
    }
  }
  STD replace(str.begin(), str.end(), '.', ',');
  return kalimat(str);
}

NSTD _bilangan_desimal NSTD _bilangan_desimal::operator-(const int& nilaiX
) const {
  return _bilangan_desimal(this->nilai - nilaiX);
}

_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(int)
_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT)
_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(_bilangan_bulat)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(float)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(double)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(_bilangan_desimal)

const NSTD _bilangan_bulat& NSTD bilangan::ambilNilaiBulat() const {
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_bulat)) { return *cast_result_ptr; }
  throw _BILANGAN_ERROR_INVALID_CAST_BULAT;
}

const NSTD _bilangan_desimal& NSTD bilangan::ambilNilaiDesimal() const {
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_desimal)) { return *cast_result_ptr; }
  throw _BILANGAN_ERROR_INVALID_CAST_DESIMAL;
}

NSTD benarsalah NSTD bilangan::isBulat() const {
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_bulat)) { return BENAR; }
  return SALAH;
}

NSTD benarsalah NSTD bilangan::isDesimal() const {
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_desimal)) { return BENAR; }
  return SALAH;
}

NSTD kalimat NSTD bilangan::ubahKeKalimat() const {
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_bulat)) {
    return cast_result_ptr->ubahKeKalimat();
  } else if(PTR_CAST(_BILANGAN_VALUE, _bilangan_desimal)) {
    return cast_result_ptr->ubahKeKalimat();
  }
  throw _BILANGAN_ERROR_INVALID_VALUE;
}

NSTD bilangan NSTD bilangan::ubah(const kalimat& nilai) {
  const STD regex patternBulat(_BILANGAN_BULAT_PATTERN);
  const STD regex patternDesimal(_BILANGAN_DESIMAL_PATTERN);
  const STD string str = nilai.ubahKeString();
  if(STD regex_match(str, patternBulat)) {
    return bilangan(STD stoll(str));
  } else if(STD regex_match(str, patternDesimal)) {
    return bilangan(STD stold(str));
  }
  throw _BILANGAN_ERROR_KALIMAT_INVALID_VALUE;
}

_DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(int);
_DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(TIPE_DATA_BILANGAN_BULAT);
_DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(float);
_DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(double);
_DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(TIPE_DATA_BILANGAN_DESIMAL);

NSTD bilangan NSTD bilangan::operator-(const int& nilaiX) const {
  if(isBulat()) { return bilangan(this->ambilNilaiBulat() - nilaiX); }
  if(isDesimal()) { return bilangan(this->ambilNilaiDesimal() - nilaiX); }
  throw _BILANGAN_ERROR_INVALID_VALUE;
}

void NSTD bilangan::setBulat(const TIPE_DATA_BILANGAN_BULAT& nilai) {
  this->nilai = STD make_unique<_bilangan_bulat>(nilai);
}

void NSTD bilangan::setDesimal(const TIPE_DATA_BILANGAN_DESIMAL& nilai) {
  this->nilai = STD make_unique<_bilangan_desimal>(nilai);
}
