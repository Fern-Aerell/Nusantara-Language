#include "nstd/operasi/operasi.h"

#include "core/error.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"

STR& NSTD operator+=(STR& nilaiX, const kalimat& nilaiY) {
  nilaiX += nilaiY.ubahKeString();
  return nilaiX;
}

NSTD benarsalah NSTD
operator<(const int& nilaiX, const NSTD _bilangan_bulat& nilaiY) {
  return NSTD benarsalah(nilaiX < nilaiY.ambilNilai());
}

NSTD benarsalah NSTD
operator<(const int& nilaiX, const NSTD _bilangan_desimal& nilaiY) {
  return benarsalah(nilaiX < nilaiY.ambilNilai());
}

NSTD benarsalah NSTD operator<(const int& nilaiX, const NSTD bilangan& nilaiY) {
  if(nilaiY.isBulat()) {
    return nilaiX < nilaiY.ambilNilaiBulat();
  } else if(nilaiY.isDesimal()) {
    return nilaiX < nilaiY.ambilNilaiDesimal();
  }
  throw RTERROR("Operasi 'int < bilangan' tidak dapat dilakukan.");
}

NSTD bilangan NSTD operator+(const int& nilaiX, const _bilangan_bulat& nilaiY) {
  return bilangan(nilaiX + nilaiY.ambilNilai());
}

NSTD bilangan NSTD operator+(const int& nilaiX, const _bilangan_desimal& nilaiY) {
  return bilangan(nilaiX + nilaiY.ambilNilai());
}

NSTD bilangan NSTD operator+(const int& nilaiX, const bilangan& nilaiY) {
  if(nilaiY.isBulat()) {
    return nilaiX + nilaiY.ambilNilaiBulat();
  } else if(nilaiY.isDesimal()) {
    return nilaiX + nilaiY.ambilNilaiDesimal();
  }
  throw RTERROR("Operasi 'int + bilangan' tidak dapat dilakukan.");
}

NSTD bilangan NSTD operator-(const int& nilaiX, const _bilangan_bulat& nilaiY) {
  return bilangan(nilaiX - nilaiY.ambilNilai());
}

NSTD bilangan NSTD operator-(const int& nilaiX, const _bilangan_desimal& nilaiY) {
  return bilangan(nilaiX - nilaiY.ambilNilai());
}

NSTD bilangan NSTD operator-(const int& nilaiX, const bilangan& nilaiY) {
  if(nilaiY.isBulat()) {
    return nilaiX - nilaiY.ambilNilaiBulat();
  } else if(nilaiY.isDesimal()) {
    return nilaiX - nilaiY.ambilNilaiDesimal();
  }
  throw RTERROR("Operasi 'int - bilangan' tidak dapat dilakukan.");
}
