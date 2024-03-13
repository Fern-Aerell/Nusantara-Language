#include <exception>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/peta.h"
#include "ncpp/tipe_data/teks.h"

int main() {
    ncpp::konsol myKonsol(true);
    try {
			ncpp::peta<ncpp::teks, ncpp::teks> data(
        {
          {ncpp::teks("Nama"), ncpp::teks("Fern Aerell")},
          {ncpp::teks("Kelas"), ncpp::teks("XI PPLG")},
          {ncpp::teks("Umur"), ncpp::teks("18")}
        }
      );
      myKonsol.cetak_baris_baru(data);
    } catch (const std::exception& error) {
      myKonsol.cetak_baris_baru(error.what());
    }
    return 0;
}
