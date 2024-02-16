#pragma once

#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/lexer/token_type_data.h>

#include <string>
#include <vector>

enum class LexerMode { BAWAAN, KALIMAT };

enum class LexerModeState {
  BAWAAN,
  KALIMAT,
  KALIMAT_PEMBUKA,
  KALIMAT_DOLAR,
  KALIMAT_KURAWAL_BUKA,
  KALIMAT_KURAWAL_TUTUP,
  KALIMAT_PENUTUP
};

class Lexer {
  public:
    Lexer(std::string source, std::string content);
    Token getNextToken();

  private:
    std::string source;
    std::string content;
    LexerMode mode = LexerMode::BAWAAN;
    LexerModeState modeState = LexerModeState::BAWAAN;
    std::vector<TokenTypeData> tokenTypesBawaan = {
        {"WHITESPACE",              TokenType::WHITESPACE,              "[ \n\t\r\f]+"           },
        {"KOMENTAR_DOKUMENTASI",    TokenType::KOMENTAR_DOKUMENTASI,    "///[^\n]*"              },
        {"KOMENTAR_SATU_BARIS",     TokenType::KOMENTAR_SATU_BARIS,     "//[^\n]*"               },
        {"KOMENTAR_BANYAK_BARIS",   TokenType::KOMENTAR_BANYAK_BARIS,
         "/\\*(.|[ \n\t\r\f])*\\*/"                                                              },
 // Nilai Tipe Data
        {"BILANGAN",                TokenType::BILANGAN,                "-?([0-9]+(,[0-9]+)?)"   },
        {"KUTIP_SATU",              TokenType::KUTIP_SATU,              "'"                      },
        {"KUTIP_DUA",               TokenType::KUTIP_DUA,               "\""                     },
        {"BENAR",                   TokenType::BENAR,                   "benar"                  },
        {"SALAH",                   TokenType::SALAH,                   "salah"                  },
 // Operator Pembanding
        {"SAMA",                    TokenType::SAMA,                    "=="                     },
        {"TIDAK_SAMA",              TokenType::TIDAK_SAMA,              "!="                     },
        {"LEBIH_BESAR_SAMA_DENGAN", TokenType::LEBIH_BESAR_SAMA_DENGAN, ">="                     },
        {"LEBIH_KECIL_SAMA_DENGAN", TokenType::LEBIH_KECIL_SAMA_DENGAN, "<="                     },
        {"LEBIH_BESAR",             TokenType::LEBIH_BESAR,             ">"                      },
        {"LEBIH_KECIL",             TokenType::LEBIH_KECIL,             "<"                      },
 // Operator Penugasan
        {"SAMA_DENGAN",             TokenType::SAMA_DENGAN,             "="                      },
        {"TAMBAH_SAMA_DENGAN",      TokenType::TAMBAH_SAMA_DENGAN,      "\\+="                   },
        {"KURANG_SAMA_DENGAN",      TokenType::KURANG_SAMA_DENGAN,      "-="                     },
        {"KALI_SAMA_DENGAN",        TokenType::KALI_SAMA_DENGAN,        "\\*="                   },
        {"BAGI_SAMA_DENGAN",        TokenType::BAGI_SAMA_DENGAN,        "/="                     },
        {"SISA_BAGI_SAMA_DENGAN",   TokenType::SISA_BAGI_SAMA_DENGAN,   "%="                     },
 // Operator Aritmatika
        {"TAMBAH_SATU",             TokenType::TAMBAH_SATU,             "\\+\\+"                 },
        {"TAMBAH",                  TokenType::TAMBAH,                  "\\+"                    },
        {"KURANG_SATU",             TokenType::KURANG_SATU,             "--"                     },
        {"KURANG",                  TokenType::KURANG,                  "-"                      },
        {"KALI",                    TokenType::KALI,                    "\\*"                    },
        {"BAGI",                    TokenType::BAGI,                    "/"                      },
        {"SISA_BAGI",               TokenType::SISA_BAGI,               "%"                      },
 // Operator Logika
        {"DAN",                     TokenType::DAN,                     "&&"                     },
        {"ATAU",                    TokenType::ATAU,                    "\\|\\|"                 },
        {"TIDAK",                   TokenType::TIDAK,                   "!"                      },
 // Pemisah
        {"TITIK_KOMA",              TokenType::TITIK_KOMA,              ";"                      },
        {"KURUNG_BUKA",             TokenType::KURUNG_BUKA,             "\\("                    },
        {"KURUNG_TUTUP",            TokenType::KURUNG_TUTUP,            "\\)"                    },
        {"KURUNG_KURAWAL_BUKA",     TokenType::KURUNG_KURAWAL_BUKA,     "\\{"                    },
        {"KURUNG_KURAWAL_TUTUP",    TokenType::KURUNG_KURAWAL_TUTUP,    "\\}"                    },
 // Lainnya
        {"IDENTIFIKASI",            TokenType::IDENTIFIKASI,            "[a-zA-Z_]+[a-zA-Z0-9_]*"}
    };
    std::vector<TokenTypeData> tokenTypesKalimat = {
        {"DOLAR",               TokenType::DOLAR,               "\\$"  },
        {"KURUNG_KURAWAL_BUKA", TokenType::KURUNG_KURAWAL_BUKA, "\\{"  },
        {"KUTIP_SATU",          TokenType::KUTIP_SATU,          "'"    },
        {"KUTIP_DUA",           TokenType::KUTIP_DUA,           "\""   },
        {"KARAKTER",            TokenType::KARAKTER,            "[^\n]"}
    };
    int line = 0;
    int realCharIndex = 0;
    int charIndex = 0;
    bool match(const std::string &pattern, std::string &match);
    Token createToken(const TokenType &type, const std::string &value);
    Token generateTokenBawaan();
    Token generateTokenKalimat();
    Token generateTokenTidakDiKenal();
    bool existForward(const std::string);
};
