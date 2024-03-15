#include <exception>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/dinamis.h"

int main() {
    ncpp::konsol myKonsol(true);
    try {
			ncpp::dinamis data("Aerell");
      myKonsol.cetak_baris_baru(data);
			data = ncpp::dinamis(10);
      myKonsol.cetak_baris_baru(data);
    } catch (const std::exception& error) {
      myKonsol.cetak_baris_baru(error.what());
    }
    return 0;
}
