#include <nusantara/core/core.h>

#include <cstddef>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>

namespace nstd {

benarsalah isKosong(const dinamis &dinamis) { return !dinamis.has_value(); }

benarsalah isTidakAda(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return !dinamis.value().has_value();
  }
  return false;
}

benarsalah isBulat(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(bulat);
  }
  return false;
}

benarsalah isDesimal(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(desimal);
  }
  return false;
}

benarsalah isKarakter(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(karakter);
  }
  return false;
}

benarsalah isKalimat(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(kalimat);
  }
  return false;
}

benarsalah isBenarSalah(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    return dinamis.value().type() == typeid(benarsalah);
  }
  return false;
}

bulat asBulat(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isBulat(dinamis)) {
      return std::any_cast<bulat>(dinamis.value());
    }
  }
  throw std::runtime_error("dinamis bukan bilangan bulat.");
}

desimal asDesimal(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isDesimal(dinamis)) {
      return std::any_cast<desimal>(dinamis.value());
    }
  }
  throw std::runtime_error("dinamis bukan bilangan desimal.");
}

karakter asKarakter(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isKarakter(dinamis)) {
      return std::any_cast<karakter>(dinamis.value());
    }
  }
  throw std::runtime_error("dinamis bukan karakter.");
}

kalimat asKalimat(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isKalimat(dinamis)) {
      return std::any_cast<kalimat>(dinamis.value());
    }
  }
  throw std::runtime_error("dinamis bukan kalimat.");
}

benarsalah asBenarSalah(const dinamis &dinamis) {
  if (!isKosong(dinamis)) {
    if (isBenarSalah(dinamis)) {
      return std::any_cast<benarsalah>(dinamis.value());
    }
  }
  throw std::runtime_error("dinamis bukan benar atau salah.");
}

kalimat ubahKeKalimat(konst<bulat> &bulat) { return std::to_string(bulat); }

kalimat ubahKeKalimat(konst<desimal> &desimal) {
  kalimat klmt = std::to_string(desimal);
  size_t pos = klmt.find('.');

  // Jika ada koma
  if (pos != kalimat::npos) {
    // Hapus angka-angka nol dari belakang desimal
    size_t end = klmt.find_last_not_of('0');

    // Jika tidak ada digit nol setelah koma
    if (end == pos) {
      klmt.erase(pos);  // Hapus koma
    } else if (end != kalimat::npos && end > pos) {
      klmt.erase(end + 1);
    }
  }

  // Ganti titik dengan koma
  std::replace(klmt.begin(), klmt.end(), '.', ',');
  return klmt;
}

kalimat ubahKeKalimat(konst<karakter> &karakter) { return {0, karakter}; }

kalimat ubahKeKalimat(konst<benarsalah> &benarsalah) {
  return (benarsalah) ? "benar" : "salah";
}

kalimat ubahKeKalimat(konst<dinamis> &dinamis) {
  if (dinamis->has_value()) {
    if (isBulat(dinamis)) {
      return ubahKeKalimat(asBulat(dinamis));
    } else if (isDesimal(dinamis)) {
      return ubahKeKalimat(asDesimal(dinamis));
    } else if (isKarakter(dinamis)) {
      return ubahKeKalimat(asKarakter(dinamis));
    } else if (isKalimat(dinamis)) {
      return ubahKeKalimat(asKalimat(dinamis));
    } else if (isBenarSalah(dinamis)) {
      return ubahKeKalimat(asBenarSalah(dinamis));
    } else {
      throw std::runtime_error(
          std::format("Tipe {} tidak bisa untuk di ubah ke kalimat.\n",
                      dinamis.value().type().name()));
    }
  } else {
    return "kosong";
  }
}

}  // namespace nstd