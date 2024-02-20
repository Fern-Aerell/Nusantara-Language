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
      if(is<int>(dinamis)) {
        return toString(as<int>(temp));
      } else if(is<double>(dinamis)) {
        return toString(as<double>(temp));
      } else if(is<char>(dinamis)) {
        return toString(as<char>(temp));
      } else if(is<std::string>(dinamis)) {
        return as<std::string>(temp);
      } else if(is<bool>(dinamis)) {
        return toString(as<bool>(temp));
      } else {
        throw std::runtime_error(std::format(
            "Tipe {} tidak bisa untuk di ubah ke string.\n",
            dinamis.type().name()
        ));
      }
    }
    return "kosong";
  }

  // Operator Aritmatika
  inline dinamis operator+(dinamis& nilaiX, dinamis& nilaiY) {
    // int + int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) + as<int>(nilaiY);
    }
    // float + float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) + as<float>(nilaiY);
    }
    // double + double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) + as<double>(nilaiY);
    }
    // int + float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) + as<float>(nilaiY);
    }
    // int  + double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) + as<double>(nilaiY);
    }
    // float + int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) + (float)as<int>(nilaiY);
    }
    // double + int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) + (double)as<int>(nilaiY);
    }
    // string + string = string
    if(is<std::string>(nilaiX) && is<std::string>(nilaiY)) {
      return as<std::string>(nilaiX) + as<std::string>(nilaiY);
    }
    // char + char = string
    if(is<char>(nilaiX) && is<char>(nilaiY)) {
      return std::string(1, as<char>(nilaiX)) + as<char>(nilaiY);
    }
    // string + char = string
    if(is<std::string>(nilaiX) && is<char>(nilaiY)) {
      return as<std::string>(nilaiX) + as<char>(nilaiY);
    }
    // char + string = string
    if(is<char>(nilaiX) && is<std::string>(nilaiY)) {
      return as<char>(nilaiX) + as<std::string>(nilaiY);
    }
    throw std::runtime_error("Operasi penjumlahan tidak valid.");
  }

  inline dinamis operator-(dinamis& nilaiX, dinamis& nilaiY) {
    // int - int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) - as<int>(nilaiY);
    }
    // float - float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) - as<float>(nilaiY);
    }
    // double - double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) - as<double>(nilaiY);
    }
    // int - float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) - as<float>(nilaiY);
    }
    // int  - double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) - as<double>(nilaiY);
    }
    // float - int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) - (float)as<int>(nilaiY);
    }
    // double - int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) - (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi pengurangan tidak valid.");
  }

  inline dinamis operator*(dinamis& nilaiX, dinamis& nilaiY) {
    // int * int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) * as<int>(nilaiY);
    }
    // float * float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) * as<float>(nilaiY);
    }
    // double * double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) * as<double>(nilaiY);
    }
    // int * float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) * as<float>(nilaiY);
    }
    // int  * double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) * as<double>(nilaiY);
    }
    // float * int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) * (float)as<int>(nilaiY);
    }
    // double * int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) * (double)as<int>(nilaiY);
    }
    // string * int = string
    if(is<std::string>(nilaiX) && is<int>(nilaiY)) {
      std::ostringstream stream;
      for(size_t index = 0; index < as<int>(nilaiY); ++index) {
        stream << as<std::string>(nilaiX);
      }
      return stream.str();
    }
    throw std::runtime_error("Operasi perkalian tidak valid.");
  }

  inline dinamis operator/(dinamis& nilaiX, dinamis& nilaiY) {
    // int / int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) / as<int>(nilaiY);
    }
    // float / float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) / as<float>(nilaiY);
    }
    // double / double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) / as<double>(nilaiY);
    }
    // int / float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) / as<float>(nilaiY);
    }
    // int  / double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) / as<double>(nilaiY);
    }
    // float / int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) / (float)as<int>(nilaiY);
    }
    // double / int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) / (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi pembagian tidak valid.");
  }

  inline dinamis operator%(dinamis& nilaiX, dinamis& nilaiY) {
    // int % int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) % as<int>(nilaiY);
    }
    // float % float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return std::fmodf(as<float>(nilaiX), as<float>(nilaiY));
    }
    // double % double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return std::fmod(as<double>(nilaiX), as<double>(nilaiY));
    }
    // int % float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return std::fmodf((float)as<int>(nilaiX), as<float>(nilaiY));
    }
    // int  % double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return std::fmod((double)as<int>(nilaiX), as<double>(nilaiY));
    }
    // float % int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return std::fmodf(as<float>(nilaiX), (float)as<int>(nilaiY));
    }
    // double % int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return std::fmod(as<double>(nilaiX), (double)as<int>(nilaiY));
    }
    throw std::runtime_error("Operasi sisa pembagian tidak valid.");
  }

  inline dinamis operator++(dinamis& nilaiX) {
    // int++
    if(is<int>(nilaiX)) { return as<int>(nilaiX) + 1; }
    // float++
    if(is<float>(nilaiX)) { return as<float>(nilaiX) + 1; }
    // double++
    if(is<double>(nilaiX)) { return as<double>(nilaiX) + 1; }
    throw std::runtime_error("Operasi tambah satu tidak valid.");
  }

  inline dinamis operator--(dinamis& nilaiX) {
    // int--
    if(is<int>(nilaiX)) { return as<int>(nilaiX) - 1; }
    // float--
    if(is<float>(nilaiX)) { return as<float>(nilaiX) - 1; }
    // double--
    if(is<double>(nilaiX)) { return as<double>(nilaiX) - 1; }
    throw std::runtime_error("Operasi tambah satu tidak valid.");
  }

  // Operator Perbandingan
  inline dinamis operator==(dinamis& nilaiX, dinamis& nilaiY) {
    // int == int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) == as<int>(nilaiY);
    }
    // float == float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) == as<float>(nilaiY);
    }
    // double == double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) == as<double>(nilaiY);
    }
    // int == float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) == as<float>(nilaiY);
    }
    // int  == double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) == as<double>(nilaiY);
    }
    // float == int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) == (float)as<int>(nilaiY);
    }
    // double == int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) == (double)as<int>(nilaiY);
    }
    // string == string = bool
    if(is<std::string>(nilaiX) && is<std::string>(nilaiY)) {
      return as<std::string>(nilaiX) == as<std::string>(nilaiY);
    }
    // char == char = bool
    if(is<char>(nilaiX) && is<char>(nilaiY)) {
      return as<char>(nilaiX) == as<char>(nilaiY);
    }
    // string == char = bool
    if(is<std::string>(nilaiX) && is<char>(nilaiY)) {
      return as<std::string>(nilaiX) == toString(as<char>(nilaiY));
    }
    // char == string = bool
    if(is<char>(nilaiX) && is<std::string>(nilaiY)) {
      return toString(as<char>(nilaiX)) == as<std::string>(nilaiY);
    }
    // bool == bool = bool
    if(is<bool>(nilaiX) && is<bool>(nilaiY)) {
      return as<bool>(nilaiX) == as<bool>(nilaiY);
    }
    throw std::runtime_error("Operasi persamaan tidak valid.");
  }

  inline dinamis operator!=(dinamis& nilaiX, dinamis& nilaiY) {
    // int != int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) != as<int>(nilaiY);
    }
    // float != float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) != as<float>(nilaiY);
    }
    // double != double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) != as<double>(nilaiY);
    }
    // int != float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) != as<float>(nilaiY);
    }
    // int  != double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) != as<double>(nilaiY);
    }
    // float != int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) != (float)as<int>(nilaiY);
    }
    // double != int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) != (double)as<int>(nilaiY);
    }
    // string != string = bool
    if(is<std::string>(nilaiX) && is<std::string>(nilaiY)) {
      return as<std::string>(nilaiX) != as<std::string>(nilaiY);
    }
    // char != char = bool
    if(is<char>(nilaiX) && is<char>(nilaiY)) {
      return as<char>(nilaiX) != as<char>(nilaiY);
    }
    // string != char = bool
    if(is<std::string>(nilaiX) && is<char>(nilaiY)) {
      return as<std::string>(nilaiX) != toString(as<char>(nilaiY));
    }
    // char != string = bool
    if(is<char>(nilaiX) && is<std::string>(nilaiY)) {
      return toString(as<char>(nilaiX)) != as<std::string>(nilaiY);
    }
    // bool != bool = bool
    if(is<bool>(nilaiX) && is<bool>(nilaiY)) {
      return as<bool>(nilaiX) != as<bool>(nilaiY);
    }
    throw std::runtime_error("Operasi pertidaksamaan tidak valid.");
  }

  inline dinamis operator>(dinamis& nilaiX, dinamis& nilaiY) {
    // int > int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) > as<int>(nilaiY);
    }
    // float > float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) > as<float>(nilaiY);
    }
    // double > double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) > as<double>(nilaiY);
    }
    // int > float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) > as<float>(nilaiY);
    }
    // int  > double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) > as<double>(nilaiY);
    }
    // float > int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) > (float)as<int>(nilaiY);
    }
    // double > int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) > (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih besar tidak valid.");
  }

  inline dinamis operator<(dinamis& nilaiX, dinamis& nilaiY) {
    // int < int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) < as<int>(nilaiY);
    }
    // float < float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) < as<float>(nilaiY);
    }
    // double < double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) < as<double>(nilaiY);
    }
    // int < float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) < as<float>(nilaiY);
    }
    // int  < double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) < as<double>(nilaiY);
    }
    // float < int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) < (float)as<int>(nilaiY);
    }
    // double < int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) < (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih kecil tidak valid.");
  }

  inline dinamis operator>=(dinamis& nilaiX, dinamis& nilaiY) {
    // int >= int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) >= as<int>(nilaiY);
    }
    // float >= float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) >= as<float>(nilaiY);
    }
    // double >= double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) >= as<double>(nilaiY);
    }
    // int >= float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) >= as<float>(nilaiY);
    }
    // int  >= double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) >= as<double>(nilaiY);
    }
    // float >= int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) >= (float)as<int>(nilaiY);
    }
    // double >= int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) >= (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih besar sama dengan tidak valid.");
  }

  inline dinamis operator<=(dinamis& nilaiX, dinamis& nilaiY) {
    // int <= int = bool
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      return as<int>(nilaiX) <= as<int>(nilaiY);
    }
    // float <= float = bool
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      return as<float>(nilaiX) <= as<float>(nilaiY);
    }
    // double <= double = bool
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      return as<double>(nilaiX) <= as<double>(nilaiY);
    }
    // int <= float = bool
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      return (float)as<int>(nilaiX) <= as<float>(nilaiY);
    }
    // int  <= double = bool
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      return (double)as<int>(nilaiX) <= as<double>(nilaiY);
    }
    // float <= int = bool
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      return as<float>(nilaiX) <= (float)as<int>(nilaiY);
    }
    // double <= int = bool
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      return as<double>(nilaiX) <= (double)as<int>(nilaiY);
    }
    throw std::runtime_error("Operasi lebih kecil sama dengan tidak valid.");
  }

  // Operator Penugasan
  inline dinamis operator+=(dinamis& nilaiX, dinamis& nilaiY) {
    // int += int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<int>(nilaiX) + as<int>(nilaiY);
      return nilaiX;
    }
    // float += float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = as<float>(nilaiX) + as<float>(nilaiY);
      return nilaiX;
    }
    // double += double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = as<double>(nilaiX) + as<double>(nilaiY);
      return nilaiX;
    }
    // int += float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = (float)as<int>(nilaiX) + as<float>(nilaiY);
      return nilaiX;
    }
    // int  += double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = (double)as<int>(nilaiX) + as<double>(nilaiY);
      return nilaiX;
    }
    // float += int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<float>(nilaiX) + (float)as<int>(nilaiY);
      return nilaiX;
    }
    // double += int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<double>(nilaiX) + (double)as<int>(nilaiY);
      return nilaiX;
    }
    // string += string = string
    if(is<std::string>(nilaiX) && is<std::string>(nilaiY)) {
      nilaiX = as<std::string>(nilaiX) + as<std::string>(nilaiY);
      return nilaiX;
    }
    // char += char = string
    if(is<char>(nilaiX) && is<char>(nilaiY)) {
      nilaiX = std::string(1, as<char>(nilaiX)) + as<char>(nilaiY);
      return nilaiX;
    }
    // string += char = char
    if(is<std::string>(nilaiX) && is<char>(nilaiY)) {
      nilaiX = as<std::string>(nilaiX) + as<char>(nilaiY);
      return nilaiX;
    }
    // char += string = string
    if(is<char>(nilaiX) && is<std::string>(nilaiY)) {
      nilaiX = as<char>(nilaiX) + as<std::string>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan tambah tidak valid.");
  }

  inline dinamis operator-=(dinamis& nilaiX, dinamis& nilaiY) {
    // int -= int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<int>(nilaiX) - as<int>(nilaiY);
      return nilaiX;
    }
    // float -= float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = as<float>(nilaiX) - as<float>(nilaiY);
      return nilaiX;
    }
    // double -= double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = as<double>(nilaiX) - as<double>(nilaiY);
      return nilaiX;
    }
    // int -= float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = (float)as<int>(nilaiX) - as<float>(nilaiY);
      return nilaiX;
    }
    // int  -= double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = (double)as<int>(nilaiX) - as<double>(nilaiY);
      return nilaiX;
    }
    // float -= int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<float>(nilaiX) - (float)as<int>(nilaiY);
      return nilaiX;
    }
    // double -= int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<double>(nilaiX) - (double)as<int>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan kurang tidak valid.");
  }

  inline dinamis operator*=(dinamis& nilaiX, dinamis& nilaiY) {
    // int *= int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<int>(nilaiX) * as<int>(nilaiY);
      return nilaiX;
    }
    // float *= float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = as<float>(nilaiX) * as<float>(nilaiY);
      return nilaiX;
    }
    // double *= double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = as<double>(nilaiX) * as<double>(nilaiY);
      return nilaiX;
    }
    // int *= float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = (float)as<int>(nilaiX) * as<float>(nilaiY);
      return nilaiX;
    }
    // int *= double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = (double)as<int>(nilaiX) * as<double>(nilaiY);
      return nilaiX;
    }
    // float *= int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<float>(nilaiX) * (float)as<int>(nilaiY);
      return nilaiX;
    }
    // double *= int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<double>(nilaiX) * (double)as<int>(nilaiY);
      return nilaiX;
    }
    // string *= int = string
    if(is<std::string>(nilaiX) && is<int>(nilaiY)) {
      std::ostringstream stream;
      for(size_t index = 0; index < as<int>(nilaiY); ++index) {
        stream << as<std::string>(nilaiX);
      }
      nilaiX = stream.str();
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan kali tidak valid.");
  }

  inline dinamis operator/=(dinamis& nilaiX, dinamis& nilaiY) {
    // int /= int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<int>(nilaiX) / as<int>(nilaiY);
      return nilaiX;
    }
    // float /= float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = as<float>(nilaiX) / as<float>(nilaiY);
      return nilaiX;
    }
    // double /= double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = as<double>(nilaiX) / as<double>(nilaiY);
      return nilaiX;
    }
    // int /= float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = (float)as<int>(nilaiX) / as<float>(nilaiY);
      return nilaiX;
    }
    // int  /= double = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = (double)as<int>(nilaiX) / as<double>(nilaiY);
      return nilaiX;
    }
    // float /= int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<float>(nilaiX) / (float)as<int>(nilaiY);
      return nilaiX;
    }
    // double /= int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<double>(nilaiX) / (double)as<int>(nilaiY);
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan bagi tidak valid.");
  }

  inline dinamis operator%=(dinamis& nilaiX, dinamis& nilaiY) {
    // int %= int = int
    if(is<int>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = as<int>(nilaiX) % as<int>(nilaiY);
      return nilaiX;
    }
    // float %= float = float
    if(is<float>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = std::fmodf(as<float>(nilaiX), as<float>(nilaiY));
      return nilaiX;
    }
    // double %= double = double
    if(is<double>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = std::fmod(as<double>(nilaiX), as<double>(nilaiY));
      return nilaiX;
    }
    // int %= float = float
    if(is<int>(nilaiX) && is<float>(nilaiY)) {
      nilaiX = std::fmodf((float)as<int>(nilaiX), as<float>(nilaiY));
      return nilaiX;
    }
    // int  %= double  = double
    if(is<int>(nilaiX) && is<double>(nilaiY)) {
      nilaiX = std::fmod((double)as<int>(nilaiX), as<double>(nilaiY));
      return nilaiX;
    }
    // float %= int = float
    if(is<float>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = std::fmodf(as<float>(nilaiX), (float)as<int>(nilaiY));
      return nilaiX;
    }
    // double %= int = double
    if(is<double>(nilaiX) && is<int>(nilaiY)) {
      nilaiX = std::fmod(as<double>(nilaiX), (double)as<int>(nilaiY));
      return nilaiX;
    }
    throw std::runtime_error("Operasi penugasan sisa bagi tidak valid.");
  }

}  // namespace nstd
