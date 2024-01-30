#pragma once

#include "token_type.h"
#include <string>
#include <token.h>
#include <token_type_data.h>
#include <vector>

class Lexer
{
public:
  explicit Lexer(std::string content);

private:
  std::vector<TokenTypeData> tokenTypes = {
    TokenTypeData("AKHIR_DARI_FILE", TokenType::AKHIR_DARI_FILE, ""),
    TokenTypeData("WHITESPACE", TokenType::WHITESPACE, "[ \n\t\r\f]+"),
    TokenTypeData("KOMENTAR_SATU_BARIS", TokenType::KOMENTAR_SATU_BARIS,
                  "//[^\n]*"),
    TokenTypeData("KOMENTAR_BANYAK_BARIS", TokenType::KOMENTAR_BANYAK_BARIS,
                  "/\\*(.|[ \n\t\r\f])*\\*/"),
    // Nilai Tipe Data
    TokenTypeData("DESIMAL", TokenType::DESIMAL, "-?[0-9]+,[0-9]+"),
    TokenTypeData("BULAT", TokenType::BULAT, "-?[0-9]+"),
    TokenTypeData("KARAKTER", TokenType::KARAKTER, "(\"[^\n]\"|'[^\n]')"),
    TokenTypeData("KALIMAT", TokenType::KALIMAT, "(\"[^\n]*\"|'[^\n]*')"),
    TokenTypeData("BENAR", TokenType::BENAR, "benar"),
    TokenTypeData("SALAH", TokenType::SALAH, "salah"),
    // Operator Penugasan
    TokenTypeData("SAMA_DENGAN", TokenType::SAMA_DENGAN, "="),
    TokenTypeData("TAMBAH_SAMA_DENGAN", TokenType::TAMBAH_SAMA_DENGAN, "\\+="),
    TokenTypeData("KURANG_SAMA_DENGAN", TokenType::KURANG_SAMA_DENGAN, "-="),
    TokenTypeData("KALI_SAMA_DENGAN", TokenType::KALI_SAMA_DENGAN, "\\*="),
    TokenTypeData("BAGI_SAMA_DENGAN", TokenType::BAGI_SAMA_DENGAN, "/="),
    TokenTypeData("SISA_BAGI_SAMA_DENGAN", TokenType::SISA_BAGI_SAMA_DENGAN,
                  "%="),
    // Operator Aritmatika
    TokenTypeData("TAMBAH_SATU", TokenType::TAMBAH_SATU, "\\+\\+"),
    TokenTypeData("TAMBAH", TokenType::TAMBAH, "\\+"),
    TokenTypeData("KURANG_SATU", TokenType::KURANG_SATU, "--"),
    TokenTypeData("KURANG", TokenType::KURANG, "-"),
    TokenTypeData("KALI", TokenType::KALI, "\\*"),
    TokenTypeData("BAGI", TokenType::BAGI, "/"),
    TokenTypeData("SISA_BAGI", TokenType::SISA_BAGI, "%"),
    // Operator Pembanding
    TokenTypeData("SAMA", TokenType::SAMA, "=="),
    TokenTypeData("TIDAK_SAMA", TokenType::TIDAK_SAMA, "!="),
    TokenTypeData("LEBIH_BESAR", TokenType::LEBIH_BESAR, ">"),
    TokenTypeData("LEBIH_KECIL", TokenType::LEBIH_KECIL, "<"),
    TokenTypeData("LEBIH_BESAR_SAMA_DENGAN",
                  TokenType::LEBIH_BESAR_SAMA_DENGAN, ">="),
    TokenTypeData("LEBIH_KECIL_SAMA_DENGAN",
                  TokenType::LEBIH_KECIL_SAMA_DENGAN, "<="),
    // Operator Logika
    TokenTypeData("DAN", TokenType::DAN, "&&"),
    TokenTypeData("ATAU", TokenType::ATAU, "||"),
    TokenTypeData("TIDAK", TokenType::TIDAK, "!")};
  std::string content;
  std::vector<Token> tokens;
  void tokenizer();
};
