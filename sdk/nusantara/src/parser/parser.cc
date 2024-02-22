#include "parser/parser.h"

#include <algorithm>
#include <format>
#include <memory>
#include <stdexcept>
#include <vector>

#include "error/error_info.h"
#include "lexer/lexer.h"
#include "lexer/token_type.h"
#include "parser/parser_rule.h"
#include "parser/parser_tree.h"

Parser::Parser(ErrorInfo errorInfo, Lexer lexer):
    errorInfo(std::move(errorInfo)),
    lexer(std::move(lexer)),
    currentToken(this->lexer.getNextToken()) {}

void Parser::skipWs() {
  while(matchOr(
      {TokenType::SPASI, TokenType::TAB, TokenType::BARIS_BARU,
       TokenType::OTHER_WHITESPACE, TokenType::KOMENTAR_BANYAK_BARIS,
       TokenType::KOMENTAR_SATU_BARIS, TokenType::KOMENTAR_DOKUMENTASI}
  )) {
    this->currentToken = this->lexer.getNextToken();
  }
}

std::unique_ptr<ParserTree> Parser::eat(
    const TokenType& type, const bool& skipWs
) {
  if(this->currentToken.getType() == type) {
    const Token beforeToken = this->currentToken;
    this->currentToken = this->lexer.getNextToken();
    if(skipWs) { this->skipWs(); }
    if(match(TokenType::TIDAK_DIKENALI)) {
      throw std::runtime_error(this->errorInfo.inLine(
          this->currentToken, "Karakter tidak di kenali."
      ));
    }
    return std::make_unique<ParserTokenTree>(beforeToken);
  } else {
    if(type == TokenType::TITIK_KOMA) {
      throw std::runtime_error(this->errorInfo.inLine(
          this->currentToken, "Sandhika Galih : Jangan lupa titik koma ';'."
      ));
    }
    throw std::runtime_error(this->errorInfo.inLine(
        this->currentToken,
        std::format(
            "Harusnya '{}' tapi malah '{}'.", toString(type),
            (this->currentToken.getValue().empty())
                ? toString(this->currentToken.getType())
                : this->currentToken.getValue()
        )
    ));
  }
}

bool Parser::match(const TokenType& type) {
  return this->currentToken.getType() == type;
}

bool Parser::matchOr(const std::vector<TokenType>& types) {
  return std::ranges::any_of(types, [this](const TokenType& type) {
    return this->match(type);
  });
}

// Fragment
std::unique_ptr<ParserTree> Parser::fragmentMultiOperasiLeftRight(
    const ParserRule& rule,
    const std::function<std::unique_ptr<ParserTree>()>& leftRightFunction,
    const TokenType& opSymbol
) {
  std::unique_ptr<ParserTree> pRuleTree =
      std::make_unique<ParserRuleTree>(rule);
  pRuleTree->addChild(leftRightFunction());
  while(this->match(opSymbol)) {
    pRuleTree->addChild(eat(opSymbol));
    pRuleTree->addChild(leftRightFunction());
  }
  return pRuleTree;
}

std::unique_ptr<ParserTree> Parser::fragmentOperasiPrePost(
    const ParserRule& rule,
    const std::function<std::unique_ptr<ParserTree>()>& leftFunction,
    const TokenType& opSymbol, const bool& pre, const bool& post
) {
  std::unique_ptr<ParserTree> pRuleTree =
      std::make_unique<ParserRuleTree>(rule);
  if(pre && this->match(opSymbol)) {
    pRuleTree->addChild(this->eat(opSymbol));
    pRuleTree->addChild(leftFunction());
  } else {
    pRuleTree->addChild(leftFunction());
    if(post && this->match(opSymbol)) {
      pRuleTree->addChild(this->eat(opSymbol));
    }
  }
  return pRuleTree;
}

// Parse
std::unique_ptr<ParserTree> Parser::parse() { return this->parseNusantara(); }

std::unique_ptr<ParserTree> Parser::parseNusantara() {
  std::unique_ptr<ParserTree> nusantara =
      std::make_unique<ParserRuleTree>(ParserRule::nusantara);
  while(!match(TokenType::AKHIR_DARI_FILE)) {
    nusantara->addChild(this->parseEkspresi());
    nusantara->addChild(eat(TokenType::TITIK_KOMA));
  }
  nusantara->addChild(eat(TokenType::AKHIR_DARI_FILE));
  return nusantara;
}

std::unique_ptr<ParserTree> Parser::parseEkspresi() {
  std::unique_ptr<ParserTree> ekspresi =
      std::make_unique<ParserRuleTree>(ParserRule::ekspresi);
  ekspresi->addChild(this->parseOperasiGeserKananBitSamaDengan());
  return ekspresi;
}

