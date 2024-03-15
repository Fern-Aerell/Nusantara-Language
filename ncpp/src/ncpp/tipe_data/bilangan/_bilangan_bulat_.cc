#include <gmp.h>
#include <mpfr.h>
#include <string>
#include "ncpp/tipe_data/bilangan/_bilangan_bulat_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"
#include "ncpp/alat/alat_string.h"

// Constructors
ncpp::_bilangan_bulat_::_bilangan_bulat_() {
	mpz_init(this->nilai);
}
ncpp::_bilangan_bulat_::_bilangan_bulat_(const std::string& nilai) {
	mpz_init_set_str(this->nilai, nilai.c_str(), _bilangan_bulat_::basis);
}
// Destructor
ncpp::_bilangan_bulat_::~_bilangan_bulat_() {
 mpz_clear(this->nilai);
}
// Copy constructor
ncpp::_bilangan_bulat_::_bilangan_bulat_(const _bilangan_bulat_& other) {
	mpz_init_set(this->nilai, other.nilai);
}
// Copy assignment operator
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator=(const _bilangan_bulat_& other) {
	if(this != &other) {
		mpz_set(this->nilai, other.nilai);
	}
	return *this;
}
// Move constructor
ncpp::_bilangan_bulat_::_bilangan_bulat_(_bilangan_bulat_&& other) noexcept {
	mpz_init(this->nilai);
	mpz_swap(this->nilai, other.nilai);
}
// Move assignment operator
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator=(_bilangan_bulat_&& other) noexcept {
	if(this != &other) {
		mpz_swap(this->nilai, other.nilai);
	}
	return *this;
}

const int ncpp::_bilangan_bulat_::basis = 10;

std::regex ncpp::_bilangan_bulat_::pattern() {
    return std::regex("^-?[0-9]+$");
}

std::string ncpp::_bilangan_bulat_::ubah_ke_string() const {
	return ncpp::ubah_ke_string(this->nilai, _bilangan_bulat_::basis);
}

const mpz_t& ncpp::_bilangan_bulat_::ambil() const {
    return this->nilai;
}

ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::ubah(const _bilangan_desimal_ &nilai) {
	mpz_t nilai_bulat;
  	mpz_init(nilai_bulat);
  	mpfr_get_z(nilai_bulat, nilai.ambil(), _bilangan_desimal_::pembulatan);
	std::string nilai_bulat_str = ncpp::ubah_ke_string(nilai_bulat, _bilangan_bulat_::basis);
	mpz_clear(nilai_bulat);
	return _bilangan_bulat_(nilai_bulat_str);
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator+(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_add(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator+(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) + nilai;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator-(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_sub(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator-(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) - nilai;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator*(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mul(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator*(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) * nilai;
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator/(const _bilangan_bulat_& nilai) const {
	return _bilangan_desimal_::ubah(*this) / _bilangan_desimal_::ubah(nilai);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator/(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) / nilai;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator%(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mod(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_desimal_ ncpp::_bilangan_bulat_::operator%(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) % nilai;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator~() const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_com(hasil, this->nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator++() {
	*this = *this + _bilangan_bulat_("1");
	return *this;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator++(int) {
	_bilangan_bulat_ temp = *this;
	*this = *this + _bilangan_bulat_("1");
	return temp;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator--() {
	*this = *this - _bilangan_bulat_("1");
	return *this;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator--(int) {
	_bilangan_bulat_ temp = *this;
	*this = *this - _bilangan_bulat_("1");
	return temp;
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator&(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_and(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator^(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_xor(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator|(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_ior(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator<<(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mul_2exp(hasil, this->nilai, mpz_get_ui(nilai.nilai));
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
ncpp::_bilangan_bulat_ ncpp::_bilangan_bulat_::operator>>(const _bilangan_bulat_& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_tdiv_q_2exp(hasil, this->nilai, mpz_get_ui(nilai.nilai));
	std::string hasil_str = ncpp::ubah_ke_string(hasil, _bilangan_bulat_::basis);
	mpz_clear(hasil);
	return _bilangan_bulat_(hasil_str);
}
bool ncpp::_bilangan_bulat_::operator<(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) < 0;
}
bool ncpp::_bilangan_bulat_::operator<(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) < nilai;
}
bool ncpp::_bilangan_bulat_::operator<=(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) <= 0;
}
bool ncpp::_bilangan_bulat_::operator<=(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) <= nilai;
}
bool ncpp::_bilangan_bulat_::operator>(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) > 0;
}
bool ncpp::_bilangan_bulat_::operator>(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) > nilai;
}
bool ncpp::_bilangan_bulat_::operator>=(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) >= 0;
}
bool ncpp::_bilangan_bulat_::operator>=(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) >= nilai;
}
bool ncpp::_bilangan_bulat_::operator==(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) == 0;
}
bool ncpp::_bilangan_bulat_::operator==(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) == nilai;
}
bool ncpp::_bilangan_bulat_::operator!=(const _bilangan_bulat_& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) != 0;
}
bool ncpp::_bilangan_bulat_::operator!=(const _bilangan_desimal_& nilai) const {
	return _bilangan_desimal_::ubah(*this) != nilai;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator+=(const _bilangan_bulat_& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator-=(const _bilangan_bulat_& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator*=(const _bilangan_bulat_& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator/=(const _bilangan_bulat_& nilai) {
	*this = _bilangan_bulat_::ubah(*this / nilai);
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator%=(const _bilangan_bulat_& nilai) {
	*this = *this % nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator&=(const _bilangan_bulat_& nilai) {
	*this = *this & nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator^=(const _bilangan_bulat_& nilai) {
	*this = *this ^ nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator|=(const _bilangan_bulat_& nilai) {
	*this = *this | nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator<<=(const _bilangan_bulat_& nilai) {
	*this = *this << nilai;
	return *this;
}
ncpp::_bilangan_bulat_& ncpp::_bilangan_bulat_::operator>>=(const _bilangan_bulat_& nilai) {
	*this = *this >> nilai;
	return *this;
}