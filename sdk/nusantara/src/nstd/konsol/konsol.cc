#include "nstd/konsol/konsol.h"

#include <iostream>

#include "core/core.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/dinamis.h"

void NSTD konsol::cetak(const bilangan& nilai) { STD cout << nilai << "\n"; }

void NSTD konsol::cetak(const kalimat& nilai) { STD cout << nilai << "\n"; }

void NSTD konsol::cetak(const dinamis& nilai) { STD cout << nilai << "\n"; }
