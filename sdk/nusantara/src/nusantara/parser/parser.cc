#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/parser/parser.h>
#include <nusantara/parser/parser_rule.h>
#include <nusantara/parser/parser_tree.h>

#include <algorithm>
#include <format>
#include <memory>
#include <stdexcept>
#include <vector>

Parser::Parser(ErrorInfo errorInfo, Lexer lexer):
    errorInfo(std::move(errorInfo)),
    lexer(std::move(lexer)),
    currentToken(this->lexer.getNextToken()) {}

void Parser::eat(const TokenType &type) {
  if(this->currentToken.getType() == type) {
    this->currentToken = this->lexer.getNextToken();
    if(this->currentToken.getType() == TokenType::TIDAK_DIKENALI) {
      throw std::runtime_error(this->errorInfo.inLine(
          this->currentToken, "Karakter tidak di kenali."
      ));
    }
  } else {
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

bool Parser::match(const TokenType &type) {
  return this->currentToken.getType() == type;
}

bool Parser::matchOr(const std::vector<TokenType> &types) {
  return std::ranges::any_of(types, [this](const TokenType &type) {
    return this->match(type);
  });
}

// Fragment
std::unique_ptr<ParserTree> Parser::fragmentTokenTypeGroup(
    const std::vector<TokenType> &tokenTypes, const ParserRule &rule
) {
  for(const TokenType &type : tokenTypes) {
    if(this->currentToken.getType() == type) {
      std::unique_ptr<ParserTree> result =
          std::make_unique<ParserRuleTree>(rule);
      std::unique_ptr<ParserTree> token =
          std::make_unique<ParserTokenTree>(this->currentToken);
      result->addChild(std::move(token));
      eat(type);
      return result;
    }
  }
  throw std::runtime_error(this->errorInfo.inLine(
      this->currentToken,
      std::format(
          "'{}' bukan {} yang valid.", toString(this->currentToken.getType()),
          toString(rule)
      )
  ));
}

// Parse
std::unique_ptr<ParserTree> Parser::parse() { return this->parseNusantara(); }

std::unique_ptr<ParserTree> Parser::parseNusantara() {
  std::unique_ptr<ParserTree> nusantara =
      std::make_unique<ParserRuleTree>(ParserRule::nusantara);
  while(!match(TokenType::AKHIR_DARI_FILE)) {
    std::unique_ptr<ParserTree> operasiPenugasan =
        this->parseOperasiPenugasan();
    nusantara->addChild(std::move(operasiPenugasan));
    std::unique_ptr<ParserTree> titikKoma =
        std::make_unique<ParserTokenTree>(this->currentToken);
    nusantara->addChild(std::move(titikKoma));
    eat(TokenType::TITIK_KOMA);
  }
  return nusantara;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPenugasan() {
  std::vector<TokenType> types = {TokenType::SAMA_DENGAN};
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_penugasan);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPenugasan() {
  std::unique_ptr<ParserTree> operasiPenugasan =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_penugasan);
  std::unique_ptr<ParserTree> left = this->parseOperasiPenugasanPenjumlahan();
  operasiPenugasan->addChild(std::move(left));
  while(this->matchOr({TokenType::SAMA_DENGAN})) {
    std::unique_ptr<ParserTree> operatorPenugasan =
        this->parseOperatorPenugasan();
    operasiPenugasan->addChild(std::move(operatorPenugasan));
    std::unique_ptr<ParserTree> right =
        this->parseOperasiPenugasanPenjumlahan();
    operasiPenugasan->addChild(std::move(right));
  }
  return operasiPenugasan;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPenugasanPenjumlahan() {
  std::vector<TokenType> types = {
      TokenType::TAMBAH_SAMA_DENGAN, TokenType::KURANG_SAMA_DENGAN
  };
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_penugasan);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPenugasanPenjumlahan() {
  std::unique_ptr<ParserTree> operasiPenugasanPenjumlahan =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_penugasan_penjumlahan
      );
  std::unique_ptr<ParserTree> left = this->parseOperasiPenugasanPerkalian();
  operasiPenugasanPenjumlahan->addChild(std::move(left));
  while(this->matchOr(
      {TokenType::TAMBAH_SAMA_DENGAN, TokenType::KURANG_SAMA_DENGAN}
  )) {
    std::unique_ptr<ParserTree> operatorPenugasanPenjumlahan =
        this->parseOperatorPenugasanPenjumlahan();
    operasiPenugasanPenjumlahan->addChild(std::move(operatorPenugasanPenjumlahan
    ));
    std::unique_ptr<ParserTree> right = this->parseOperasiPenugasanPerkalian();
    operasiPenugasanPenjumlahan->addChild(std::move(right));
  }
  return operasiPenugasanPenjumlahan;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPenugasanPerkalian() {
  std::vector<TokenType> types = {
      TokenType::KALI_SAMA_DENGAN, TokenType::BAGI_SAMA_DENGAN,
      TokenType::SISA_BAGI_SAMA_DENGAN
  };
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_penugasan);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPenugasanPerkalian() {
  std::unique_ptr<ParserTree> operasiPenugasanPerkalian =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_penugasan_perkalian);
  std::unique_ptr<ParserTree> left = this->parseOperasiLogika();
  operasiPenugasanPerkalian->addChild(std::move(left));
  while(this->matchOr(
      {TokenType::KALI_SAMA_DENGAN, TokenType::BAGI_SAMA_DENGAN,
       TokenType::SISA_BAGI_SAMA_DENGAN}
  )) {
    std::unique_ptr<ParserTree> operatorPenugasanPerkalian =
        this->parseOperatorPenugasanPerkalian();
    operasiPenugasanPerkalian->addChild(std::move(operatorPenugasanPerkalian));
    std::unique_ptr<ParserTree> right = this->parseOperasiLogika();
    operasiPenugasanPerkalian->addChild(std::move(right));
  }
  return operasiPenugasanPerkalian;
}

std::unique_ptr<ParserTree> Parser::parseOperatorLogika() {
  std::vector<TokenType> types = {TokenType::DAN, TokenType::ATAU};
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_logika);
}

std::unique_ptr<ParserTree> Parser::parseOperasiLogika() {
  std::unique_ptr<ParserTree> operasiLogika =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_logika);
  std::unique_ptr<ParserTree> left = this->parseOperasiLogikaTidak();
  operasiLogika->addChild(std::move(left));
  while(this->matchOr({TokenType::DAN, TokenType::ATAU})) {
    std::unique_ptr<ParserTree> operatorLogika = this->parseOperatorLogika();
    operasiLogika->addChild(std::move(operatorLogika));
    std::unique_ptr<ParserTree> right = this->parseOperasiLogikaTidak();
    operasiLogika->addChild(std::move(right));
  }
  return operasiLogika;
}

