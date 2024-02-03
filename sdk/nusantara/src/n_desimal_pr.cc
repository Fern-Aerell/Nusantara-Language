#include "n_kalimat.h"
#include <n_desimal_pr.h>
#include <string>

NDesimalPr::NDesimalPr(const float& nilai): nilai(nilai) {}

NKalimat NDesimalPr::ubahKeKalimat() const {
    return NKalimat(std::to_string(this->nilai));
}

NDesimalPr NDesimalPr::operator+(NDesimalPr const& desimal) const {
    float hasil = this->nilai + desimal.nilai;
    return NDesimalPr(hasil);
}

NDesimalPr NDesimalPr::operator-(NDesimalPr const& desimal) const {
    float hasil = this->nilai - desimal.nilai;
    return NDesimalPr(hasil);
}

NDesimalPr NDesimalPr::operator/(NDesimalPr const& desimal) const {
    float hasil = this->nilai / desimal.nilai;
    return NDesimalPr(hasil);
}

NDesimalPr NDesimalPr::operator*(NDesimalPr const& desimal) const {
    float hasil = this->nilai * desimal.nilai;
    return NDesimalPr(hasil);
}

NDesimalPr NDesimalPr::operator++() const {
    float hasil = this->nilai + 1;
    return NDesimalPr(hasil);
}

NDesimalPr NDesimalPr::operator--() const {
    float hasil = this->nilai - 1;
    return NDesimalPr(hasil);
}
