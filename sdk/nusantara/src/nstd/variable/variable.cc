#include "nstd/variable/variable.h"
#include <format>
#include "core/core.h"
#include "core/format.h"
#include "core/error.h"
#include "core/pointer.h"
#include "core/print.h"
#include "nstd/tipe_data/bilangan.h"

#define _VARIABLE_DEFINE_COPY_ASSIGMENT_OPERATOR(tipe_data) NSTD variable& NSTD variable::operator=(const tipe_data& other) {\
    if(this->tipe != variable_data_type::tipe_data) {\
        throw RTERROR(STD format("{} bukanlah sebuah {}.", other.ubahKeKalimat().ubahKeString(), toString(this->tipe)));\
    }\
    this->nilai = MPTR(tipe_data, other);\
    return *this;\
}

#define _VARIABLE_NILAI_CAST(nilai_value) if(PTR_CAST(nilai_value, bilangan)) {\
        this->nilai = MPTR(bilangan, *cast_result_ptr);\
    }else if(PTR_CAST(nilai_value, kalimat)) {\
        this->nilai = MPTR(kalimat, *cast_result_ptr);\
    }else if(PTR_CAST(nilai_value, benarsalah)) {\
        this->nilai = MPTR(benarsalah, *cast_result_ptr);\
    }else if(PTR_CAST(nilai_value, daftar)) {\
        this->nilai = MPTR(daftar, *cast_result_ptr);\
    }else if(PTR_CAST(nilai_value, peta)) {\
        this->nilai = MPTR(peta, *cast_result_ptr);\
    }else if(PTR_CAST(nilai_value, dinamis)) {\
        this->nilai = MPTR(dinamis, *cast_result_ptr);\
    }else{\
        this->nilai = nullptr;\
    }

#define _VARIABLE_DEFINE_IS_FUNCTION(tipe_data) bool NSTD variable::is_##tipe_data() const {\
  if(PTR_CAST(this->nilai, tipe_data)) {\
    return true;\
  }\
  return false;\
}

#define _VARIABLE_AS_ERROR(as) \
  RTERROR(FMT("Nilai dinamis bukanlah sebuah {}.", as))

#define _VARIABLE_AS_ERROR_TIPE_CHECK(tipe_var, tipe_name, as_msg) \
  if(tipe_var == tipe_name) { throw _VARIABLE_AS_ERROR(as_msg); }

#define _DEFINE_VARIABLE_GET_FUNCTION(tipe_data)                                \
  const NSTD tipe_data& NSTD variable::get_##tipe_data() const {                         \
    if(this->is_##tipe_data()) {                                              \
      if(PTR_CAST(this->nilai, tipe_data)) { return *cast_result_ptr; }    \
    }                                                                         \
    STR tipe_name(typeid(tipe_data).name());                                  \
    _VARIABLE_AS_ERROR_TIPE_CHECK(                                             \
        tipe_name, "class nstd::bilangan", "bilangan"                         \
    )                                                                         \
    _VARIABLE_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::kalimat", "kalimat") \
    _VARIABLE_AS_ERROR_TIPE_CHECK(                                             \
        tipe_name, "class nstd::benarsalah", "benar atau salah"               \
    )                                                                         \
    _VARIABLE_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::daftar", "daftar")   \
    _VARIABLE_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::peta", "peta")       \
    _VARIABLE_AS_ERROR_TIPE_CHECK(tipe_name, "class nstd::dinamis", "dinamis")       \
    throw RTERROR("Nilai dinamis tidak valid.");                                       \
  }

STR NSTD toString(const variable_data_type& tipe) {
    switch(tipe) {
      case variable_data_type::bilangan:
        return "bilangan";
      case variable_data_type::kalimat:
        return "kalimat";
      case variable_data_type::benarsalah:
        return "benarsalah";
      case variable_data_type::daftar:
        return "daftar";
      case variable_data_type::peta:
        return "peta";
      case variable_data_type::dinamis:
        return "dinamis";
    }
}

