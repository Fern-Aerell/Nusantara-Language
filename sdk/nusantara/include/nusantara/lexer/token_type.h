#pragma once

#include <string>

enum class TokenType : int {
  AKHIR_DARI_FILE,
  TIDAK_DIKENALI,
  WHITESPACE,
  KOMENTAR_SATU_BARIS,
  KOMENTAR_BANYAK_BARIS,
  KOMENTAR_DOKUMENTASI,
  // Nilai Tipe Data
  BILANGAN,
  KALIMAT,
  BENAR,
  SALAH,
  // Operator Penugasan
  SAMA_DENGAN,
  TAMBAH_SAMA_DENGAN,
  KURANG_SAMA_DENGAN,
  KALI_SAMA_DENGAN,
  BAGI_SAMA_DENGAN,
  SISA_BAGI_SAMA_DENGAN,
  // Operator Aritmatika
  TAMBAH,
  KURANG,
  KALI,
  BAGI,
  SISA_BAGI,
  TAMBAH_SATU,
  KURANG_SATU,
  // Operator Pembanding
  SAMA,
  TIDAK_SAMA,
  LEBIH_BESAR,
  LEBIH_KECIL,
  LEBIH_BESAR_SAMA_DENGAN,
  LEBIH_KECIL_SAMA_DENGAN,
  // Operator Logika
  DAN,
  ATAU,
  TIDAK,
  // Pemisah
  TITIK_KOMA,
  KURUNG_BUKA,
  KURUNG_TUTUP
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
    case TokenType::KOMENTAR_DOKUMENTASI:
      return "KOMENTAR_DOKUMENTASI";
    case TokenType::BILANGAN:
      return "BILANGAN";
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
