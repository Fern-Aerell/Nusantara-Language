#pragma once

#include <any>
#include <cmath>
#include <format>
#include <sstream>
#include <stdexcept>
#include <string>

#include "benarsalah.h"
#include "bilangan.h"
#include "karakter.h"

namespace nstd {

  using dinamis = std::any;

  inline bool kosong(const dinamis& dinamis) { return !dinamis.has_value(); }

  inline bool tidakKosong(const dinamis& dinamis) {
    return dinamis.has_value();
  }

  template<typename Tipe>
  inline bool is(const dinamis& dinamis) {
    if(tidakKosong(dinamis)) { return dinamis.type() == typeid(Tipe); }
    return false;
  }

  template<typename Tipe>
  inline Tipe& as(dinamis& dinamis) {
    if(tidakKosong(dinamis)) {
      if(is<Tipe>(dinamis)) { return std::any_cast<Tipe&>(dinamis); }
    }
    throw std::runtime_error(
        std::format("dinamis bukan {}.", typeid(Tipe).name())
    );
  }

  inline std::string toString(const dinamis& dinamis) {
    nstd::dinamis temp = dinamis;
    if(tidakKosong(dinamis)) {
      if(nstd::is<int>(dinamis)) {
        return nstd::toString(nstd::as<int>(temp));
      } else if(nstd::is<double>(dinamis)) {
        return nstd::toString(nstd::as<double>(temp));
      } else if(nstd::is<char>(dinamis)) {
        return nstd::toString(nstd::as<char>(temp));
      } else if(nstd::is<std::string>(dinamis)) {
        return nstd::as<std::string>(temp);
      } else if(nstd::is<bool>(dinamis)) {
        return nstd::toString(nstd::as<bool>(temp));
      } else {
        throw std::runtime_error(std::format(
            "Tipe {} tidak bisa untuk di ubah ke string.\n",
            dinamis.type().name()
        ));
      }
    }
    return "kosong";
  } 
}  // namespace nstd

