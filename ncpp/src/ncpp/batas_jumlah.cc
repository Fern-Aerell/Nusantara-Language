#include "ncpp/batas_jumlah.h"
#include <stdexcept>
#include "ncpp/tipe_data/teks.h"

ncpp::batas_jumlah_minimal::batas_jumlah_minimal(const size_t& jumlah): jumlah(jumlah), batasan(true) {}
bool ncpp::batas_jumlah_minimal::operator==(const batas_jumlah_minimal& other) const {
    return this->batasan == other.batasan && this->jumlah == other.jumlah;
}
bool ncpp::batas_jumlah_minimal::operator!=(const batas_jumlah_minimal& other) const {
    return this->batasan != other.batasan && this->jumlah != other.jumlah;
}

ncpp::batas_jumlah_maksimal::batas_jumlah_maksimal(const size_t& jumlah): jumlah(jumlah), batasan(true) {}
bool ncpp::batas_jumlah_maksimal::operator==(const batas_jumlah_maksimal& other) const {
    return this->batasan == other.batasan && this->jumlah == other.jumlah;
}
bool ncpp::batas_jumlah_maksimal::operator!=(const batas_jumlah_maksimal& other) const {
    return this->batasan != other.batasan && this->jumlah != other.jumlah;
}

ncpp::batas_jumlah::batas_jumlah(const size_t& min, const size_t& max): min(min), max(max) {
    if(min > max) {
        throw std::runtime_error(teks("Batas jumlah minimal '{}' tidak boleh lebih tinggi dari batas jumlah maksimal '{}'.", min, max).ubah_ke_string());
    }
}
ncpp::batas_jumlah::batas_jumlah(const batas_jumlah_minimal& min): min(min) {}
ncpp::batas_jumlah::batas_jumlah(const batas_jumlah_maksimal& max): max(max) {}
bool ncpp::batas_jumlah::operator==(const batas_jumlah& other) const {
    return this->max == other.max && this->min == other.min;
}
bool ncpp::batas_jumlah::operator!=(const batas_jumlah& other) const {
    return this->max != other.max && this->min != other.min;
}