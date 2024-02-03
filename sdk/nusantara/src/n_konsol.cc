#include "n_bulat.h"
#include <iostream>
#include <n_konsol.h>

void NKonsol::cetak(const NBulat& bulat) {
    std::cout << bulat.ubahKeKalimat();
}

void NKonsol::cetakBarisBaru(const NBulat& bulat) {
    std::cout << bulat.ubahKeKalimat() << "\n";
}