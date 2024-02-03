#include <n_karakter.h>
#include <string>

NKarakter::NKarakter(const char& nilai): nilai(nilai) {}

NKalimat NKarakter::ubahKeKalimat() const {
    return NKalimat(std::to_string(this->nilai));
}

NKalimat NKarakter::operator+(NKarakter const& karakter) const {
    return NKalimat(std::to_string(this->nilai + karakter.nilai));
}
