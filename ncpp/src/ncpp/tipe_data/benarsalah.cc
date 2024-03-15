#include "ncpp/tipe_data/benarsalah.h"
#include <string>

// Constructors
ncpp::benarsalah::benarsalah(): nilai(false) {}
ncpp::benarsalah::benarsalah(const bool& nilai): nilai(nilai) {}
// Copy constructor
ncpp::benarsalah::benarsalah(const benarsalah& other)  = default;
// Copy assignment operator
ncpp::benarsalah& ncpp::benarsalah::operator=(const benarsalah& other) {
    if(this == &other) {return *this;}
    this->nilai = other.nilai;
    return *this;
}
ncpp::benarsalah& ncpp::benarsalah::operator=(const bool& other) {
	if(this->nilai == other) {return *this;}
	this->nilai = other;
	return *this;
}
// Move constructor
ncpp::benarsalah::benarsalah(benarsalah&& other) noexcept : nilai(other.nilai) {}
// Move assignment operator
ncpp::benarsalah& ncpp::benarsalah::operator=(benarsalah&& other) noexcept {
    this->nilai = other.nilai;
    return *this;
}
std::string ncpp::benarsalah::ubah_ke_string() const {
    if(this->nilai) {
        return "benar";
    }
    return "salah";
}
bool ncpp::benarsalah::ubah_ke_bool() const {
	return this->nilai;
}
ncpp::benarsalah::operator bool() const {
    return this->nilai;
}
bool ncpp::benarsalah::operator==(const benarsalah& nilai) const {
    return this->nilai == nilai.nilai;
}
bool ncpp::benarsalah::operator==(const bool& nilai) const {
    return this->nilai == nilai;
}
bool ncpp::benarsalah::operator!=(const benarsalah& nilai) const {
    return this->nilai != nilai.nilai;
}
bool ncpp::benarsalah::operator!=(const bool& nilai) const {
    return this->nilai != nilai;
}
bool ncpp::benarsalah::operator!() const { 
    return !this->nilai;
}
bool ncpp::benarsalah::operator&&(const benarsalah& nilai) const {
    return this->nilai && nilai.nilai;
}
bool ncpp::benarsalah::operator&&(const bool& nilai) const {
    return this->nilai && nilai;
}
bool ncpp::benarsalah::operator||(const benarsalah& nilai) const {
    return this->nilai || nilai.nilai;
}
bool ncpp::benarsalah::operator||(const bool& nilai) const {
    return this->nilai || nilai;
}
bool operator==(const bool& nilai_x, const ncpp::benarsalah& nilai_y) {
	return nilai_x == nilai_y.ubah_ke_bool();
}
bool operator!=(const bool& nilai_x, const ncpp::benarsalah& nilai_y) {
	return nilai_x != nilai_y.ubah_ke_bool();
}
bool operator&&(const bool& nilai_x, const ncpp::benarsalah& nilai_y) {
	return nilai_x && nilai_y.ubah_ke_bool();
}
bool operator||(const bool& nilai_x, const ncpp::benarsalah& nilai_y) {
	return nilai_x || nilai_y.ubah_ke_bool();
}
