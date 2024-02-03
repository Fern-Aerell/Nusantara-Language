#pragma once

#include "n_kalimat.h"

class NDesimalPt {
    public:
        explicit NDesimalPt(const double& nilai);
        NDesimalPt operator+(NDesimalPt const& desimal) const ;
        NDesimalPt operator-(NDesimalPt const& desimal) const;
        NDesimalPt operator/(NDesimalPt const& desimal) const;
        NDesimalPt operator*(NDesimalPt const& desimal) const;
        NDesimalPt operator%(NDesimalPt const& desimal) const;
        NDesimalPt operator++() const;
        NDesimalPt operator--() const;
        [[nodiscard]] NKalimat ubahKeKalimat() const;
    private:
        double nilai;
};