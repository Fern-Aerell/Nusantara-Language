#pragma once

#include <string>

enum class ParserRule : int {
  nusantara,
  operator_penugasan,
  operasi_penugasan,
  operator_penugasan_penjumlahan,
  operasi_penugasan_penjumlahan,
  operator_penugasan_perkalian,
  operasi_penugasan_perkalian,
  operator_logika,
  operasi_logika,
  operator_logika_tidak,
  operasi_logika_tidak,
  operator_perbandingan,
  operasi_perbandingan,
  operator_penjumlahan,
  operasi_penjumlahan,
  operator_pre_post,
  operasi_pre_post,
  operator_perkalian,
  operasi_perkalian,
  nilai
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
    case ParserRule::operator_logika_tidak:
      return "operator_logika_tidak";
    case ParserRule::operasi_logika_tidak:
      return "operasi_logika_tidak";
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
