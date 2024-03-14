#include <gmp.h>
#include <mpfr.h>
#include <string>
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"
#include "ncpp/alat/alat_string.h"

// Constructors
ncpp::bilangan_bulat::bilangan_bulat() {
	mpz_init(this->nilai);
}
ncpp::bilangan_bulat::bilangan_bulat(const std::string& nilai) {
	mpz_init_set_str(this->nilai, nilai.c_str(), bilangan_bulat::basis);
}
// Destructor
ncpp::bilangan_bulat::~bilangan_bulat() {
 mpz_clear(this->nilai);
}
// Copy constructor
ncpp::bilangan_bulat::bilangan_bulat(const bilangan_bulat& other) {
	mpz_init_set(this->nilai, other.nilai);
}
// Copy assignment operator
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator=(const bilangan_bulat& other) {
	if(this != &other) {
		mpz_set(this->nilai, other.nilai);
	}
	return *this;
}
// Move constructor
ncpp::bilangan_bulat::bilangan_bulat(bilangan_bulat&& other) noexcept {
	mpz_init(this->nilai);
	mpz_swap(this->nilai, other.nilai);
}
// Move assignment operator
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator=(bilangan_bulat&& other) noexcept {
	if(this != &other) {
		mpz_swap(this->nilai, other.nilai);
	}
	return *this;
}

const int ncpp::bilangan_bulat::basis = 10;

std::regex ncpp::bilangan_bulat::pattern() {
    return std::regex("^-?[0-9]+$");
}

std::string ncpp::bilangan_bulat::ubah_ke_string() const {
	return ncpp::ubah_ke_string(this->nilai, bilangan_bulat::basis);
}

const mpz_t& ncpp::bilangan_bulat::ambil() const {
    return this->nilai;
}

ncpp::bilangan_bulat ncpp::bilangan_bulat::ubah(const bilangan_desimal &nilai) {
	mpz_t nilai_bulat;
  	mpz_init(nilai_bulat);
  	mpfr_get_z(nilai_bulat, nilai.ambil(), bilangan_desimal::pembulatan);
	std::string nilai_bulat_str = ncpp::ubah_ke_string(nilai_bulat, bilangan_bulat::basis);
	mpz_clear(nilai_bulat);
	return bilangan_bulat(nilai_bulat_str);
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator+(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_add(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator+(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) + nilai;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator-(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_sub(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator-(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) - nilai;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator*(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mul(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator*(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) * nilai;
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator/(const bilangan_bulat& nilai) const {
	return bilangan_desimal::ubah(*this) / bilangan_desimal::ubah(nilai);
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator/(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) / nilai;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator%(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mod(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_desimal ncpp::bilangan_bulat::operator%(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) % nilai;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator~() const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_com(hasil, this->nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator++() {
	*this = *this + bilangan_bulat("1");
	return *this;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator++(int) {
	bilangan_bulat temp = *this;
	*this = *this + bilangan_bulat("1");
	return temp;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator--() {
	*this = *this - bilangan_bulat("1");
	return *this;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator--(int) {
	bilangan_bulat temp = *this;
	*this = *this - bilangan_bulat("1");
	return temp;
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator&(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_and(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator^(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_xor(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator|(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_ior(hasil, this->nilai, nilai.nilai);
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator<<(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_mul_2exp(hasil, this->nilai, mpz_get_ui(nilai.nilai));
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
ncpp::bilangan_bulat ncpp::bilangan_bulat::operator>>(const bilangan_bulat& nilai) const {
	mpz_t hasil;
	mpz_init(hasil);
	mpz_tdiv_q_2exp(hasil, this->nilai, mpz_get_ui(nilai.nilai));
	std::string hasil_str = ncpp::ubah_ke_string(hasil, bilangan_bulat::basis);
	mpz_clear(hasil);
	return bilangan_bulat(hasil_str);
}
bool ncpp::bilangan_bulat::operator<(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) < 0;
}
bool ncpp::bilangan_bulat::operator<(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) < nilai;
}
bool ncpp::bilangan_bulat::operator<=(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) <= 0;
}
bool ncpp::bilangan_bulat::operator<=(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) <= nilai;
}
bool ncpp::bilangan_bulat::operator>(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) > 0;
}
bool ncpp::bilangan_bulat::operator>(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) > nilai;
}
bool ncpp::bilangan_bulat::operator>=(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) >= 0;
}
bool ncpp::bilangan_bulat::operator>=(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) >= nilai;
}
bool ncpp::bilangan_bulat::operator==(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) == 0;
}
bool ncpp::bilangan_bulat::operator==(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) == nilai;
}
bool ncpp::bilangan_bulat::operator!=(const bilangan_bulat& nilai) const {
	return mpz_cmp(this->nilai, nilai.nilai) != 0;
}
bool ncpp::bilangan_bulat::operator!=(const bilangan_desimal& nilai) const {
	return bilangan_desimal::ubah(*this) != nilai;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator+=(const bilangan_bulat& nilai) {
	*this = *this + nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator-=(const bilangan_bulat& nilai) {
	*this = *this - nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator*=(const bilangan_bulat& nilai) {
	*this = *this * nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator/=(const bilangan_bulat& nilai) {
	*this = bilangan_bulat::ubah(*this / nilai);
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator%=(const bilangan_bulat& nilai) {
	*this = *this % nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator&=(const bilangan_bulat& nilai) {
	*this = *this & nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator^=(const bilangan_bulat& nilai) {
	*this = *this ^ nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator|=(const bilangan_bulat& nilai) {
	*this = *this | nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator<<=(const bilangan_bulat& nilai) {
	*this = *this << nilai;
	return *this;
}
ncpp::bilangan_bulat& ncpp::bilangan_bulat::operator>>=(const bilangan_bulat& nilai) {
	*this = *this >> nilai;
	return *this;
}