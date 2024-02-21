#pragma once

#include <string>

enum class TokenType : int {
  TIDAK_DIKENALI,
  AKHIR_DARI_FILE,
  // Skip token
  SPASI,
  BARIS_BARU,
  TAB,
  OTHER_WHITESPACE,
  KOMENTAR_DOKUMENTASI,
  KOMENTAR_SATU_BARIS,
  KOMENTAR_BANYAK_BARIS,
  // Nilai Tipe Data
  BILANGAN,
  KARAKTER,
  BENAR,
  SALAH,
  // Operator Penugasan
  SAMA_DENGAN,
  TAMBAH_SAMA_DENGAN,
  KURANG_SAMA_DENGAN,
  KALI_SAMA_DENGAN,
  BAGI_SAMA_DENGAN,
  SISA_BAGI_SAMA_DENGAN,
  AND_BIT_SAMA_DENGAN,
  OR_BIT_SAMA_DENGAN,
  XOR_BIT_SAMA_DENGAN,
  GESER_KIRI_BIT_SAMA_DENGAN,
  GESER_KANAN_BIT_SAMA_DENGAN,
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
  // Operator Bitwise
  AND_BIT,
  OR_BIT,
  XOR_BIT,
  NOT_BIT,
  GESER_KIRI_BIT,
  GESER_KANAN_BIT,
  // Pemisah
  TITIK_KOMA,
  KURUNG_BUKA,
  KURUNG_TUTUP,
  KURUNG_KURAWAL_BUKA,
  KURUNG_KURAWAL_TUTUP,
  // Simbol
  DOLAR,
  KUTIP_SATU,
  KUTIP_DUA,
  GARIS_MIRING_KEBALIK
};

inline std::string toString(const TokenType &type) {
  switch(type) {
    case TokenType::TIDAK_DIKENALI:
      return "TIDAK_DIKENALI";
    case TokenType::AKHIR_DARI_FILE:
      return "AKHIR_DARI_FILE";
    case TokenType::SPASI:
      return "SPASI";
    case TokenType::BARIS_BARU:
      return "BARIS_BARU";
    case TokenType::TAB:
      return "TAB";
    case TokenType::OTHER_WHITESPACE:
      return "OTHER_WHITESPACE";
    case TokenType::KOMENTAR_DOKUMENTASI:
      return "KOMENTAR_DOKUMENTASI";
    case TokenType::KOMENTAR_SATU_BARIS:
      return "KOMENTAR_SATU_BARIS";
    case TokenType::KOMENTAR_BANYAK_BARIS:
      return "KOMENTAR_BANYAK_BARIS";
    case TokenType::BILANGAN:
      return "BILANGAN";
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
    case TokenType::KURUNG_KURAWAL_BUKA:
      return "KURUNG_KURAWAL_BUKA";
    case TokenType::KURUNG_KURAWAL_TUTUP:
      return "KURUNG_KURAWAL_TUTUP";
    case TokenType::DOLAR:
      return "DOLAR";
    case TokenType::KUTIP_SATU:
      return "KUTIP_SATU";
    case TokenType::KUTIP_DUA:
      return "KUTIP_DUA";
    case TokenType::KARAKTER:
      return "KARAKTER";
    case TokenType::GARIS_MIRING_KEBALIK:
      return "GARIS_MIRING_KEBALIK";
    case TokenType::AND_BIT:
      return "AND_BIT";
    case TokenType::OR_BIT:
      return "OR_BIT";
    case TokenType::XOR_BIT:
      return "XOR_BIT";
    case TokenType::NOT_BIT:
      return "NOT_BIT";
    case TokenType::GESER_KIRI_BIT:
      return "GESER_KIRI_BIT";
    case TokenType::GESER_KANAN_BIT:
      return "GESER_KANAN_BIT";
    case TokenType::AND_BIT_SAMA_DENGAN:
      return "AND_BIT_SAMA_DENGAN";
    case TokenType::OR_BIT_SAMA_DENGAN:
      return "OR_BIT_SAMA_DENGAN";
    case TokenType::XOR_BIT_SAMA_DENGAN:
      return "XOR_BIT_SAMA_DENGAN";
    case TokenType::GESER_KIRI_BIT_SAMA_DENGAN:
      return "GESER_KIRI_BIT_SAMA_DENGAN";
    case TokenType::GESER_KANAN_BIT_SAMA_DENGAN:
      return "GESER_KANAN_BIT_SAMA_DENGAN";
  }
};
