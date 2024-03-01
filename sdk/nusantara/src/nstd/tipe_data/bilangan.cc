#include "nstd/tipe_data/bilangan.h"

#include <cmath>
#include <memory>
#include <regex>
#include <string>

#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "core/pointer.h"
#include "core/print.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/kalimat.h"

#define TIPE_DATA_BILANGAN_BULAT long long int
#define TIPE_DATA_BILANGAN_DESIMAL long double

// NILAI BILANGAN MACRO
#define _NILAI_BILANGAN_OPERATION_LEFT_RIGHT_RETURN_CODE(result, op) return result(this->ambilNilai() op nilaiX.ambilNilai())

#define _NILAI_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(nilai_bilangan, result, op, with_type) \
  CLASS_DEFINE_OPERATION_LEFT_RIGHT(nilai_bilangan, result, op, with_type, \
    _NILAI_BILANGAN_OPERATION_LEFT_RIGHT_RETURN_CODE(result, op);\
  )

// BILANGAN BULAT MACRO
#define _BILANGAN_BULAT_PATTERN "^-?[0-9]+$"
#define _BILANGAN_BULAT_CONSTRUCTOR(type) \
  NSTD _bilangan_bulat::_bilangan_bulat(const type& nilai): nilai(nilai) {}

#define _BILANGAN_BULAT_NEGATIF_ERROR_OPERATION(op) RTERROR(FMT("Tidak dapat melakukan operasi '{}' pada bilangan bulat negatif.", op))

#define _BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(result, op, with_type) \
  _NILAI_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, result, op, with_type)

#define _BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(result, op, with_type, op_str)\
  CLASS_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, result, op, with_type, \
    if(this->isNegatif()) {throw _BILANGAN_BULAT_NEGATIF_ERROR_OPERATION(op_str);}\
    _NILAI_BILANGAN_OPERATION_LEFT_RIGHT_RETURN_CODE(result, op);\
  )

// BILANGAN DESIMAL MACRO
#define _BILANGAN_DESIMAL_PATTERN "^-?[0-9]+,[0-9]+$"
#define _BILANGAN_DESIMAL_CONSTRUCTOR(type) \
  NSTD _bilangan_desimal::_bilangan_desimal(const type& nilai): nilai(nilai) {}

#define _BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(result, op, with_type) \
  _NILAI_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, result, op, with_type)

#define _BILANGAN_ERROR_OPERATION_WITH_BILANGAN_DESIMAL(op) RTERROR(FMT("Tidak dapat melakukan operasi '{}' pada bilangan desimal.", op))

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

#define _BILANGAN_ERROR_OPERASI_TIDAK_VALID(operasi_name) RTERROR(FMT("Operasi {} tidak valid.", operasi_name))

#define _BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(result, op, with_type, code) \
  CLASS_DEFINE_OPERATION_LEFT_RIGHT(NSTD bilangan, result, op, with_type, code)

#define _BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(result, op, with_type, op_name) \
  _BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(result, op, with_type, \
    if(this->isBulat() && nilaiX.isBulat()) {\
      return result(this->ambilNilaiBulat() op nilaiX.ambilNilaiBulat());\
    }\
    if(this->isDesimal() && nilaiX.isDesimal()) {\
      return result(this->ambilNilaiDesimal() op nilaiX.ambilNilaiDesimal());\
    }\
    if(this->isBulat() && nilaiX.isDesimal()) {\
      return result(this->ambilNilaiBulat() op nilaiX.ambilNilaiDesimal());\
    }\
    if(this->isDesimal() && nilaiX.isBulat()) {\
      return result(this->ambilNilaiDesimal() op nilaiX.ambilNilaiBulat());\
    }\
    throw _BILANGAN_ERROR_OPERASI_TIDAK_VALID(op_name);\
  )

#define _BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(result, op, with_type, op_name) \
  _BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(result, op, with_type, \
    if(this->isBulat() && nilaiX.isBulat()) {\
      return result(this->ambilNilaiBulat() op nilaiX.ambilNilaiBulat());\
    }\
    throw _BILANGAN_ERROR_OPERASI_TIDAK_VALID(op_name);\
  )

// BILANGAN BULAT

_BILANGAN_BULAT_CONSTRUCTOR(int)
_BILANGAN_BULAT_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT)

const TIPE_DATA_BILANGAN_BULAT& NSTD _bilangan_bulat::ambilNilai() const {
  return this->nilai;
}

NSTD kalimat NSTD _bilangan_bulat::ubahKeKalimat() const {
  return kalimat(STD to_string(this->nilai));
}

NSTD _bilangan_bulat NSTD _bilangan_bulat::operator~() const {
  _bilangan_bulat temp = *this;
  if(temp.isNegatif()) {
    throw _BILANGAN_BULAT_NEGATIF_ERROR_OPERATION("~");
  }
  PRINT("NSTD _bilangan_bulat NSTD _bilangan_bulat::operator~() const {");
  temp.nilai = ~temp.nilai;
  return temp;
}

ND NSTD benarsalah NSTD _bilangan_bulat::isNegatif() const {
  kalimat tempStr = this->ubahKeKalimat();
  return tempStr.diAwali('-');
}

