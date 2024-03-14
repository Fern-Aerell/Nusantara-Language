#include <mpfr.h>
#include <algorithm>
#include <regex>
#include <string>
#include "ncpp/alat/alat_mpfr.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"
#include "ncpp/alat/alat_string.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/teks.h"

// Constructors
ncpp::bilangan_desimal::bilangan_desimal() {
	mpfr_init_set_str(this->nilai, "0.0", bilangan_desimal::basis, bilangan_desimal::pembulatan);
}
ncpp::bilangan_desimal:: bilangan_desimal(const std::string& nilai) {
	std::string nilai_dengan_titik(nilai);
	std::replace(nilai_dengan_titik.begin(), nilai_dengan_titik.end(), ',', '.');	
	mpfr_init_set_str(this->nilai, nilai_dengan_titik.c_str(), bilangan_desimal::basis, bilangan_desimal::pembulatan);
}
// Destructor
ncpp::bilangan_desimal::~bilangan_desimal() {
	mpfr_clear(this->nilai);
}
// Copy constructor
ncpp::bilangan_desimal::bilangan_desimal(const bilangan_desimal& other) {
	mpfr_init_set(this->nilai, other.nilai, bilangan_desimal::pembulatan);
}
// Copy assignment operator
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator=(const bilangan_desimal& other) {
	if (this != &other) {
    mpfr_set(this->nilai, other.nilai, bilangan_desimal::pembulatan);
  }
  return *this;
} 
// Move constructor
ncpp::bilangan_desimal::bilangan_desimal(bilangan_desimal&& other) noexcept {
  mpfr_init_set_str(this->nilai, "0.0", bilangan_desimal::basis, bilangan_desimal::pembulatan);
  mpfr_swap(this->nilai, other.nilai);
  
}
// Move assignment operator
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator=(bilangan_desimal&& other) noexcept {
	if (this != &other) {
    mpfr_swap(this->nilai, other.nilai);
  }
  return *this;
}

const int ncpp::bilangan_desimal::basis = 10;
const int ncpp::bilangan_desimal::presisi_string_bawaan = 15;
const mpfr_rnd_t ncpp::bilangan_desimal::pembulatan = MPFR_RNDN;
const double ncpp::bilangan_desimal::toleransi = 1e-9;

std::regex ncpp::bilangan_desimal::pattern() {
    return std::regex("^-?[0-9]+([,.][0-9]+|([,.][0-9]*)?[eE][+-]?[0-9]+)$");
}
std::string ncpp::bilangan_desimal::ubah_ke_string() const {
	return ncpp::ubah_ke_string_presisi(this->nilai, bilangan_desimal::presisi_string_bawaan, true);
}
std::string ncpp::bilangan_desimal::ubah_ke_string_tetap(const int& presisi) const {
	return ncpp::ubah_ke_string_tetap(this->nilai, presisi, true);
}
std::string ncpp::bilangan_desimal::ubah_ke_string_presisi(const int& presisi) const {
	return ncpp::ubah_ke_string_presisi(this->nilai, presisi, true);
}
const mpfr_t& ncpp::bilangan_desimal::ambil() const {
    return this->nilai;
}

ncpp::bilangan_desimal ncpp::bilangan_desimal::ubah(const bilangan_bulat& nilai) {
  return bilangan_desimal(teks("{},0", nilai).ubah_ke_string());
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator+(const bilangan_bulat& nilai) const {
	return *this + bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator+(const bilangan_desimal& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_add(hasil, this->nilai, nilai.nilai, bilangan_desimal::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return bilangan_desimal(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator-(const bilangan_bulat& nilai) const {
	return *this - bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator-(const bilangan_desimal& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_sub(hasil, this->nilai, nilai.nilai, bilangan_desimal::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return bilangan_desimal(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator*(const bilangan_bulat& nilai) const {
	return *this * bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator*(const bilangan_desimal& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_mul(hasil, this->nilai, nilai.nilai, bilangan_desimal::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return bilangan_desimal(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator/(const bilangan_bulat& nilai) const {
	return *this / bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator/(const bilangan_desimal& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_div(hasil, this->nilai, nilai.nilai, bilangan_desimal::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return bilangan_desimal(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator%(const bilangan_bulat& nilai) const {
	return *this % bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator%(const bilangan_desimal& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_fmod(hasil, this->nilai, nilai.nilai, bilangan_desimal::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil));
	mpfr_clear(hasil);
	return bilangan_desimal(hasil_str);
}
int ncpp::bilangan_desimal::presisi() const {
	return mpfr_get_prec(this->nilai);
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator++() {
	*this = *this + bilangan_desimal("1,0");
	return *this;
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator++(int) {
	bilangan_desimal temp = *this;
	*this = *this + bilangan_desimal("1,0");
	return temp;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator--() {
	*this = *this - bilangan_desimal("1,0");
	return *this;
}
ncpp::bilangan_desimal ncpp::bilangan_desimal::operator--(int) {
	bilangan_desimal temp = *this;
	*this = *this - bilangan_desimal("1,0");
	return temp;
}
bool ncpp::bilangan_desimal::operator<(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) < 0;
}
bool ncpp::bilangan_desimal::operator<(const bilangan_bulat& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, bilangan_desimal::ubah(nilai).nilai, bilangan_desimal::toleransi) < 0;
}
bool ncpp::bilangan_desimal::operator<=(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) <= 0;
}
bool ncpp::bilangan_desimal::operator<=(const bilangan_bulat& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, bilangan_desimal::ubah(nilai).nilai, bilangan_desimal::toleransi) <= 0;
}
bool ncpp::bilangan_desimal::operator>(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) > 0;
}
bool ncpp::bilangan_desimal::operator>(const bilangan_bulat& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, bilangan_desimal::ubah(nilai).nilai, bilangan_desimal::toleransi) > 0;
}
bool ncpp::bilangan_desimal::operator>=(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) >= 0;
}
bool ncpp::bilangan_desimal::operator>=(const bilangan_bulat& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, bilangan_desimal::ubah(nilai).nilai, bilangan_desimal::toleransi) >= 0;
}
bool ncpp::bilangan_desimal::operator==(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) == 0;
}
bool ncpp::bilangan_desimal::operator==(const bilangan_bulat& nilai) const {
	return *this == bilangan_desimal::ubah(nilai);
}
bool ncpp::bilangan_desimal::operator!=(const bilangan_desimal& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, bilangan_desimal::toleransi) != 0;
}
bool ncpp::bilangan_desimal::operator!=(const bilangan_bulat& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, bilangan_desimal::ubah(nilai).nilai, bilangan_desimal::toleransi) != 0;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator+=(const bilangan_bulat& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator+=(const bilangan_desimal& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator-=(const bilangan_bulat& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator-=(const bilangan_desimal& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator*=(const bilangan_bulat& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator*=(const bilangan_desimal& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator/=(const bilangan_bulat& nilai) {
	*this = *this / nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator/=(const bilangan_desimal& nilai) {
	*this = *this / nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator%=(const bilangan_bulat& nilai) {
	*this = *this % nilai;
	return *this;
}
ncpp::bilangan_desimal& ncpp::bilangan_desimal::operator%=(const bilangan_desimal& nilai) {
	*this = *this % nilai;
	return *this;
}