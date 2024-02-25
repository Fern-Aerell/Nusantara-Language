#pragma once

#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"

namespace nstd {
    inline nstd::benarsalah operator<(const int& nilaiX, const nstd::bilangan& nilaiY) {
        if(const auto* ptr = dynamic_cast<nstd::bilangan_bulat*>(nilaiY.ambilNilai().get())) {
            return nstd::benarsalah(ptr->getNilai() < nilaiX);
        }else if(const auto* ptr = dynamic_cast<nstd::bilangan_desimal*>(nilaiY.ambilNilai().get())) {
            return nstd::benarsalah(ptr->getNilai() < nilaiX);
        }
        throw nilai_bilangan_tidak_valid_exception();
    }
}