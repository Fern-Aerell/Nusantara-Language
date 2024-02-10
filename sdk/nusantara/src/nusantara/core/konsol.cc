#include "nusantara/core/core.h"
#include <format>
#include <iostream>
#include <nusantara/core/konsol.h>

namespace nstd
{
  void Konsol::cetak(konst<bulat> &bulat) { std::cout << bulat << "\n"; }

  void Konsol::cetak(konst<desimal> &desimal) { std::cout << desimal << "\n"; }

  void Konsol::cetak(konst<karakter> &karakter)
  {
    std::cout << karakter << "\n";
  }

  void Konsol::cetak(konst<kalimat> &kalimat) { std::cout << kalimat << "\n"; }

  void Konsol::cetak(konst<benarsalah> &benarsalah)
  {
    std::cout << benarsalah << "\n";
  }

  void Konsol::cetak(konst<dinamis> &dinamis)
  {
    if(dinamis->has_value())
      {
        if(isBulat(dinamis))
          {
            Konsol::cetak(asBulat(dinamis));
          }
        else if(isDesimal(dinamis))
          {
            Konsol::cetak(asDesimal(dinamis));
          }
        else if(isKarakter(dinamis))
          {
            Konsol::cetak(asKarakter(dinamis));
          }
        else if(isKalimat(dinamis))
          {
            Konsol::cetak(asKalimat(dinamis));
          }
        else if(isBenarSalah(dinamis))
          {
            Konsol::cetak(asBenarSalah(dinamis));
          }
        else
          {
            std::cout << std::format("Tipe {} tidak bisa untuk di cetak.",
                                     dinamis.value().type().name())
                      << "\n";
          }
      }
    else
      {
        std::cout << "kosong"
                  << "\n";
      }
  }
}