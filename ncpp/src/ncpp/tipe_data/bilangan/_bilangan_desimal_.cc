#include <mpfr.h>
#include <algorithm>
#include <regex>
#include <string>
#include "ncpp/alat/alat_mpfr.h"
#include "ncpp/alat/alat_string.h"
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_bulat_.h"
#include "ncpp/tipe_data/teks.h"

// Constructors
ncpp::_bilangan_desimal_::_bilangan_desimal_() {
	mpfr_init_set_str(this->nilai, "0.0", _bilangan_desimal_::basis, _bilangan_desimal_::pembulatan);
}
ncpp::_bilangan_desimal_:: _bilangan_desimal_(const std::string& nilai) {
	std::string nilai_dengan_titik(nilai);
	std::replace(nilai_dengan_titik.begin(), nilai_dengan_titik.end(), ',', '.');	
	mpfr_init_set_str(this->nilai, nilai_dengan_titik.c_str(), _bilangan_desimal_::basis, _bilangan_desimal_::pembulatan);
}
// Destructor
ncpp::_bilangan_desimal_::~_bilangan_desimal_() {
	mpfr_clear(this->nilai);
}
// Copy constructor
ncpp::_bilangan_desimal_::_bilangan_desimal_(const _bilangan_desimal_& other) {
	mpfr_init_set(this->nilai, other.nilai, _bilangan_desimal_::pembulatan);
}
// Copy assignment operator
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator=(const _bilangan_desimal_& other) {
	if (this != &other) {
    mpfr_set(this->nilai, other.nilai, _bilangan_desimal_::pembulatan);
  }
  return *this;
} 
// Move constructor
ncpp::_bilangan_desimal_::_bilangan_desimal_(_bilangan_desimal_&& other) noexcept {
  mpfr_init_set_str(this->nilai, "0.0", _bilangan_desimal_::basis, _bilangan_desimal_::pembulatan);
  mpfr_swap(this->nilai, other.nilai);
  
}
// Move assignment operator
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator=(_bilangan_desimal_&& other) noexcept {
	if (this != &other) {
    mpfr_swap(this->nilai, other.nilai);
  }
  return *this;
}

const int ncpp::_bilangan_desimal_::basis = 10;
const int ncpp::_bilangan_desimal_::presisi_string_bawaan = 15;
const mpfr_rnd_t ncpp::_bilangan_desimal_::pembulatan = MPFR_RNDN;
const double ncpp::_bilangan_desimal_::toleransi = 1e-9;