std::unique_ptr<ParserTree> Parser::parseOperasiGeserKananBitSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_geser_kanan_bit_sama_dengan,
      [this]() { return this->parseOperasiGeserKiriBitSamaDengan(); },
      TokenType::GESER_KANAN_BIT_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiGeserKiriBitSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_geser_kiri_bit_sama_dengan,
      [this]() { return this->parseOperasiXorBitSamaDengan(); },
      TokenType::GESER_KIRI_BIT_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiXorBitSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_xor_bit_sama_dengan,
      [this]() { return this->parseOperasiOrBitSamaDengan(); },
      TokenType::XOR_BIT_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiOrBitSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_or_bit_sama_dengan,
      [this]() { return this->parseOperasiAndBitSamaDengan(); },
      TokenType::OR_BIT_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiAndBitSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_and_bit_sama_dengan,
      [this]() { return this->parseOperasiKurangSamaDengan(); },
      TokenType::AND_BIT_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiKurangSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_kurang_sama_dengan,
      [this]() { return this->parseOperasiTambahSamaDengan(); },
      TokenType::KURANG_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiTambahSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_tambah_sama_dengan,
      [this]() { return this->parseOperasiSisaBagiSamaDengan(); },
      TokenType::TAMBAH_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiSisaBagiSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_sisa_bagi_sama_dengan,
      [this]() { return this->parseOperasiBagiSamaDengan(); },
      TokenType::SISA_BAGI_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiBagiSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_bagi_sama_dengan,
      [this]() { return this->parseOperasiKaliSamaDengan(); },
      TokenType::BAGI_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiKaliSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_kali_sama_dengan,
      [this]() { return this->parseOperasiSamaDengan(); },
      TokenType::KALI_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_sama_dengan,
      [this]() { return this->parseOperasiKondisional(); },
      TokenType::SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiKondisional() {
  std::unique_ptr<ParserTree> operasiKondisional =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_kondisional);
  operasiKondisional->addChild(this->parseOperasiAtau());
  if(match(TokenType::TANDA_TANYA)) {
    operasiKondisional->addChild(this->eat(TokenType::TANDA_TANYA));
    operasiKondisional->addChild(this->parseEkspresi());
    operasiKondisional->addChild(this->eat(TokenType::TITIK_DUA));
    operasiKondisional->addChild(this->parseEkspresi());
  }
  return operasiKondisional;
}

