#pragma once

#include "n_kalimat.h"

class NBulat {
    public:
        explicit NBulat(const int& nilai);
        NBulat operator+(NBulat const& bulat) const;
        NBulat operator-(NBulat const& bulat) const;
        NBulat operator/(NBulat const& bulat) const;
        NBulat operator*(NBulat const& bulat) const;
        NBulat operator%(NBulat const& bulat) const;
        NBulat operator++() const;
        NBulat operator--() const;
        [[nodiscard]] NKalimat ubahKeKalimat() const;
    private:
        int nilai;
};