#pragma once

#include <stdexcept>
#include <string>
enum class TokenType : int
{
  TIDAK_DIKENALI = -2,
  AKHIR_DARI_FILE = -1,
  WHITESPACE = 0,
  KOMENTAR_SATU_BARIS = 1,
  KOMENTAR_BANYAK_BARIS = 2,
  // Nilai Tipe Data
  DESIMAL = 3,
  BULAT = 4,
  KARAKTER = 5,
  KALIMAT = 6,
  BENAR = 7,
  SALAH = 8,
  // Operator Penugasan
  SAMA_DENGAN = 9,
  TAMBAH_SAMA_DENGAN = 10,
  KURANG_SAMA_DENGAN = 11,
  KALI_SAMA_DENGAN = 12,
  BAGI_SAMA_DENGAN = 13,
  SISA_BAGI_SAMA_DENGAN = 14,
  // Operator Aritmatika
  TAMBAH = 15,
  KURANG = 16,
  KALI = 17,
  BAGI = 18,
  SISA_BAGI = 19,
  TAMBAH_SATU = 20,
  KURANG_SATU = 21,
  // Operator Pembanding
  SAMA = 22,
  TIDAK_SAMA = 23,
  LEBIH_BESAR = 24,
  LEBIH_KECIL = 25,
  LEBIH_BESAR_SAMA_DENGAN = 26,
  LEBIH_KECIL_SAMA_DENGAN = 27,
  // Operator Logika
  DAN = 28,
  ATAU = 29,
  TIDAK = 30
};

inline std::string toString(const TokenType& type) {
  switch (type) {
    case TokenType::TIDAK_DIKENALI:
      return "TIDAK_DIKENALI";
    case TokenType::AKHIR_DARI_FILE:
      return "AKHIR_DARI_FILE";
    case TokenType::WHITESPACE:
      return "WHITESPACE";
    case TokenType::KOMENTAR_SATU_BARIS:
      return "KOMENTAR_SATU_BARIS";
    case TokenType::KOMENTAR_BANYAK_BARIS:
      return "KOMENTAR_BANYAK_BARIS";
    case TokenType::DESIMAL:
      return "DESIMAL";
    case TokenType::BULAT:
      return "BULAT";
    case TokenType::KARAKTER:
      return "KARAKTER";
    case TokenType::KALIMAT:
      return "KALIMAT";
    case TokenType::BENAR:
      return "BENAR";
    case TokenType::SALAH:
      return "SALAH";
    case TokenType::SAMA_DENGAN:
      return "SAMA_DENGAN";
    case TokenType::TAMBAH_SAMA_DENGAN:
      return "TAMBAH_SAMA_DENGAN";
    case TokenType::KURANG_SAMA_DENGAN:
      return "KURANG_SAMA_DENGAN";
    case TokenType::KALI_SAMA_DENGAN:
      return "KALI_SAMA_DENGAN";
    case TokenType::BAGI_SAMA_DENGAN:
      return "BAGI_SAMA_DENGAN";
    case TokenType::SISA_BAGI_SAMA_DENGAN:
      return "SISA_BAGI_SAMA_DENGAN";
    case TokenType::TAMBAH:
      return "TAMBAH";
    case TokenType::KURANG:
      return "KURANG";
    case TokenType::KALI:
      return "KALI";
    case TokenType::BAGI:
      return "BAGI";
    case TokenType::SISA_BAGI:
      return "SISA_BAGI";
    case TokenType::TAMBAH_SATU:
      return "TAMBAH_SATU";
    case TokenType::KURANG_SATU:
      return "KURANG_SATU";
    case TokenType::SAMA:
      return "SAMA";
    case TokenType::TIDAK_SAMA:
      return "TIDAK_SAMA";
    case TokenType::LEBIH_BESAR:
      return "LEBIH_BESAR";
    case TokenType::LEBIH_KECIL:
      return "LEBIH_KECIL";
    case TokenType::LEBIH_BESAR_SAMA_DENGAN:
      return "LEBIH_BESAR_SAMA_DENGAN";
    case TokenType::LEBIH_KECIL_SAMA_DENGAN:
      return "LEBIH_KECIL_SAMA_DENGAN";
    case TokenType::DAN:
      return "DAN";
    case TokenType::ATAU:
      return "ATAU";
    case TokenType::TIDAK: 
      return "TIDAK";
  }
}