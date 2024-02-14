#pragma once

#include <iostream>
#include "bilangan.h"
#include "karakter.h"
#include "benarsalah.h"
#include "dinamis.h"

namespace nstd {

    template<typename Tipe>
    inline void cetak(const Tipe& nilai) {
        std::cout << toString(nilai) << "\n";
    }
    
}