// Operator Aritmatika
  inline nstd::dinamis operator+(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int + int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) + nstd::as<int>(nilaiY);
    }
    // float + float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) + nstd::as<float>(nilaiY);
    }
    // double + double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) + nstd::as<double>(nilaiY);
    }
    // int + float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) + nstd::as<float>(nilaiY);
    }
    // int  + double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) + nstd::as<double>(nilaiY);
    }
    // float + int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) + (float)nstd::as<int>(nilaiY);
    }
    // double + int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) + (double)nstd::as<int>(nilaiY);
    }
    // string + string = string
    if(nstd::is<std::string>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) + nstd::as<std::string>(nilaiY);
    }
    // char + char = string
    if(nstd::is<char>(nilaiX) && nstd::is<char>(nilaiY)) {
      return std::string(1, nstd::as<char>(nilaiX)) + nstd::as<char>(nilaiY);
    }
    // string + char = string
    if(nstd::is<std::string>(nilaiX) && nstd::is<char>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) + nstd::as<char>(nilaiY);
    }
    // char + string = string
    if(nstd::is<char>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::as<char>(nilaiX) + nstd::as<std::string>(nilaiY);
    }
    throw std::runtime_error("Operasi penjumlahan tidak valid.");
  }

  inline nstd::dinamis operator-(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int - int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) - nstd::as<int>(nilaiY);
    }
    // float - float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) - nstd::as<float>(nilaiY);
    }
    // double - double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) - nstd::as<double>(nilaiY);
    }
    // int - float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) - nstd::as<float>(nilaiY);
    }
    // int  - double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) - nstd::as<double>(nilaiY);
    }
    // float - int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) - (float)nstd::as<int>(nilaiY);
    }
    // double - int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) - (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi pengurangan tidak valid.");
  }

  inline nstd::dinamis operator*(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int * int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) * nstd::as<int>(nilaiY);
    }
    // float * float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) * nstd::as<float>(nilaiY);
    }
    // double * double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) * nstd::as<double>(nilaiY);
    }
    // int * float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) * nstd::as<float>(nilaiY);
    }
    // int  * double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) * nstd::as<double>(nilaiY);
    }
    // float * int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) * (float)nstd::as<int>(nilaiY);
    }
    // double * int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) * (double)nstd::as<int>(nilaiY);
    }
    // string * int = string
    if(nstd::is<std::string>(nilaiX) && nstd::is<int>(nilaiY)) {
      std::ostringstream stream;
      for(size_t index = 0; index < nstd::as<int>(nilaiY); ++index) {
        stream << nstd::as<std::string>(nilaiX);
      }
      return stream.str();
    }
    throw std::runtime_error("Operasi perkalian tidak valid.");
  }

  inline nstd::dinamis operator/(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int / int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) / nstd::as<int>(nilaiY);
    }
    // float / float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) / nstd::as<float>(nilaiY);
    }
    // double / double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) / nstd::as<double>(nilaiY);
    }
    // int / float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) / nstd::as<float>(nilaiY);
    }
    // int  / double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) / nstd::as<double>(nilaiY);
    }
    // float / int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) / (float)nstd::as<int>(nilaiY);
    }
    // double / int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) / (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi pembagian tidak valid.");
  }

  inline nstd::dinamis operator%(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int % int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) % nstd::as<int>(nilaiY);
    }
    // float % float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return fmodf(nstd::as<float>(nilaiX), nstd::as<float>(nilaiY));
    }
    // double % double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return std::fmod(nstd::as<double>(nilaiX), nstd::as<double>(nilaiY));
    }
    // int % float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return fmodf((float)nstd::as<int>(nilaiX), nstd::as<float>(nilaiY));
    }
    // int  % double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return std::fmod((double)nstd::as<int>(nilaiX), nstd::as<double>(nilaiY));
    }
    // float % int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return fmodf(nstd::as<float>(nilaiX), (float)nstd::as<int>(nilaiY));
    }
    // double % int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return std::fmod(nstd::as<double>(nilaiX), (double)nstd::as<int>(nilaiY));
    }
    throw std::runtime_error("Operasi sisa pembagian tidak valid.");
  }

  inline nstd::dinamis operator++(nstd::dinamis nilaiX) {
    // int++
    if(nstd::is<int>(nilaiX)) { return nstd::as<int>(nilaiX) + 1; }
    // float++
    if(nstd::is<float>(nilaiX)) { return nstd::as<float>(nilaiX) + 1; }
    // double++
    if(nstd::is<double>(nilaiX)) { return nstd::as<double>(nilaiX) + 1; }
    throw std::runtime_error("Operasi tambah satu tidak valid.");
  }

  inline nstd::dinamis operator--(nstd::dinamis nilaiX) {
    // int--
    if(nstd::is<int>(nilaiX)) { return nstd::as<int>(nilaiX) - 1; }
    // float--
    if(nstd::is<float>(nilaiX)) { return nstd::as<float>(nilaiX) - 1; }
    // double--
    if(nstd::is<double>(nilaiX)) { return nstd::as<double>(nilaiX) - 1; }
    throw std::runtime_error("Operasi tambah satu tidak valid.");
  }

  // Operator Perbandingan
  inline nstd::dinamis operator==(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int == int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) == nstd::as<int>(nilaiY);
    }
    // float == float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) == nstd::as<float>(nilaiY);
    }
    // double == double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) == nstd::as<double>(nilaiY);
    }
    // int == float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) == nstd::as<float>(nilaiY);
    }
    // int  == double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) == nstd::as<double>(nilaiY);
    }
    // float == int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) == (float)nstd::as<int>(nilaiY);
    }
    // double == int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) == (double)nstd::as<int>(nilaiY);
    }
    // string == string = bool
    if(nstd::is<std::string>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) == nstd::as<std::string>(nilaiY);
    }
    // char == char = bool
    if(nstd::is<char>(nilaiX) && nstd::is<char>(nilaiY)) {
      return nstd::as<char>(nilaiX) == nstd::as<char>(nilaiY);
    }
    // string == char = bool
    if(nstd::is<std::string>(nilaiX) && nstd::is<char>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) == nstd::toString(nstd::as<char>(nilaiY));
    }
    // char == string = bool
    if(nstd::is<char>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::toString(nstd::as<char>(nilaiX)) == nstd::as<std::string>(nilaiY);
    }
    // bool == bool = bool
    if(nstd::is<bool>(nilaiX) && nstd::is<bool>(nilaiY)) {
      return nstd::as<bool>(nilaiX) == nstd::as<bool>(nilaiY);
    }
    throw std::runtime_error("Operasi persamaan tidak valid.");
  }

  inline nstd::dinamis operator!=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int != int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) != nstd::as<int>(nilaiY);
    }
    // float != float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) != nstd::as<float>(nilaiY);
    }
    // double != double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) != nstd::as<double>(nilaiY);
    }
    // int != float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) != nstd::as<float>(nilaiY);
    }
    // int  != double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) != nstd::as<double>(nilaiY);
    }
    // float != int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) != (float)nstd::as<int>(nilaiY);
    }
    // double != int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) != (double)nstd::as<int>(nilaiY);
    }
    // string != string = bool
    if(nstd::is<std::string>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) != nstd::as<std::string>(nilaiY);
    }
    // char != char = bool
    if(nstd::is<char>(nilaiX) && nstd::is<char>(nilaiY)) {
      return nstd::as<char>(nilaiX) != nstd::as<char>(nilaiY);
    }
    // string != char = bool
    if(nstd::is<std::string>(nilaiX) && nstd::is<char>(nilaiY)) {
      return nstd::as<std::string>(nilaiX) != nstd::toString(nstd::as<char>(nilaiY));
    }
    // char != string = bool
    if(nstd::is<char>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      return nstd::toString(nstd::as<char>(nilaiX)) != nstd::as<std::string>(nilaiY);
    }
    // bool != bool = bool
    if(nstd::is<bool>(nilaiX) && nstd::is<bool>(nilaiY)) {
      return nstd::as<bool>(nilaiX) != nstd::as<bool>(nilaiY);
    }
    throw std::runtime_error("Operasi pertidaksamaan tidak valid.");
  }

  inline nstd::dinamis operator>(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int > int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) > nstd::as<int>(nilaiY);
    }
    // float > float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) > nstd::as<float>(nilaiY);
    }
    // double > double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) > nstd::as<double>(nilaiY);
    }
    // int > float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) > nstd::as<float>(nilaiY);
    }
    // int  > double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) > nstd::as<double>(nilaiY);
    }
    // float > int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) > (float)nstd::as<int>(nilaiY);
    }
    // double > int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) > (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih besar tidak valid.");
  }

  inline nstd::dinamis operator<(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int < int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) < nstd::as<int>(nilaiY);
    }
    // float < float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) < nstd::as<float>(nilaiY);
    }
    // double < double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) < nstd::as<double>(nilaiY);
    }
    // int < float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) < nstd::as<float>(nilaiY);
    }
    // int  < double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) < nstd::as<double>(nilaiY);
    }
    // float < int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) < (float)nstd::as<int>(nilaiY);
    }
    // double < int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) < (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih kecil tidak valid.");
  }

  inline nstd::dinamis operator>=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int >= int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) >= nstd::as<int>(nilaiY);
    }
    // float >= float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) >= nstd::as<float>(nilaiY);
    }
    // double >= double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) >= nstd::as<double>(nilaiY);
    }
    // int >= float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) >= nstd::as<float>(nilaiY);
    }
    // int  >= double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) >= nstd::as<double>(nilaiY);
    }
    // float >= int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) >= (float)nstd::as<int>(nilaiY);
    }
    // double >= int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) >= (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih besar sama dengan tidak valid.");
  }

  inline nstd::dinamis operator<=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int <= int = bool
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) <= nstd::as<int>(nilaiY);
    }
    // float <= float = bool
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      return nstd::as<float>(nilaiX) <= nstd::as<float>(nilaiY);
    }
    // double <= double = bool
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      return nstd::as<double>(nilaiX) <= nstd::as<double>(nilaiY);
    }
    // int <= float = bool
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      return (float)nstd::as<int>(nilaiX) <= nstd::as<float>(nilaiY);
    }
    // int  <= double = bool
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      return (double)nstd::as<int>(nilaiX) <= nstd::as<double>(nilaiY);
    }
    // float <= int = bool
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<float>(nilaiX) <= (float)nstd::as<int>(nilaiY);
    }
    // double <= int = bool
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<double>(nilaiX) <= (double)nstd::as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih kecil sama dengan tidak valid.");
  }

  // Operator Penugasan	
  inline nstd::dinamis operator+=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int += int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) + nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // float += float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) + nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // double += double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) + nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // int += float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = (float)nstd::as<int>(nilaiX) + nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // int  += double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = (double)nstd::as<int>(nilaiX) + nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // float += int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) + (float)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // double += int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) + (double)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // string += string = string
    if(nstd::is<std::string>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      nilaiX = nstd::as<std::string>(nilaiX) + nstd::as<std::string>(nilaiY);
      return nilaiX;
    }
    // char += char = string
    if(nstd::is<char>(nilaiX) && nstd::is<char>(nilaiY)) {
      nilaiX = std::string(1, nstd::as<char>(nilaiX)) + nstd::as<char>(nilaiY);
      return nilaiX;
    }
    // string += char = char
    if(nstd::is<std::string>(nilaiX) && nstd::is<char>(nilaiY)) {
      nilaiX = nstd::as<std::string>(nilaiX) + nstd::as<char>(nilaiY);
      return nilaiX;
    }
    // char += string = string
    if(nstd::is<char>(nilaiX) && nstd::is<std::string>(nilaiY)) {
      nilaiX = nstd::as<char>(nilaiX) + nstd::as<std::string>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan tambah tidak valid.");
  }

  inline nstd::dinamis operator-=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int -= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) - nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // float -= float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) - nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // double -= double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) - nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // int -= float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = (float)nstd::as<int>(nilaiX) - nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // int  -= double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = (double)nstd::as<int>(nilaiX) - nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // float -= int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) - (float)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // double -= int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) - (double)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan kurang tidak valid.");
  }

  inline nstd::dinamis operator*=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int *= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) * nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // float *= float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) * nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // double *= double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) * nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // int *= float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = (float)nstd::as<int>(nilaiX) * nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // int *= double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = (double)nstd::as<int>(nilaiX) * nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // float *= int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) * (float)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // double *= int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) * (double)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // string *= int = string
    if(nstd::is<std::string>(nilaiX) && nstd::is<int>(nilaiY)) {
      std::ostringstream stream;
      for(size_t index = 0; index < nstd::as<int>(nilaiY); ++index) {
        stream << nstd::as<std::string>(nilaiX);
      }
      nilaiX = stream.str();
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan kali tidak valid.");
  }

  inline nstd::dinamis operator/=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int /= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) / nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // float /= float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) / nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // double /= double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) / nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // int /= float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = (float)nstd::as<int>(nilaiX) / nstd::as<float>(nilaiY);
      return nilaiX;
    }
    // int  /= double = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = (double)nstd::as<int>(nilaiX) / nstd::as<double>(nilaiY);
      return nilaiX;
    }
    // float /= int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<float>(nilaiX) / (float)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // double /= int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<double>(nilaiX) / (double)nstd::as<int>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan bagi tidak valid.");
  }

  inline nstd::dinamis operator%=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int %= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) % nstd::as<int>(nilaiY);
      return nilaiX;
    }
    // float %= float = float
    if(nstd::is<float>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = fmodf(nstd::as<float>(nilaiX), nstd::as<float>(nilaiY));
      return nilaiX;
    }
    // double %= double = double
    if(nstd::is<double>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = std::fmod(nstd::as<double>(nilaiX), nstd::as<double>(nilaiY));
      return nilaiX;
    }
    // int %= float = float
    if(nstd::is<int>(nilaiX) && nstd::is<float>(nilaiY)) {
      nilaiX = fmodf((float)nstd::as<int>(nilaiX), nstd::as<float>(nilaiY));
      return nilaiX;
    }
    // int  %= double  = double
    if(nstd::is<int>(nilaiX) && nstd::is<double>(nilaiY)) {
      nilaiX = std::fmod((double)nstd::as<int>(nilaiX), nstd::as<double>(nilaiY));
      return nilaiX;
    }
    // float %= int = float
    if(nstd::is<float>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = fmodf(nstd::as<float>(nilaiX), (float)nstd::as<int>(nilaiY));
      return nilaiX;
    }
    // double %= int = double
    if(nstd::is<double>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = std::fmod(nstd::as<double>(nilaiX), (double)nstd::as<int>(nilaiY));
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan sisa bagi tidak valid.");
  }

	inline nstd::dinamis operator&=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int &= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) & nstd::as<int>(nilaiY);
      return nilaiX;
    } 
    throw std::runtime_error("Operasi penugasan and bit tidak valid.");
  }

	inline nstd::dinamis operator|=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int |= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) | nstd::as<int>(nilaiY);
      return nilaiX;
    } 
    throw std::runtime_error("Operasi penugasan or bit tidak valid.");
  }

	inline nstd::dinamis operator^=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int ^= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) ^ nstd::as<int>(nilaiY);
      return nilaiX;
    } 
    throw std::runtime_error("Operasi penugasan xor bit tidak valid.");
  }

	inline nstd::dinamis operator<<=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int <<= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) << nstd::as<int>(nilaiY);
      return nilaiX;
    } 
    throw std::runtime_error("Operasi penugasan geser kiri bit tidak valid.");
  }

	inline nstd::dinamis operator>>=(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int >>= int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      nilaiX = nstd::as<int>(nilaiX) >> nstd::as<int>(nilaiY);
      return nilaiX;
    } 
    throw std::runtime_error("Operasi penugasan geser kanan bit tidak valid.");
  }

	// Operasi Logika
	inline nstd::dinamis operator&&(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // bool && bool = bool
    if(nstd::is<bool>(nilaiX) && nstd::is<bool>(nilaiY)) {
      return nstd::as<bool>(nilaiX) && nstd::as<bool>(nilaiY);
    } 
    throw std::runtime_error("Operasi dan tidak valid.");
  }

	inline nstd::dinamis operator||(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // bool || bool = bool
    if(nstd::is<bool>(nilaiX) && nstd::is<bool>(nilaiY)) {
      return nstd::as<bool>(nilaiX) || nstd::as<bool>(nilaiY);
    } 
    throw std::runtime_error("Operasi atau tidak valid.");
  }

	inline nstd::dinamis operator!(nstd::dinamis nilaiX) {
    // !bool = bool
    if(nstd::is<bool>(nilaiX)) {
      return !nstd::as<bool>(nilaiX);
    } 
    throw std::runtime_error("Operasi tidak gak valid.");
  }

	// Operasi Bitwise
	inline nstd::dinamis operator&(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int & int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) & nstd::as<int>(nilaiY);
    } 
    throw std::runtime_error("Operasi and bit tidak valid.");
  }

	inline nstd::dinamis operator|(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int | int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) | nstd::as<int>(nilaiY);
    } 
    throw std::runtime_error("Operasi or bit tidak valid.");
  }

	inline nstd::dinamis operator^(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int ^ int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) ^ nstd::as<int>(nilaiY);
    } 
    throw std::runtime_error("Operasi xor bit tidak valid.");
  }

	inline nstd::dinamis operator~(nstd::dinamis nilaiX) {
    // ~int = int
    if(nstd::is<int>(nilaiX)) {
      return ~nstd::as<int>(nilaiX);
    } 
    throw std::runtime_error("Operasi not bit tidak valid.");
  }

	inline nstd::dinamis operator<<(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int << int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) << nstd::as<int>(nilaiY);
    } 
    throw std::runtime_error("Operasi geser kiri bit tidak valid.");
  }

	inline nstd::dinamis operator>>(nstd::dinamis nilaiX, nstd::dinamis nilaiY) {
    // int >> int = int
    if(nstd::is<int>(nilaiX) && nstd::is<int>(nilaiY)) {
      return nstd::as<int>(nilaiX) >> nstd::as<int>(nilaiY);
    } 
    throw std::runtime_error("Operasi geser kanan bit tidak valid.");
  }
