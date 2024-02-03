#include "n_kalimat.h"
#include <n_desimal_pt.h>
#include <string>

NDesimalPt::NDesimalPt(const double& nilai): nilai(nilai) {}

NKalimat NDesimalPt::ubahKeKalimat() const {
    return NKalimat(std::to_string(this->nilai));
}

NDesimalPt NDesimalPt::operator+(NDesimalPt const& desimal) const {
    double hasil = this->nilai + desimal.nilai;
    return NDesimalPt(hasil);
}

NDesimalPt NDesimalPt::operator-(NDesimalPt const& desimal) const {
    double hasil = this->nilai - desimal.nilai;
    return NDesimalPt(hasil);
}

NDesimalPt NDesimalPt::operator/(NDesimalPt const& desimal) const {
    double hasil = this->nilai / desimal.nilai;
    return NDesimalPt(hasil);
}

NDesimalPt NDesimalPt::operator*(NDesimalPt const& desimal) const {
    double hasil = this->nilai * desimal.nilai;
    return NDesimalPt(hasil);
}

NDesimalPt NDesimalPt::operator++() const {
    double hasil = this->nilai + 1;
    return NDesimalPt(hasil);
}

NDesimalPt NDesimalPt::operator--() const {
    double hasil = this->nilai - 1;
    return NDesimalPt(hasil);
}
