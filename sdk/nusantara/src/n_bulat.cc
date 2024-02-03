#include "n_kalimat.h"
#include <n_bulat.h>

NBulat::NBulat(const int& nilai): nilai(nilai) {}

NKalimat NBulat::ubahKeKalimat() const {
    return NKalimat(std::to_string(this->nilai));
}

NBulat NBulat::operator+(NBulat const& bulat) const {
    int hasil = this->nilai + bulat.nilai;
    return NBulat(hasil);
}

NBulat NBulat::operator-(NBulat const& bulat) const {
    int hasil = this->nilai - bulat.nilai;
    return NBulat(hasil);
}

NBulat NBulat::operator/(NBulat const& bulat) const {
    int hasil = this->nilai / bulat.nilai;
    return NBulat(hasil);
}

NBulat NBulat::operator*(NBulat const& bulat) const {
    int hasil = this->nilai * bulat.nilai;
    return NBulat(hasil);
}

NBulat NBulat::operator%(NBulat const& bulat) const {
    int hasil = this->nilai % bulat.nilai;
    return NBulat(hasil);
}

NBulat NBulat::operator++() const {
    int hasil = this->nilai + 1;
    return NBulat(hasil);
}

NBulat NBulat::operator--() const {
    int hasil = this->nilai - 1;
    return NBulat(hasil);
}
