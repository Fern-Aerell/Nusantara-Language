#pragma once

#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/parser/parser_tree.h>

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "nstd/daftar.h"
#include "nusantara/parser/parser_rule.h"

class Parser {
  public:
    Parser(ErrorInfo errorInfo, Lexer lexer);
    std::unique_ptr<ParserTree> parse();

  private:
    ErrorInfo errorInfo;
    Lexer lexer;
    Token currentToken;
    std::unique_ptr<ParserTree> eat(
        const TokenType& type, const bool& skipWs = true
    );
    bool match(const TokenType& type);
    bool matchOr(const std::vector<TokenType>& types);
    // fragment
    std::unique_ptr<ParserTree> fragmentMultiOperasiLeftRight(
        const ParserRule& rule,
        const std::function<std::unique_ptr<ParserTree>()>& leftRightFunction,
        const TokenType& opSymbol
    );
    std::unique_ptr<ParserTree> fragmentOperasiPrePost(
        const ParserRule& rule,
        const std::function<std::unique_ptr<ParserTree>()>& leftFunction,
        const TokenType& opSymbol, const bool& pre, const bool& post
    );
    // parse
    std::unique_ptr<ParserTree> parseNusantara();
    std::unique_ptr<ParserTree> parseEkspresi();
    std::unique_ptr<ParserTree> parseOperasiGeserKananBitSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiGeserKiriBitSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiXorBitSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiOrBitSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiAndBitSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiKurangSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiTambahSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiSisaBagiSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiBagiSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiKaliSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiAtau();
    std::unique_ptr<ParserTree> parseOperasiDan();
    std::unique_ptr<ParserTree> parseOperasiOrBit();
    std::unique_ptr<ParserTree> parseOperasiXorBit();
    std::unique_ptr<ParserTree> parseOperasiAndBit();
    std::unique_ptr<ParserTree> parseOperasiTidakSama();
    std::unique_ptr<ParserTree> parseOperasiSama();
    std::unique_ptr<ParserTree> parseOperasiLebihBesarSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiLebihBesar();
    std::unique_ptr<ParserTree> parseOperasiLebihKecilSamaDengan();
    std::unique_ptr<ParserTree> parseOperasiLebihKecil();
    std::unique_ptr<ParserTree> parseOperasiGeserKananBit();
    std::unique_ptr<ParserTree> parseOperasiGeserKiriBit();
    std::unique_ptr<ParserTree> parseOperasiKurang();
    std::unique_ptr<ParserTree> parseOperasiTambah();
    std::unique_ptr<ParserTree> parseOperasiSisaPembagian();
    std::unique_ptr<ParserTree> parseOperasiPembagian();
    std::unique_ptr<ParserTree> parseOperasiPerkalian();
    std::unique_ptr<ParserTree> parseOperasiTidak();
    std::unique_ptr<ParserTree> parseOperasiNotBit();
    std::unique_ptr<ParserTree> parseOperasiKurangSatu();
    std::unique_ptr<ParserTree> parseOperasiTambahSatu();
    std::unique_ptr<ParserTree> parseNilai();
    std::unique_ptr<ParserTree> parseNilaiKalimat();
};
