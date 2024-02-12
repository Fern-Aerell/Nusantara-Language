#pragma once

#include <string>

enum class ParserRule : int {
  nusantara = 0,
  operator_penugasan = 1,
  operasi_penugasan = 2,
  operator_penugasan_penjumlahan = 3,
  operasi_penugasan_penjumlahan = 4,
  operator_penugasan_perkalian = 5,
  operasi_penugasan_perkalian = 6,
  operator_logika = 7,
  operasi_logika = 8,
  operator_perbandingan = 9,
  operasi_perbandingan = 10,
  operator_penjumlahan = 11,
  operasi_penjumlahan = 12,
  operator_pre_post = 13,
  operasi_pre_post = 14,
  operator_perkalian = 15,
  operasi_perkalian = 16,
  nilai = 17
};

inline std::string toString(const ParserRule &rule) {
  switch(rule) {
    case ParserRule::nusantara:
      return "nusantara";
    case ParserRule::operator_penugasan:
      return "operator_penugasan";
    case ParserRule::operasi_penugasan:
      return "operasi_penugasan";
    case ParserRule::operator_penugasan_penjumlahan:
      return "operator_penugasan_penjumlahan";
    case ParserRule::operasi_penugasan_penjumlahan:
      return "operasi_penugasan_penjumlahan";
    case ParserRule::operator_penugasan_perkalian:
      return "operator_penugasan_perkalian";
    case ParserRule::operasi_penugasan_perkalian:
      return "operasi_penugasan_perkalian";
    case ParserRule::operator_logika:
      return "operator_logika";
    case ParserRule::operasi_logika:
      return "operasi_logika";
    case ParserRule::operator_perbandingan:
      return "operator_perbandingan";
    case ParserRule::operasi_perbandingan:
      return "operasi_perbandingan";
    case ParserRule::operator_penjumlahan:
      return "operator_penjumlahan";
    case ParserRule::operasi_penjumlahan:
      return "operasi_penjumlahan";
    case ParserRule::operator_pre_post:
      return "operator_pre_post";
    case ParserRule::operasi_pre_post:
      return "operasi_pre_post";
    case ParserRule::operator_perkalian:
      return "operator_perkalian";
    case ParserRule::operasi_perkalian:
      return "operasi_perkalian";
    case ParserRule::nilai:
      return "nilai";
  }
}
