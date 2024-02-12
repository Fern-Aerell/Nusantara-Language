#pragma once

#include <string>

enum class TokenType : int {
  AKHIR_DARI_FILE = -1,
  TIDAK_DIKENALI = 0,
  WHITESPACE = 1,
  KOMENTAR_SATU_BARIS = 2,
  KOMENTAR_BANYAK_BARIS = 3,
  // Nilai Tipe Data
  DESIMAL = 4,
  BULAT = 5,
  KARAKTER = 6,
  KALIMAT = 7,
  BENAR = 8,
  SALAH = 9,
  // Operator Penugasan
  SAMA_DENGAN = 10,
  TAMBAH_SAMA_DENGAN = 11,
  KURANG_SAMA_DENGAN = 12,
  KALI_SAMA_DENGAN = 13,
  BAGI_SAMA_DENGAN = 14,
  SISA_BAGI_SAMA_DENGAN = 15,
  // Operator Aritmatika
  TAMBAH = 16,
  KURANG = 17,
  KALI = 18,
  BAGI = 19,
  SISA_BAGI = 20,
  TAMBAH_SATU = 21,
  KURANG_SATU = 22,
  // Operator Pembanding
  SAMA = 23,
  TIDAK_SAMA = 24,
  LEBIH_BESAR = 25,
  LEBIH_KECIL = 26,
  LEBIH_BESAR_SAMA_DENGAN = 27,
  LEBIH_KECIL_SAMA_DENGAN = 28,
  // Operator Logika
  DAN = 29,
  ATAU = 30,
  TIDAK = 31,
  // Pemisah
  TITIK_KOMA = 32,
  KURUNG_BUKA = 33,
  KURUNG_TUTUP = 34
};

inline std::string toString(const TokenType &type) {
  switch(type) {
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
    case TokenType::TITIK_KOMA:
      return "TITIK_KOMA";
    case TokenType::KURUNG_BUKA:
      return "KURUNG_BUKA";
    case TokenType::KURUNG_TUTUP:
      return "KURUNG_TUTUP";
  }
}
