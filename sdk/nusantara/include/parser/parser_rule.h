#pragma once

#include <string>

enum class ParserRule : int {
  nusantara,
  ekspresi,
  operasi_geser_kanan_bit_sama_dengan,
  operasi_geser_kiri_bit_sama_dengan,
  operasi_xor_bit_sama_dengan,
  operasi_or_bit_sama_dengan,
  operasi_and_bit_sama_dengan,
  operasi_kurang_sama_dengan,
  operasi_tambah_sama_dengan,
  operasi_sisa_bagi_sama_dengan,
  operasi_bagi_sama_dengan,
  operasi_kali_sama_dengan,
  operasi_sama_dengan,
  operasi_atau,
  operasi_dan,
  operasi_or_bit,
  operasi_xor_bit,
  operasi_and_bit,
  operasi_tidak_sama,
  operasi_sama,
  operasi_lebih_besar_sama_dengan,
  operasi_lebih_besar,
  operasi_lebih_kecil_sama_dengan,
  operasi_lebih_kecil,
  operasi_geser_kanan_bit,
  operasi_geser_kiri_bit,
  operasi_kurang,
  operasi_tambah,
  operasi_sisa_pembagian,
  operasi_pembagian,
  operasi_perkalian,
  operasi_tidak,
  operasi_not_bit,
  operasi_kurang_satu,
  operasi_tambah_satu,
  nilai,
  nilai_kalimat
};

inline std::string toString(const ParserRule &rule) {
  switch(rule) {
    case ParserRule::nusantara:
      return "nusantara";
    case ParserRule::ekspresi:
      return "ekspresi";
    case ParserRule::operasi_geser_kanan_bit_sama_dengan:
      return "operasi_geser_kanan_bit_sama_dengan";
    case ParserRule::operasi_geser_kiri_bit_sama_dengan:
      return "operasi_geser_kiri_bit_sama_dengan";
    case ParserRule::operasi_xor_bit_sama_dengan:
      return "operasi_xor_bit_sama_dengan";
    case ParserRule::operasi_or_bit_sama_dengan:
      return "operasi_or_bit_sama_dengan";
    case ParserRule::operasi_and_bit_sama_dengan:
      return "operasi_and_bit_sama_dengan";
    case ParserRule::operasi_kurang_sama_dengan:
      return "operasi_kurang_sama_dengan";
    case ParserRule::operasi_tambah_sama_dengan:
      return "operasi_tambah_sama_dengan";
    case ParserRule::operasi_sisa_bagi_sama_dengan:
      return "operasi_sisa_bagi_sama_dengan";
    case ParserRule::operasi_bagi_sama_dengan:
      return "operasi_bagi_sama_dengan";
    case ParserRule::operasi_kali_sama_dengan:
      return "operasi_kali_sama_dengan";
    case ParserRule::operasi_sama_dengan:
      return "operasi_sama_dengan";
    case ParserRule::operasi_atau:
      return "operasi_atau";
    case ParserRule::operasi_dan:
      return "operasi_dan";
    case ParserRule::operasi_or_bit:
      return "operasi_or_bit";
    case ParserRule::operasi_xor_bit:
      return "operasi_xor_bit";
    case ParserRule::operasi_and_bit:
      return "operasi_and_bit";
    case ParserRule::operasi_tidak_sama:
      return "operasi_tidak_sama";
    case ParserRule::operasi_sama:
      return "operasi_sama";
    case ParserRule::operasi_lebih_besar_sama_dengan:
      return "operasi_lebih_besar_sama_dengan";
    case ParserRule::operasi_lebih_besar:
      return "operasi_lebih_besar";
    case ParserRule::operasi_lebih_kecil_sama_dengan:
      return "operasi_lebih_kecil_sama_dengan";
    case ParserRule::operasi_lebih_kecil:
      return "operasi_lebih_kecil";
    case ParserRule::operasi_geser_kanan_bit:
      return "operasi_geser_kanan_bit";
    case ParserRule::operasi_geser_kiri_bit:
      return "operasi_geser_kiri_bit";
    case ParserRule::operasi_kurang:
      return "operasi_kurang";
    case ParserRule::operasi_tambah:
      return "operasi_tambah";
    case ParserRule::operasi_sisa_pembagian:
      return "operasi_sisa_pembagian";
    case ParserRule::operasi_pembagian:
      return "operasi_pembagian";
    case ParserRule::operasi_perkalian:
      return "operasi_perkalian";
    case ParserRule::operasi_tidak:
      return "operasi_tidak";
    case ParserRule::operasi_not_bit:
      return "operasi_not_bit";
    case ParserRule::operasi_kurang_satu:
      return "operasi_kurang_satu";
    case ParserRule::operasi_tambah_satu:
      return "operasi_tambah_satu";
    case ParserRule::nilai:
      return "nilai";
    case ParserRule::nilai_kalimat:
      return "nilai_kalimat";
  }
};
