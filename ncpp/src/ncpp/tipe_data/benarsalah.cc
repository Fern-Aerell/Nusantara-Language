#include "ncpp/tipe_data/benarsalah.h"
#include <format>
#include <stdexcept>
#include <string>

// Constructors
ncpp::benarsalah::benarsalah(): nilai(false) {}
ncpp::benarsalah::benarsalah(const std::string& nilai) {
    if(nilai == "benar") {
        this->nilai = true;
    }else if(nilai == "salah") {
        this->nilai = false;
    }else {
        throw std::runtime_error(std::format("'{}' bukanlah nilai benar atau salah.", nilai));
    }
}
// Copy constructor
ncpp::benarsalah::benarsalah(const benarsalah& other)  = default;
// Copy assignment operator
ncpp::benarsalah& ncpp::benarsalah::operator=(const benarsalah& other) {
    if(this == &other) {return *this;}
    this->nilai = other.nilai;
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
ncpp::benarsalah::operator bool() const {
    return this->nilai;
}
ncpp::benarsalah ncpp::benarsalah::benar() {
    return benarsalah("benar");
}
ncpp::benarsalah ncpp::benarsalah::salah() {
    return benarsalah("salah");
}
ncpp::benarsalah ncpp::benarsalah::operator==(const benarsalah& nilai) const {
    if(this->nilai == nilai.nilai) {
        return benarsalah::benar();
    }
    return benarsalah::salah();
}
ncpp::benarsalah ncpp::benarsalah::operator!=(const benarsalah& nilai) const {
    if(this->nilai != nilai.nilai) {
        return benarsalah::benar();
    }
    return benarsalah::salah();
}
ncpp::benarsalah ncpp::benarsalah::operator!() const {
    if(this->nilai) {
        return benarsalah::salah();
    }
    return benarsalah::benar();
}
ncpp::benarsalah ncpp::benarsalah::operator&&(const benarsalah& nilai) const {
    if(this->nilai && nilai.nilai) {
        return benarsalah::benar();
    }
    return benarsalah::salah();
}
ncpp::benarsalah ncpp::benarsalah::operator||(const benarsalah& nilai) const {
    if(this->nilai || nilai.nilai) {
        return benarsalah::benar();
    }
    return benarsalah::salah();
}