std::unique_ptr<ParserTree> Parser::parseOperatorLogikaTidak() {
  std::vector<TokenType> types = {TokenType::TIDAK};
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_logika_tidak);
}

std::unique_ptr<ParserTree> Parser::parseOperasiLogikaTidak() {
  std::unique_ptr<ParserTree> operasiLogikaTidak =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_logika_tidak);
  if(match(TokenType::TIDAK)) {
    std::unique_ptr<ParserTree> operatorLogikaTidak =
        this->parseOperatorLogikaTidak();
    operasiLogikaTidak->addChild(std::move(operatorLogikaTidak));
  }
  std::unique_ptr<ParserTree> left = this->parseOperasiPerbandingan();
  operasiLogikaTidak->addChild(std::move(left));
  return operasiLogikaTidak;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPerbandingan() {
  std::vector<TokenType> types = {
      TokenType::SAMA,
      TokenType::TIDAK_SAMA,
      TokenType::LEBIH_BESAR,
      TokenType::LEBIH_KECIL,
      TokenType::LEBIH_BESAR_SAMA_DENGAN,
      TokenType::LEBIH_KECIL_SAMA_DENGAN
  };
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_perbandingan);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPerbandingan() {
  std::unique_ptr<ParserTree> operasiPerbandingan =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_perbandingan);
  std::unique_ptr<ParserTree> left = this->parseOperasiPrePost();
  operasiPerbandingan->addChild(std::move(left));
  while(this->matchOr(
      {TokenType::SAMA, TokenType::TIDAK_SAMA, TokenType::LEBIH_BESAR,
       TokenType::LEBIH_KECIL, TokenType::LEBIH_BESAR_SAMA_DENGAN,
       TokenType::LEBIH_KECIL_SAMA_DENGAN}
  )) {
    std::unique_ptr<ParserTree> operatorPerbandingan =
        this->parseOperatorPerbandingan();
    operasiPerbandingan->addChild(std::move(operatorPerbandingan));
    std::unique_ptr<ParserTree> right = this->parseOperasiPrePost();
    operasiPerbandingan->addChild(std::move(right));
  }
  return operasiPerbandingan;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPrePost() {
  std::vector<TokenType> types = {
      TokenType::TAMBAH_SATU, TokenType::KURANG_SATU
  };
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_pre_post);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPrePost() {
  std::unique_ptr<ParserTree> operasiPrePost =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_pre_post);
  if(this->matchOr({TokenType::TAMBAH_SATU, TokenType::KURANG_SATU})) {
    std::unique_ptr<ParserTree> operatorPrePost = this->parseOperatorPrePost();
    operasiPrePost->addChild(std::move(operatorPrePost));
    std::unique_ptr<ParserTree> nilai = this->parseOperasiPenjumlahan();
    operasiPrePost->addChild(std::move(nilai));
  } else {
    std::unique_ptr<ParserTree> nilai = this->parseOperasiPenjumlahan();
    operasiPrePost->addChild(std::move(nilai));
    if(this->matchOr({TokenType::TAMBAH_SATU, TokenType::KURANG_SATU})) {
      std::unique_ptr<ParserTree> operatorPrePost =
          this->parseOperatorPrePost();
      operasiPrePost->addChild(std::move(operatorPrePost));
    }
  }
  return operasiPrePost;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPenjumlahan() {
  std::vector<TokenType> types = {TokenType::TAMBAH, TokenType::KURANG};
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_penjumlahan);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPenjumlahan() {
  std::unique_ptr<ParserTree> operasiPenjumlahan =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_penjumlahan);
  std::unique_ptr<ParserTree> left = this->parseOperasiPerkalian();
  operasiPenjumlahan->addChild(std::move(left));
  while(this->matchOr({TokenType::TAMBAH, TokenType::KURANG})) {
    std::unique_ptr<ParserTree> operatorPenjumlahan =
        this->parseOperatorPenjumlahan();
    operasiPenjumlahan->addChild(std::move(operatorPenjumlahan));
    std::unique_ptr<ParserTree> right = this->parseOperasiPerkalian();
    operasiPenjumlahan->addChild(std::move(right));
  }
  return operasiPenjumlahan;
}

