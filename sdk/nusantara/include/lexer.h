#pragma once

#include <token.h>
#include "token_type.h"
#include <token_type_data.h>
#include <vector>

class Lexer {
  public:
    std::string toString(const TokenType& type);
    std::string toString(const Token& token);
    std::string toString(const std::vector<Token>& tokens);
    std::vector<Token> inputFromFile(const std::string& filepath);
    std::vector<Token> inputFromString(const std::string& source, std::string& content);
  private:
    std::vector<TokenTypeData> tokenTypes = {
      {"AKHIR_DARI_FILE", TokenType::AKHIR_DARI_FILE, "\\0"},
      {"WHITESPACE", TokenType::WHITESPACE, "[ \n\t\r\f]+"},
      {"KOMENTAR_SATU_BARIS", TokenType::KOMENTAR_SATU_BARIS,
                    "//[^\n]*"},
      {"KOMENTAR_BANYAK_BARIS", TokenType::KOMENTAR_BANYAK_BARIS,
                    "/\\*(.|[ \n\t\r\f])*\\*/"},
      // Nilai Tipe Data
      {"DESIMAL", TokenType::DESIMAL, "-?[0-9]+,[0-9]+"},
      {"BULAT", TokenType::BULAT, "-?[0-9]+"},
      {"KARAKTER", TokenType::KARAKTER, "(\"[^\n]\"|'[^\n]')"},
      {"KALIMAT", TokenType::KALIMAT, "(\"[^\n]*\"|'[^\n]*')"},
      {"BENAR", TokenType::BENAR, "benar"},
      {"SALAH", TokenType::SALAH, "salah"},
      // Operator Penugasan
      {"SAMA_DENGAN", TokenType::SAMA_DENGAN, "="},
      {"TAMBAH_SAMA_DENGAN", TokenType::TAMBAH_SAMA_DENGAN, "\\+="},
      {"KURANG_SAMA_DENGAN", TokenType::KURANG_SAMA_DENGAN, "-="},
      {"KALI_SAMA_DENGAN", TokenType::KALI_SAMA_DENGAN, "\\*="},
      {"BAGI_SAMA_DENGAN", TokenType::BAGI_SAMA_DENGAN, "/="},
      {"SISA_BAGI_SAMA_DENGAN", TokenType::SISA_BAGI_SAMA_DENGAN,
                    "%="},
      // Operator Aritmatika
      {"TAMBAH_SATU", TokenType::TAMBAH_SATU, "\\+\\+"},
      {"TAMBAH", TokenType::TAMBAH, "\\+"},
      {"KURANG_SATU", TokenType::KURANG_SATU, "--"},
      {"KURANG", TokenType::KURANG, "-"},
      {"KALI", TokenType::KALI, "\\*"},
      {"BAGI", TokenType::BAGI, "/"},
      {"SISA_BAGI", TokenType::SISA_BAGI, "%"},
      // Operator Pembanding
      {"SAMA", TokenType::SAMA, "=="},
      {"TIDAK_SAMA", TokenType::TIDAK_SAMA, "!="},
      {"LEBIH_BESAR", TokenType::LEBIH_BESAR, ">"},
      {"LEBIH_KECIL", TokenType::LEBIH_KECIL, "<"},
      {"LEBIH_BESAR_SAMA_DENGAN",
                    TokenType::LEBIH_BESAR_SAMA_DENGAN, ">="},
      {"LEBIH_KECIL_SAMA_DENGAN",
                    TokenType::LEBIH_KECIL_SAMA_DENGAN, "<="},
      // Operator Logika
      {"DAN", TokenType::DAN, "&&"},
      {"ATAU", TokenType::ATAU, "||"},
      {"TIDAK", TokenType::TIDAK, "!"}
    };
    static bool match(std::string& content, const std::string& pattern, std::string& match, int& line, int& realCharIndex, int& charIndex);
    static void createToken(std::vector<Token>& tokens, const std::string& source, const TokenType& type, std::string& match, int& line, int& charIndex);
};
