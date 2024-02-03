#include <n_kalimat.h>
#include <string>

NKalimat::NKalimat(std::string nilai): nilai(std::move(nilai)) {}

NKalimat NKalimat::operator+(NKalimat const& kalimat) const {
    std::string hasil = this->nilai + kalimat.nilai;
    return NKalimat(hasil);
}