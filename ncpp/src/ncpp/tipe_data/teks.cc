#include "ncpp/tipe_data/teks.h"
#include <stdexcept>
#include <string>
#include "ncpp/tipe_data/bilangan/bilangan.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"

// Constructors
ncpp::teks::teks() = default;
ncpp::teks::teks(std::string nilai): nilai(std::move(nilai)) {}
ncpp::teks::teks(const size_t& jumlah, const char& nilai): nilai(jumlah, nilai) {}
// Copy constructor
ncpp::teks::teks(const teks& other)  = default;
// Copy assignment operator
ncpp::teks& ncpp::teks::operator=(const teks& other) {
    if(this == &other) {return *this;}
    this->nilai = other.nilai;
    return *this;
}
// Move constructor
ncpp::teks::teks(teks&& other) noexcept: nilai(std::move(other.nilai)) {}
// Move assignment operator
ncpp::teks& ncpp::teks::operator=(teks&& other) noexcept {
    this->nilai = std::move(other.nilai);
    return *this;
}
void ncpp::teks::teks_format(std::ostringstream& stream, const std::string& format) {
	stream << format;
}
ncpp::teks ncpp::teks::operator+(const teks& other) const {
	return teks(this->nilai + other.nilai);
}
ncpp::teks& ncpp::teks::operator+=(const teks& other) {
	*this = *this + other;
	return *this;
}
ncpp::teks ncpp::teks::operator*(const bilangan& other) const {
	if(other.ini_desimal()) {
		throw std::runtime_error("Tidak dapat melakukan operasi perkalian '*' pada teks dengan bilangan desimal.");
	}
	teks result;
	for(bilangan index; index < other; ++index) {
		result += *this;
	}
	return result;
}
ncpp::teks& ncpp::teks::operator*=(const bilangan& other) {
	*this = *this * other;
	return *this;
}
ncpp::teks ncpp::teks::operator*(const bilangan_bulat& other) const {
	teks result;
	for(bilangan_bulat index; index < other; ++index) {
		result += *this;
	}
	return result;
}
ncpp::teks& ncpp::teks::operator*=(const bilangan_bulat& other) {
	*this = *this * other;
	return *this;
}
bool ncpp::teks::operator==(const teks& other) const {
	return this->nilai == other.nilai;
}
bool ncpp::teks::operator!=(const teks& other) const {
	return this->nilai != other.nilai;
}
bool ncpp::teks::operator<(const teks& other) const {
	return this->nilai < other.nilai;
}
bool ncpp::teks::operator>(const teks& other) const {
	return this->nilai > other.nilai;
}
std::string ncpp::teks::ubah_ke_string() const {
	return this->nilai;
}
const char* ncpp::teks::ubah_ke_c_string() const {
	return this->nilai.c_str();
}
size_t ncpp::teks::jumlah() const {
	return this->nilai.length();
}
char& ncpp::teks::operator[](const size_t& urutan) {
	if(urutan <= 0) {
		throw std::runtime_error(teks("Urutan karakter pada teks di awali dengan 1 bukan 0.").ubah_ke_string());
	}
	if(urutan > this->jumlah()) {
		throw std::runtime_error(teks("Kamu mencoba mendapatkan karakter ke-{} dari teks yang hanya memiliki {} karakter.", urutan, this->jumlah()).ubah_ke_string());
	}
	size_t urutan_mod = urutan - 1;
	return this->nilai[urutan_mod];
}
size_t ncpp::teks::cari(const std::string& ini) const {
	return this->nilai.find(ini) + 1;
}
size_t ncpp::teks::cari(const std::string& ini, const size_t& urutan) const {
	if(urutan <= 0) {
		throw std::runtime_error(teks("Urutan karakter pada teks di awali dengan 1 bukan 0.").ubah_ke_string());
	}
	if(urutan > this->jumlah()) {
		throw std::runtime_error(teks("Kamu mencoba mendapatkan karakter ke-{} dari teks yang hanya memiliki {} karakter.", urutan, this->jumlah()).ubah_ke_string());
	}
	size_t urutan_mod = urutan - 1;
	return this->nilai.find(ini, urutan_mod) + 1;
}
void ncpp::teks::ganti(const std::string& ini, const std::string& kee) {
	size_t pos = this->nilai.find(ini);
	if(pos != std::string::npos) {
		this->nilai.replace(pos, ini.length(), kee);
	}else{
		throw std::runtime_error(teks("Kamu mencoba mengganti '{}' dengan '{}' pada teks yang tidak memiliki '{}'.", ini, kee, ini).ubah_ke_string());
	}
}
void ncpp::teks::ganti_semua(const std::string& ini, const std::string& kee) {
	size_t pos = 0;
	while ((pos = this->nilai.find(ini, pos)) != std::string::npos) {
        this->nilai.replace(pos, ini.length(), kee);
        pos += kee.length();
    }
    if (pos == 0) {
		throw std::runtime_error(teks("Kamu mencoba mengganti '{}' dengan '{}' pada teks yang tidak memiliki '{}'.", ini, kee, ini).ubah_ke_string());
    }
}