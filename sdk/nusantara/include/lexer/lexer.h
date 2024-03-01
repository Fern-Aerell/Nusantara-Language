#pragma once

#include <string>
#include <vector>

#include "lexer/token.h"
#include "lexer/token_type.h"
#include "lexer/token_type_data.h"

class Lexer {
  public:
    Lexer(std::string source, std::string content);
    Token getNextToken();

  private:
    std::string source;
    std::string content;
    std::vector<TokenTypeData> tokenTypesBawaan = {
        {"SPASI",                       TokenType::SPASI,                       "[ ]+"                   },
        {"BARIS_BARU",                  TokenType::BARIS_BARU,                  "[\n]+"                  },
        {"TAB",                         TokenType::TAB,                         "[\t]+"                  },
        {"OTHER_WHITESPACE",            TokenType::OTHER_WHITESPACE,            "[\r\f]+"                },
        {"KOMENTAR_DOKUMENTASI",        TokenType::KOMENTAR_DOKUMENTASI,        "///[^\n]*"              },
        {"KOMENTAR_SATU_BARIS",         TokenType::KOMENTAR_SATU_BARIS,         "//[^\n]*"               },
        {"KOMENTAR_BANYAK_BARIS",       TokenType::KOMENTAR_BANYAK_BARIS,
         "/\\*(.|[ \n\t\r\f])*\\*/"                                                                      },
        {"TIPE_DATA_BILANGAN",          TokenType::TIPE_DATA_BILANGAN,          "bilangan"               },
        {"TIPE_DATA_KALIMAT",           TokenType::TIPE_DATA_KALIMAT,           "kalimat"                },
        {"TIPE_DATA_BENARSALAH",        TokenType::TIPE_DATA_BENARSALAH,        "benarsalah"             },
        {"BILANGAN",                    TokenType::BILANGAN,                    "-?([0-9]+(,[0-9]+)?)"   },
        {"BENAR",                       TokenType::NILAI_BENAR,                 "benar"                  },
        {"SALAH",                       TokenType::NILAI_SALAH,                 "salah"                  },
        {"DAN",                         TokenType::DAN,                         "&&"                     },
        {"ATAU",                        TokenType::ATAU,                        "\\|\\|"                 },
        {"TIDAK_SAMA",                  TokenType::TIDAK_SAMA,                  "!="                     },
        {"TIDAK",                       TokenType::TIDAK,                       "!"                      },
        {"AND_BIT_SAMA_DENGAN",         TokenType::AND_BIT_SAMA_DENGAN,         "&="                     },
        {"OR_BIT_SAMA_DENGAN",          TokenType::OR_BIT_SAMA_DENGAN,          "\\|="                   },
        {"XOR_BIT_SAMA_DENGAN",         TokenType::XOR_BIT_SAMA_DENGAN,         "\\^="                   },
        {"GESER_KIRI_BIT_SAMA_DENGAN",  TokenType::GESER_KIRI_BIT_SAMA_DENGAN,
         "<<="                                                                                           },
        {"GESER_KANAN_BIT_SAMA_DENGAN", TokenType::GESER_KANAN_BIT_SAMA_DENGAN,
         ">>="                                                                                           },
        {"AND_BIT",                     TokenType::AND_BIT,                     "&"                      },
        {"OR_BIT",                      TokenType::OR_BIT,                      "\\|"                    },
        {"XOR_BIT",                     TokenType::XOR_BIT,                     "\\^"                    },
        {"NOT_BIT",                     TokenType::NOT_BIT,                     "\\~"                    },
        {"GESER_KIRI_BIT",              TokenType::GESER_KIRI_BIT,              "<<"                     },
        {"GESER_KANAN_BIT",             TokenType::GESER_KANAN_BIT,             ">>"                     },
        {"SAMA",                        TokenType::SAMA,                        "=="                     },
        {"LEBIH_BESAR_SAMA_DENGAN",     TokenType::LEBIH_BESAR_SAMA_DENGAN,     ">="                     },
        {"LEBIH_KECIL_SAMA_DENGAN",     TokenType::LEBIH_KECIL_SAMA_DENGAN,     "<="                     },
        {"LEBIH_BESAR",                 TokenType::LEBIH_BESAR,                 ">"                      },
        {"LEBIH_KECIL",                 TokenType::LEBIH_KECIL,                 "<"                      },
        {"SAMA_DENGAN",                 TokenType::SAMA_DENGAN,                 "="                      },
        {"TAMBAH_SAMA_DENGAN",          TokenType::TAMBAH_SAMA_DENGAN,          "\\+="                   },
        {"KURANG_SAMA_DENGAN",          TokenType::KURANG_SAMA_DENGAN,          "-="                     },
        {"KALI_SAMA_DENGAN",            TokenType::KALI_SAMA_DENGAN,            "\\*="                   },
        {"BAGI_SAMA_DENGAN",            TokenType::BAGI_SAMA_DENGAN,            "/="                     },
        {"SISA_BAGI_SAMA_DENGAN",       TokenType::SISA_BAGI_SAMA_DENGAN,       "%="                     },
        {"TAMBAH_SATU",                 TokenType::TAMBAH_SATU,                 "\\+\\+"                 },
        {"TAMBAH",                      TokenType::TAMBAH,                      "\\+"                    },
        {"KURANG_SATU",                 TokenType::KURANG_SATU,                 "--"                     },
        {"KURANG",                      TokenType::KURANG,                      "-"                      },
        {"KALI",                        TokenType::KALI,                        "\\*"                    },
        {"BAGI",                        TokenType::BAGI,                        "/"                      },
        {"SISA_BAGI",                   TokenType::SISA_BAGI,                   "%"                      },
        {"TANDA_TANYA",                 TokenType::TANDA_TANYA,                 "\\?"                    },
        {"TITIK_DUA",                   TokenType::TITIK_DUA,                   ":"                      },
        {"TITIK_KOMA",                  TokenType::TITIK_KOMA,                  ";"                      },
        {"KURUNG_BUKA",                 TokenType::KURUNG_BUKA,                 "\\("                    },
        {"KURUNG_TUTUP",                TokenType::KURUNG_TUTUP,                "\\)"                    },
        {"KURUNG_KURAWAL_BUKA",         TokenType::KURUNG_KURAWAL_BUKA,         "\\{"                    },
        {"KURUNG_KURAWAL_TUTUP",        TokenType::KURUNG_KURAWAL_TUTUP,        "\\}"                    },
        {"DOLAR",                       TokenType::DOLAR,                       "\\$"                    },
        {"KUTIP_SATU",                  TokenType::KUTIP_SATU,                  "'"                      },
        {"KUTIP_DUA",                   TokenType::KUTIP_DUA,                   "\""                     },
        {"GARIS_MIRING_KEBALIK",        TokenType::GARIS_MIRING_KEBALIK,        "\\\\"                   },
        {"IDENTIFIKASI",                TokenType::IDENTIFIKASI,                "[a-zA-Z_]+[a-zA-Z0-9_]*"},
        {"KARAKTER",                    TokenType::KARAKTER,                    "[^\n\t\r\f]"            }
    };
    int line = 0;
    int realCharIndex = 0;
    int charIndex = 0;
    bool match(const std::string &pattern, std::string &match);
    Token createToken(const TokenType &type, const std::string &value);
};
