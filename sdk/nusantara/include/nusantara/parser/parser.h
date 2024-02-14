#pragma once

#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>
#include <vector>

class Parser {
  public:
    Parser(ErrorInfo errorInfo, Lexer lexer);
    std::unique_ptr<ParserTree> parse();

  private:
    ErrorInfo errorInfo;
    Lexer lexer;
    Token currentToken;
    void eat(const TokenType &type);
    bool match(const TokenType &type);
    bool matchOr(const std::vector<TokenType> &types);
    // fragment
    std::unique_ptr<ParserTree> fragmentTokenTypeGroup(
        const std::vector<TokenType> &tokenTypes, const ParserRule &rule
    );
    // parse
    std::unique_ptr<ParserTree> parseNusantara();
    std::unique_ptr<ParserTree> parseOperatorPenugasan();
    std::unique_ptr<ParserTree> parseOperasiPenugasan();
    std::unique_ptr<ParserTree> parseOperatorPenugasanPenjumlahan();
    std::unique_ptr<ParserTree> parseOperasiPenugasanPenjumlahan();
    std::unique_ptr<ParserTree> parseOperatorPenugasanPerkalian();
    std::unique_ptr<ParserTree> parseOperasiPenugasanPerkalian();
    std::unique_ptr<ParserTree> parseOperatorLogika();
    std::unique_ptr<ParserTree> parseOperasiLogika();
    std::unique_ptr<ParserTree> parseOperatorLogikaTidak();
    std::unique_ptr<ParserTree> parseOperasiLogikaTidak();
    std::unique_ptr<ParserTree> parseOperatorPerbandingan();
    std::unique_ptr<ParserTree> parseOperasiPerbandingan();
    std::unique_ptr<ParserTree> parseOperatorPenjumlahan();
    std::unique_ptr<ParserTree> parseOperasiPenjumlahan();
    std::unique_ptr<ParserTree> parseOperatorPrePost();
    std::unique_ptr<ParserTree> parseOperasiPrePost();
    std::unique_ptr<ParserTree> parseOperatorPerkalian();
    std::unique_ptr<ParserTree> parseOperasiPerkalian();
    std::unique_ptr<ParserTree> parseNilai();
};
