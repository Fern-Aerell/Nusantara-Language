#pragma once

#include "n_kalimat.h"

class NKarakter {
    public:
        explicit NKarakter(const char& nilai);
        NKalimat operator+(NKarakter const& karakter) const;
        [[nodiscard]] NKalimat ubahKeKalimat() const;
    private:
        char nilai;
};