// Constructors
NSTD variable::variable(): tipe(), nilai(nullptr) {}
NSTD variable::variable(const variable_data_type& tipe): tipe(tipe), nilai(nullptr) {}

// Copy constructor
NSTD variable::variable(const variable& other) : tipe(other.tipe) {
    _VARIABLE_NILAI_CAST(other.nilai)
}

// Copy assignment operator
NSTD variable& NSTD variable::operator=(const variable& other) {
    if(this == &other) {return *this;}
    this->tipe = other.tipe;
    _VARIABLE_NILAI_CAST(other.nilai)
    return *this;
}
_VARIABLE_DEFINE_COPY_ASSIGMENT_OPERATOR(bilangan)
NSTD variable& NSTD variable::operator=(const kalimat& other) {
  if(this->tipe != variable_data_type ::kalimat) {
    throw std ::runtime_error(std ::format(
        "{} bukanlah sebuah {}.", other.ubahKeString(),
        toString(this->tipe)
    ));
  }
  this->nilai = std ::make_unique<kalimat>(other);
  return *this;
}
_VARIABLE_DEFINE_COPY_ASSIGMENT_OPERATOR(benarsalah)
_VARIABLE_DEFINE_COPY_ASSIGMENT_OPERATOR(daftar)
_VARIABLE_DEFINE_COPY_ASSIGMENT_OPERATOR(peta)
NSTD variable& NSTD variable::operator=(const dinamis& other) {
  if(this->tipe == variable_data_type::dinamis) {
    this->nilai = std ::make_unique<dinamis>(other);
  }else{
    if(other.is_bilangan()) {
      *this = other.get_bilangan();
    }else if(other.is_kalimat()) {
      *this = other.get_kalimat();
    }else if(other.is_benarsalah()) {
      *this = other.get_benarsalah();
    }else if(other.is_daftar()) {
      *this = other.get_daftar();
    }else if(other.is_peta()) {
      *this = other.get_peta();
    }
  }
  return *this;
}

_VARIABLE_DEFINE_IS_FUNCTION(bilangan);
_VARIABLE_DEFINE_IS_FUNCTION(kalimat);
_VARIABLE_DEFINE_IS_FUNCTION(benarsalah);
_VARIABLE_DEFINE_IS_FUNCTION(daftar);
_VARIABLE_DEFINE_IS_FUNCTION(peta);
_VARIABLE_DEFINE_IS_FUNCTION(dinamis);

_DEFINE_VARIABLE_GET_FUNCTION(bilangan);
_DEFINE_VARIABLE_GET_FUNCTION(kalimat);
_DEFINE_VARIABLE_GET_FUNCTION(benarsalah);
_DEFINE_VARIABLE_GET_FUNCTION(daftar);
_DEFINE_VARIABLE_GET_FUNCTION(peta);
_DEFINE_VARIABLE_GET_FUNCTION(dinamis);

const NSTD variable_data_type& NSTD variable::getTipe() const {
  return this->tipe;
}

ND NSTD kalimat NSTD variable::ubahKeKalimat() const {
    if(this->is_bilangan()) {
        return this->get_bilangan().ubahKeKalimat();
    }else if(this->is_kalimat()) {
        return this->get_kalimat();
    }else if(this->is_benarsalah()) {
        return this->get_benarsalah().ubahKeKalimat();
    }else if(this->is_daftar()) {
        return this->get_daftar().ubahKeKalimat();
    }else if(this->is_peta()) {
        return this->get_peta().ubahKeKalimat();
    }else if(this->is_dinamis()) {
        return this->get_dinamis().ubahKeKalimat();
    }else{
        return kalimat("kosong");
    }
}

NSTD bilangan NSTD variable::operator+(const bilangan& nilaiX) const {
  // kosong + bilangan = bilangan
  if(this->nilai == nullptr) {
    return nilaiX;
  }
  // bilangan + bilangan = bilangan
  if(this->is_bilangan()) {
    return this->get_bilangan() + nilaiX;
  }
  
  throw RTERROR("Operasi tidak valid.");
}