_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, +, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, +, NSTD _bilangan_desimal)
NSTD _bilangan_bulat NSTD _bilangan_bulat::operator-(const int& nilaiX) const {
  return _bilangan_bulat(this->ambilNilai() - nilaiX);
}
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, -, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, -, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, *, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, *, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, /, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, /, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_bulat, %, NSTD _bilangan_bulat)
NSTD _bilangan_desimal NSTD _bilangan_bulat::operator%(const NSTD _bilangan_desimal& nilaiX) const {
  return _bilangan_desimal(STD fmodl((long double)this->ambilNilai(), nilaiX.ambilNilai()));
}
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, ==, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, ==, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, !=, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, !=, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >,NSTD  _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >=, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >=, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <=, NSTD _bilangan_bulat)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <=, NSTD _bilangan_desimal)
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(NSTD _bilangan_bulat, &, NSTD _bilangan_bulat, "&")
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(NSTD _bilangan_bulat, |, NSTD _bilangan_bulat, "|")
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(NSTD _bilangan_bulat, ^, NSTD _bilangan_bulat, "^")
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(NSTD _bilangan_bulat, <<, NSTD _bilangan_bulat, "<<")
_BILANGAN_BULAT_DEFINE_OPERATION_LEFT_RIGHT_ERROR_IF_NEGATIF(NSTD _bilangan_bulat, >>, NSTD _bilangan_bulat, ">>")


// BILANGAN DESIMAL

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

ND NSTD benarsalah NSTD _bilangan_desimal::isNegatif() const {
  kalimat tempStr = this->ubahKeKalimat();
  return tempStr.diAwali('-');
}

_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, +, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, +, NSTD _bilangan_desimal);
NSTD _bilangan_desimal NSTD _bilangan_desimal::operator-(const int& nilaiX) const {
  return _bilangan_desimal(this->ambilNilai() - nilaiX);
};
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, -, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, -, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, *, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, *, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, /, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD _bilangan_desimal, /, NSTD _bilangan_desimal);
NSTD _bilangan_desimal NSTD _bilangan_desimal ::operator%(const _bilangan_bulat& nilaiX) const {
  return _bilangan_desimal(STD fmodl(this->ambilNilai(), (long double)nilaiX.ambilNilai()));
};
NSTD _bilangan_desimal NSTD _bilangan_desimal ::operator%(const _bilangan_desimal& nilaiX) const {
  return _bilangan_desimal(STD fmodl(this->ambilNilai(),nilaiX.ambilNilai()));
};
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, ==, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, ==, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, !=, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, !=, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >=,NSTD  _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, >=, NSTD _bilangan_desimal);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <=, NSTD _bilangan_bulat);
_BILANGAN_DESIMAL_DEFINE_OPERATION_LEFT_RIGHT(NSTD benarsalah, <=, NSTD _bilangan_desimal);

// BILANGAN

// Constructors
_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(int)
_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT)
_BILANGAN_BILANGAN_BULAT_CONSTRUCTOR(_bilangan_bulat)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(float)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(double)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL)
_BILANGAN_BILANGAN_DESIMAL_CONSTRUCTOR(_bilangan_desimal)
// Copy constructors
NSTD bilangan::bilangan(const bilangan& nilai) {
  if(nilai.isBulat()) {
    this->nilai = MPTR(_bilangan_bulat, nilai.ambilNilaiBulat());
  }else if(nilai.isDesimal()) {
    this->nilai = MPTR(_bilangan_desimal, nilai.ambilNilaiDesimal());
  }else{
    throw _BILANGAN_ERROR_INVALID_VALUE;
  }
}
// Move constructor
NSTD bilangan::bilangan(bilangan&& other) noexcept: nilai(STD move(other.nilai)) {}

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
  }
  if(PTR_CAST(_BILANGAN_VALUE, _bilangan_desimal)) {
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

ND NSTD benarsalah NSTD bilangan::isNegatif() const {
  if(this->isBulat()) {
    return this->ambilNilaiBulat().isNegatif();
  }
  if(this->isDesimal()) {
    return this->ambilNilaiDesimal().isNegatif();
  }
  throw _BILANGAN_ERROR_INVALID_VALUE;
}

NSTD bilangan NSTD bilangan::operator~() const {
  bilangan temp = *this;
  if(temp.isBulat()) {
    temp.nilai = MPTR(_bilangan_bulat, ~temp.ambilNilaiBulat());
    return temp;
  }
  throw _BILANGAN_ERROR_OPERATION_WITH_BILANGAN_DESIMAL("~");
}

_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD bilangan, +, NSTD bilangan, "penjumlahan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD bilangan, -, NSTD bilangan, "pengurangan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT(NSTD bilangan, -, int,
  if(this->isBulat()) { return bilangan(this->ambilNilaiBulat() - nilaiX); }
  if(this->isDesimal()) { return bilangan(this->ambilNilaiDesimal() - nilaiX); }
  throw _BILANGAN_ERROR_INVALID_VALUE;
)
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD bilangan, *, NSTD bilangan, "perkalian")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD bilangan, /, NSTD bilangan, "pembagian")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD bilangan, %, NSTD bilangan, "sisa pembagian")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, ==, NSTD bilangan, "persamaan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, !=, NSTD bilangan, "pertidaksamaan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, >, NSTD bilangan, "lebih besar dari")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, <, NSTD bilangan, "lebih kecil dari")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, >=, NSTD bilangan, "lebih besar dari sama dengan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR(NSTD benarsalah, <=, NSTD bilangan, "lebih kecil dari sama dengan")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(NSTD bilangan, &, NSTD bilangan, "and bit")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(NSTD bilangan, |, NSTD bilangan, "or bit")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(NSTD bilangan, ^, NSTD bilangan, "xor bit")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(NSTD bilangan, <<, NSTD bilangan, "geser kiri bit")
_BILANGAN_DEFINE_OPERATION_LEFT_RIGHT_WITH_RETURN_CODE_AND_THROW_ERROR_WITHOUT_BILANGAN_DESIMAL(NSTD bilangan, >>, NSTD bilangan, "geser kanan bit")