std::unique_ptr<ParserTree> Parser::parseOperasiAtau() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_atau, [this]() { return this->parseOperasiDan(); },
      TokenType::ATAU
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiDan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_dan, [this]() { return this->parseOperasiOrBit(); },
      TokenType::DAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiOrBit() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_or_bit,
      [this]() { return this->parseOperasiXorBit(); }, TokenType::OR_BIT
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiXorBit() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_xor_bit,
      [this]() { return this->parseOperasiAndBit(); }, TokenType::XOR_BIT
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiAndBit() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_and_bit,
      [this]() { return this->parseOperasiTidakSama(); }, TokenType::AND_BIT
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiTidakSama() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_tidak_sama,
      [this]() { return this->parseOperasiSama(); }, TokenType::TIDAK_SAMA
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiSama() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_sama,
      [this]() { return this->parseOperasiLebihBesarSamaDengan(); },
      TokenType::SAMA
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiLebihBesarSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_lebih_besar_sama_dengan,
      [this]() { return this->parseOperasiLebihBesar(); },
      TokenType::LEBIH_BESAR_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiLebihBesar() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_lebih_besar,
      [this]() { return this->parseOperasiLebihKecilSamaDengan(); },
      TokenType::LEBIH_BESAR
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiLebihKecilSamaDengan() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_lebih_kecil_sama_dengan,
      [this]() { return this->parseOperasiLebihKecil(); },
      TokenType::LEBIH_KECIL_SAMA_DENGAN
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiLebihKecil() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_lebih_kecil,
      [this]() { return this->parseOperasiGeserKananBit(); },
      TokenType::LEBIH_KECIL
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiGeserKananBit() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_geser_kanan_bit,
      [this]() { return this->parseOperasiGeserKiriBit(); },
      TokenType::GESER_KANAN_BIT
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiGeserKiriBit() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_geser_kiri_bit,
      [this]() { return this->parseOperasiKurang(); }, TokenType::GESER_KIRI_BIT
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiKurang() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_kurang,
      [this]() { return this->parseOperasiTambah(); }, TokenType::KURANG
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiTambah() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_tambah,
      [this]() { return this->parseOperasiSisaPembagian(); }, TokenType::TAMBAH
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiSisaPembagian() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_sisa_pembagian,
      [this]() { return this->parseOperasiPembagian(); }, TokenType::SISA_BAGI
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiPembagian() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_pembagian,
      [this]() { return this->parseOperasiPerkalian(); }, TokenType::BAGI
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiPerkalian() {
  return this->fragmentMultiOperasiLeftRight(
      ParserRule::operasi_perkalian,
      [this]() { return this->parseOperasiTidak(); }, TokenType::KALI
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiTidak() {
  return this->fragmentOperasiPrePost(
      ParserRule::operasi_tidak,
      [this]() { return this->parseOperasiNotBit(); }, TokenType::TIDAK, true,
      false
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiNotBit() {
  return this->fragmentOperasiPrePost(
      ParserRule::operasi_not_bit,
      [this]() { return this->parseOperasiKurangSatu(); }, TokenType::NOT_BIT,
      true, false
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiKurangSatu() {
  return this->fragmentOperasiPrePost(
      ParserRule::operasi_kurang_satu,
      [this]() { return this->parseOperasiTambahSatu(); },
      TokenType::KURANG_SATU, true, true
  );
}

std::unique_ptr<ParserTree> Parser::parseOperasiTambahSatu() {
  return this->fragmentOperasiPrePost(
      ParserRule::operasi_tambah_satu, [this]() { return this->parseNilai(); },
      TokenType::TAMBAH_SATU, true, true
  );
}

std::unique_ptr<ParserTree> Parser::parseNilai() {
  std::unique_ptr<ParserTree> ekspresi_nilai =
      std::make_unique<ParserRuleTree>(ParserRule::nilai);
  const nstd::daftar<TokenType> types = {
      TokenType::BILANGAN, TokenType::BENAR, TokenType::SALAH
  };
  this->skipWs();
  if(this->matchOr(types)) {
    for(const TokenType& type : types) {
      if(this->match(type)) {
        ekspresi_nilai->addChild(this->eat(type));
        return ekspresi_nilai;
      }
    }
  } else if(this->matchOr({TokenType::KUTIP_SATU, TokenType::KUTIP_DUA})) {
    ekspresi_nilai->addChild(this->parseNilaiKalimat());
    return ekspresi_nilai;
  } else if(this->match(TokenType::KURUNG_BUKA)) {
    ekspresi_nilai->addChild(eat(TokenType::KURUNG_BUKA));
    ekspresi_nilai->addChild(this->parseEkspresi());
    ekspresi_nilai->addChild(eat(TokenType::KURUNG_TUTUP));
    return ekspresi_nilai;
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->currentToken,
      std::format(
          "'{}' bukan {} yang valid.", toString(this->currentToken.getType()),
          toString(ParserRule::nilai)
      )
  ));
}

std::unique_ptr<ParserTree> Parser::parseNilaiKalimat() {
  std::unique_ptr<ParserTree> nilaiKalimat =
      std::make_unique<ParserRuleTree>(ParserRule::nilai_kalimat);
  TokenType kutipPembukaType = TokenType::KUTIP_SATU;
  if(match(TokenType::KUTIP_SATU)) {
    nilaiKalimat->addChild(eat(TokenType::KUTIP_SATU, false));
  } else {
    nilaiKalimat->addChild(eat(TokenType::KUTIP_DUA, false));
    kutipPembukaType = TokenType::KUTIP_DUA;
  }
  while(!this->match(kutipPembukaType)) {
    if(this->match(TokenType::GARIS_MIRING_KEBALIK)) {
      nilaiKalimat->addChild(eat(this->currentToken.getType(), false));
      nilaiKalimat->addChild(eat(this->currentToken.getType(), false));
    } else if(this->match(TokenType::DOLAR)) {
      nilaiKalimat->addChild(eat(TokenType::DOLAR, false));
      if(this->match(TokenType::KURUNG_KURAWAL_BUKA)) {
        nilaiKalimat->addChild(eat(TokenType::KURUNG_KURAWAL_BUKA));
        nilaiKalimat->addChild(this->parseEkspresi());
        nilaiKalimat->addChild(eat(TokenType::KURUNG_KURAWAL_TUTUP, false));
      } else {
        throw std::runtime_error(this->errorInfo.inLine(
            this->currentToken,
            "Kalimat interpolasi harus berisi identifikasi atau blok kode."
        ));
      }
    } else {
      if(matchOr(
             {TokenType::BARIS_BARU, TokenType::OTHER_WHITESPACE,
              TokenType::AKHIR_DARI_FILE}
         )) {
        throw std::runtime_error(
            this->errorInfo.inLine(this->currentToken, "Kalimat tidak valid.")
        );
      }
      nilaiKalimat->addChild(eat(this->currentToken.getType(), false));
    }
  }
  nilaiKalimat->addChild(eat(kutipPembukaType));
  return nilaiKalimat;
}
