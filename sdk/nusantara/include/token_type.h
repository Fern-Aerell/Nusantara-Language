#pragma once

enum class TokenType : int
{
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
