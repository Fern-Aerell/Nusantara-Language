#include <cstddef>
#include <nusantara/core/core.h>
#include <format>
#include <stdexcept>
#include <string>

namespace nstd
{

  benarsalah isKosong(const dinamis &dinamis) { return !dinamis.has_value(); }

  benarsalah isTidakAda(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return !dinamis.value().has_value();
      }
    return false;
  }

  benarsalah isBulat(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return dinamis.value().type() == typeid(bulat);
      }
    return false;
  }

  benarsalah isDesimal(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return dinamis.value().type() == typeid(desimal);
      }
    return false;
  }

  benarsalah isKarakter(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return dinamis.value().type() == typeid(karakter);
      }
    return false;
  }

  benarsalah isKalimat(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return dinamis.value().type() == typeid(kalimat);
      }
    return false;
  }

  benarsalah isBenarSalah(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        return dinamis.value().type() == typeid(benarsalah);
      }
    return false;
  }

  bulat asBulat(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        if(isBulat(dinamis))
          {
            return std::any_cast<bulat>(dinamis.value());
          }
      }
    throw std::runtime_error("dinamis bukan bilangan bulat.");
  }

  desimal asDesimal(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        if(isDesimal(dinamis))
          {
            return std::any_cast<desimal>(dinamis.value());
          }
      }
    throw std::runtime_error("dinamis bukan bilangan desimal.");
  }

  karakter asKarakter(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        if(isKarakter(dinamis))
          {
            return std::any_cast<karakter>(dinamis.value());
          }
      }
    throw std::runtime_error("dinamis bukan karakter.");
  }

  kalimat asKalimat(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        if(isKalimat(dinamis))
          {
            return std::any_cast<kalimat>(dinamis.value());
          }
      }
    throw std::runtime_error("dinamis bukan kalimat.");
  }

  benarsalah asBenarSalah(const dinamis &dinamis)
  {
    if(!isKosong(dinamis))
      {
        if(isBenarSalah(dinamis))
          {
            return std::any_cast<benarsalah>(dinamis.value());
          }
      }
    throw std::runtime_error("dinamis bukan benar atau salah.");
  }

  kalimat ubahKeKalimat(konst<bulat> &bulat) { return std::to_string(bulat); }

  kalimat ubahKeKalimat(konst<desimal> &desimal)
  {
    kalimat klmt = std::to_string(desimal);
    size_t pos = klmt.find('.');
    if(pos != kalimat::npos)
      {
        size_t end = klmt.find_last_not_of('0');
        if(end != kalimat::npos && end > pos)
          {
            klmt.erase(end + 1);
          }
        if(klmt.back() == '.')
          {
            klmt.pop_back();
          }
      }
    klmt.replace(klmt.find('.'), 1, ",");
    return klmt;
  }

  kalimat ubahKeKalimat(konst<karakter> &karakter) { return {1, karakter}; }

  kalimat ubahKeKalimat(konst<benarsalah> &benarsalah)
  {
    return (benarsalah) ? "benar" : "salah";
  }
}