std::regex ncpp::_bilangan_desimal_::pattern() {
    return std::regex("^-?[0-9]+([,.][0-9]+|([,.][0-9]*)?[eE][+-]?[0-9]+)$");
}
std::string ncpp::_bilangan_desimal_::ubah_ke_string() const {
	return ncpp::ubah_ke_string_presisi(this->nilai, _bilangan_desimal_::presisi_string_bawaan, true);
}
std::string ncpp::_bilangan_desimal_::ubah_ke_string_tetap(const int& presisi) const {
	return ncpp::ubah_ke_string_tetap(this->nilai, presisi, true);
}
std::string ncpp::_bilangan_desimal_::ubah_ke_string_presisi(const int& presisi) const {
	return ncpp::ubah_ke_string_presisi(this->nilai, presisi, true);
}
const mpfr_t& ncpp::_bilangan_desimal_::ambil() const {
    return this->nilai;
}

ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::ubah(const _bilangan_bulat_& nilai) {
  return _bilangan_desimal_(teks("{},0", nilai).ubah_ke_string());
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator+(const _bilangan_bulat_& nilai) const {
	return *this + _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator+(const _bilangan_desimal_& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_add(hasil, this->nilai, nilai.nilai, _bilangan_desimal_::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return _bilangan_desimal_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator-(const _bilangan_bulat_& nilai) const {
	return *this - _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator-(const _bilangan_desimal_& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_sub(hasil, this->nilai, nilai.nilai, _bilangan_desimal_::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return _bilangan_desimal_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator*(const _bilangan_bulat_& nilai) const {
	return *this * _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator*(const _bilangan_desimal_& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_mul(hasil, this->nilai, nilai.nilai, _bilangan_desimal_::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return _bilangan_desimal_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator/(const _bilangan_bulat_& nilai) const {
	return *this / _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator/(const _bilangan_desimal_& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_div(hasil, this->nilai, nilai.nilai, _bilangan_desimal_::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil), true);
	mpfr_clear(hasil);
	return _bilangan_desimal_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator%(const _bilangan_bulat_& nilai) const {
	return *this % _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator%(const _bilangan_desimal_& nilai) const {
	mpfr_t hasil;
	mpfr_init(hasil);
	mpfr_fmod(hasil, this->nilai, nilai.nilai, _bilangan_desimal_::pembulatan);
	std::string hasil_str = ncpp::ubah_ke_string_presisi(hasil, mpfr_get_prec(hasil));
	mpfr_clear(hasil);
	return _bilangan_desimal_(hasil_str);
}
int ncpp::_bilangan_desimal_::presisi() const {
	return mpfr_get_prec(this->nilai);
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator++() {
	*this = *this + _bilangan_desimal_("1,0");
	return *this;
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator++(int) {
	_bilangan_desimal_ temp = *this;
	*this = *this + _bilangan_desimal_("1,0");
	return temp;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator--() {
	*this = *this - _bilangan_desimal_("1,0");
	return *this;
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_desimal_::operator--(int) {
	_bilangan_desimal_ temp = *this;
	*this = *this - _bilangan_desimal_("1,0");
	return temp;
}
bool ncpp::_bilangan_desimal_::operator<(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) < 0;
}
bool ncpp::_bilangan_desimal_::operator<(const _bilangan_bulat_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, _bilangan_desimal_::ubah(nilai).nilai, _bilangan_desimal_::toleransi) < 0;
}
bool ncpp::_bilangan_desimal_::operator<=(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) <= 0;
}
bool ncpp::_bilangan_desimal_::operator<=(const _bilangan_bulat_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, _bilangan_desimal_::ubah(nilai).nilai, _bilangan_desimal_::toleransi) <= 0;
}
bool ncpp::_bilangan_desimal_::operator>(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) > 0;
}
bool ncpp::_bilangan_desimal_::operator>(const _bilangan_bulat_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, _bilangan_desimal_::ubah(nilai).nilai, _bilangan_desimal_::toleransi) > 0;
}
bool ncpp::_bilangan_desimal_::operator>=(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) >= 0;
}
bool ncpp::_bilangan_desimal_::operator>=(const _bilangan_bulat_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, _bilangan_desimal_::ubah(nilai).nilai, _bilangan_desimal_::toleransi) >= 0;
}
bool ncpp::_bilangan_desimal_::operator==(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) == 0;
}
bool ncpp::_bilangan_desimal_::operator==(const _bilangan_bulat_& nilai) const {
	return *this == _bilangan_desimal_::ubah(nilai);
}
bool ncpp::_bilangan_desimal_::operator!=(const _bilangan_desimal_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, nilai.nilai, _bilangan_desimal_::toleransi) != 0;
}
bool ncpp::_bilangan_desimal_::operator!=(const _bilangan_bulat_& nilai) const {
	return mpfr_cmp_with_tolerance(this->nilai, _bilangan_desimal_::ubah(nilai).nilai, _bilangan_desimal_::toleransi) != 0;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator+=(const _bilangan_bulat_& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator+=(const _bilangan_desimal_& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator-=(const _bilangan_bulat_& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator-=(const _bilangan_desimal_& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator*=(const _bilangan_bulat_& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator*=(const _bilangan_desimal_& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator/=(const _bilangan_bulat_& nilai) {
	*this = *this / nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator/=(const _bilangan_desimal_& nilai) {
	*this = *this / nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator%=(const _bilangan_bulat_& nilai) {
	*this = *this % nilai;
	return *this;
}
ncpp::_bilangan_desimal_& ncpp::_bilangan_desimal_::operator%=(const _bilangan_desimal_& nilai) {
	*this = *this % nilai;
	return *this;
}