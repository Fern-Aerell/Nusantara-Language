#include "ncpp/tipe_data/dinamis.h"

// Constructors
ncpp::dinamis::dinamis(): nilai(nullptr) {}
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