std::unique_ptr<ParserTree> Parser::parseOperatorPerkalian() {
  std::vector<TokenType> types = {
      TokenType::KALI, TokenType::BAGI, TokenType::SISA_BAGI
  };
  return this->fragmentTokenTypeGroup(types, ParserRule::operator_perkalian);
}

std::unique_ptr<ParserTree> Parser::parseOperasiPerkalian() {
  std::unique_ptr<ParserTree> operasiPerkalian =
      std::make_unique<ParserRuleTree>(ParserRule::operasi_perkalian);
  std::unique_ptr<ParserTree> left = this->parseNilai();
  operasiPerkalian->addChild(std::move(left));
  while(this->matchOr({TokenType::KALI, TokenType::BAGI, TokenType::SISA_BAGI})
  ) {
    std::unique_ptr<ParserTree> operatorPerkalian =
        this->parseOperatorPerkalian();
    operasiPerkalian->addChild(std::move(operatorPerkalian));
    std::unique_ptr<ParserTree> right = this->parseNilai();
    operasiPerkalian->addChild(std::move(right));
  }
  return operasiPerkalian;
}

std::unique_ptr<ParserTree> Parser::parseNilai() {
  std::vector<TokenType> types = {TokenType::BILANGAN, TokenType::KALIMAT,
                                  TokenType::BENAR,    TokenType::SALAH};
  if(this->matchOr(types)) {
    return this->fragmentTokenTypeGroup(types, ParserRule::nilai);
  } else if(this->match(TokenType::KURUNG_BUKA)) {
    std::unique_ptr<ParserTree> ekspresi_nilai =
        std::make_unique<ParserRuleTree>(ParserRule::nilai);
    std::unique_ptr<ParserTree> kurungBuka =
        std::make_unique<ParserTokenTree>(this->currentToken);
    ekspresi_nilai->addChild(std::move(kurungBuka));
    eat(TokenType::KURUNG_BUKA);
    std::unique_ptr<ParserTree> operatorPenugasan =
        this->parseOperasiPenugasan();
    ekspresi_nilai->addChild(std::move(operatorPenugasan));
    std::unique_ptr<ParserTree> kurungTutup =
        std::make_unique<ParserTokenTree>(this->currentToken);
    ekspresi_nilai->addChild(std::move(kurungTutup));
    eat(TokenType::KURUNG_TUTUP);
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
