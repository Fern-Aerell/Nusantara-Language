#include "ncpp/tipe_data/dinamis.h"
#include <any>
#include <iostream>
#include <stdexcept>
#include <string>
#include "ncpp/tipe_data/teks.h"

// Constructors
ncpp::dinamis::dinamis() = default;
ncpp::dinamis::dinamis(std::any nilai): nilai(std::move(nilai)) {}
// Destructor
ncpp::dinamis::~dinamis() = default;
// Copy constructor
ncpp::dinamis::dinamis(const dinamis& other) = default;
// Copy assignment operator
ncpp::dinamis& ncpp::dinamis::operator=(const dinamis& other) {
	if(this == &other) {return *this;}
	this->nilai = other.nilai;
	return *this;
}
// Move constructor
ncpp::dinamis::dinamis(dinamis&& other) noexcept: nilai(std::move(other.nilai)) {}
// Move assignment operator
ncpp::dinamis& ncpp::dinamis::operator=(dinamis&& other) noexcept {
	this->nilai = std::move(other.nilai);
	return *this;
}

std::string ncpp::dinamis::ubah_ke_string() const {
	if(!this->nilai.has_value()) {
		return "kosong";
	}
	if(auto hasil = this->ubah_ke_string<char>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<short>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<int>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<long>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<long long>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<float>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<double>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<long double>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<bool>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<const char*>()) {return *hasil;}
	if(auto hasil = this->ubah_ke_string<std::string>()) {return *hasil;}
	throw std::runtime_error(teks("Nilai dinamis '{}' tidak dapat diubah ke string.", this->nilai.type().name()).ubah_ke_string());
}
