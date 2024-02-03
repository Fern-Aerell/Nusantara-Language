#pragma once

#include "n_kalimat.h"

class NDesimalPr {
    public:
        explicit NDesimalPr(const float& nilai);
        NDesimalPr operator+(NDesimalPr const& desimal) const ;
        NDesimalPr operator-(NDesimalPr const& desimal) const;
        NDesimalPr operator/(NDesimalPr const& desimal) const;
        NDesimalPr operator*(NDesimalPr const& desimal) const;
        NDesimalPr operator%(NDesimalPr const& desimal) const;
        NDesimalPr operator++() const;
        NDesimalPr operator--() const;
        [[nodiscard]] NKalimat ubahKeKalimat() const;
    private:
        float nilai;
};