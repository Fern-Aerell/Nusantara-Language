#pragma once

#include <iostream>
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/kalimat.h"

namespace nstd {
    class konsol {
        public:
            static void cetak(const bilangan& nilai) {
                std::cout << nilai << "\n";
            }
            static void cetak(const kalimat& nilai) {
                std::cout << nilai << "\n";
            }
        private:
    };
}