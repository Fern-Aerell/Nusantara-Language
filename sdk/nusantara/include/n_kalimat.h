#pragma once

#include <ostream>
#include <string>

class NKalimat {
    public:
        explicit NKalimat(std::string nilai);
        NKalimat operator+(NKalimat const& kalimat) const;
        friend std::ostream& operator<<(std::ostream& oss, const NKalimat& kalimat) {
            oss << kalimat.nilai;
            return oss;
        }
    private:
        std::string nilai;
};