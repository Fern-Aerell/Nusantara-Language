#pragma once

#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/lexer/token_type_data.h>

#include <string>
#include <vector>

class Lexer {
  public:
    Lexer(std::string source, std::string content);
    Token getNextToken();

  private:
    std::string source;
    std::string content;
    std::vector<TokenTypeData> tokenTypesBawaan = {
        {"SPASI",                   TokenType::SPASI,                   "[ ]+"                },
        {"BARIS_BARU",              TokenType::BARIS_BARU,              "[\n]+"               },
        {"TAB",                     TokenType::TAB,                     "[\t]+"               },
        {"OTHER_WHITESPACE",        TokenType::OTHER_WHITESPACE,        "[\r\f]+"             },
        {"KOMENTAR_DOKUMENTASI",    TokenType::KOMENTAR_DOKUMENTASI,    "///[^\n]*"           },
        {"KOMENTAR_SATU_BARIS",     TokenType::KOMENTAR_SATU_BARIS,     "//[^\n]*"            },
        {"KOMENTAR_BANYAK_BARIS",   TokenType::KOMENTAR_BANYAK_BARIS,
         "/\\*(.|[ \n\t\r\f])*\\*/"                                                           },
 // Nilai Tipe Data
        {"BILANGAN",                TokenType::BILANGAN,                "-?([0-9]+(,[0-9]+)?)"},
        {"BENAR",                   TokenType::BENAR,                   "benar"               },
        {"SALAH",                   TokenType::SALAH,                   "salah"               },
 // Operator Pembanding
        {"SAMA",                    TokenType::SAMA,                    "=="                  },
        {"TIDAK_SAMA",              TokenType::TIDAK_SAMA,              "!="                  },
        {"LEBIH_BESAR_SAMA_DENGAN", TokenType::LEBIH_BESAR_SAMA_DENGAN, ">="                  },
        {"LEBIH_KECIL_SAMA_DENGAN", TokenType::LEBIH_KECIL_SAMA_DENGAN, "<="                  },
        {"LEBIH_BESAR",             TokenType::LEBIH_BESAR,             ">"                   },
        {"LEBIH_KECIL",             TokenType::LEBIH_KECIL,             "<"                   },
 // Operator Penugasan
        {"SAMA_DENGAN",             TokenType::SAMA_DENGAN,             "="                   },
        {"TAMBAH_SAMA_DENGAN",      TokenType::TAMBAH_SAMA_DENGAN,      "\\+="                },
        {"KURANG_SAMA_DENGAN",      TokenType::KURANG_SAMA_DENGAN,      "-="                  },
        {"KALI_SAMA_DENGAN",        TokenType::KALI_SAMA_DENGAN,        "\\*="                },
        {"BAGI_SAMA_DENGAN",        TokenType::BAGI_SAMA_DENGAN,        "/="                  },
        {"SISA_BAGI_SAMA_DENGAN",   TokenType::SISA_BAGI_SAMA_DENGAN,   "%="                  },
 // Operator Aritmatika
        {"TAMBAH_SATU",             TokenType::TAMBAH_SATU,             "\\+\\+"              },
        {"TAMBAH",                  TokenType::TAMBAH,                  "\\+"                 },
        {"KURANG_SATU",             TokenType::KURANG_SATU,             "--"                  },
        {"KURANG",                  TokenType::KURANG,                  "-"                   },
        {"KALI",                    TokenType::KALI,                    "\\*"                 },
        {"BAGI",                    TokenType::BAGI,                    "/"                   },
        {"SISA_BAGI",               TokenType::SISA_BAGI,               "%"                   },
 // Operator Logika
        {"DAN",                     TokenType::DAN,                     "&&"                  },
        {"ATAU",                    TokenType::ATAU,                    "\\|\\|"              },
        {"TIDAK",                   TokenType::TIDAK,                   "!"                   },
 // Pemisah
        {"TITIK_KOMA",              TokenType::TITIK_KOMA,              ";"                   },
        {"KURUNG_BUKA",             TokenType::KURUNG_BUKA,             "\\("                 },
        {"KURUNG_TUTUP",            TokenType::KURUNG_TUTUP,            "\\)"                 },
        {"KURUNG_KURAWAL_BUKA",     TokenType::KURUNG_KURAWAL_BUKA,     "\\{"                 },
        {"KURUNG_KURAWAL_TUTUP",    TokenType::KURUNG_KURAWAL_TUTUP,    "\\}"                 },
 // Simbol
        {"DOLAR",                   TokenType::DOLAR,                   "\\$"                 },
        {"KUTIP_SATU",              TokenType::KUTIP_SATU,              "'"                   },
        {"KUTIP_DUA",               TokenType::KUTIP_DUA,               "\""                  },
        {"GARIS_MIRING_KEBALIK",    TokenType::GARIS_MIRING_KEBALIK,    "\\\\"                },
 // Lainnya
        {"KARAKTER",                TokenType::KARAKTER,                "[^\n\t\r\f]"         }
    };
    int line = 0;
    int realCharIndex = 0;
    int charIndex = 0;
    bool match(const std::string &pattern, std::string &match);
    Token createToken(const TokenType &type, const std::string &value);
    Token generateTokenBawaan();
    Token generateTokenTidakDiKenal();
};
