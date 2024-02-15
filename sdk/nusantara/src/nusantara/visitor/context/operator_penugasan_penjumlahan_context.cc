#include <nusantara/visitor/context/operator_penugasan_penjumlahan_context.h>

#include <stdexcept>

#include "nusantara/lexer/token_type.h"
#include "nstd/kosong.h"
#include "nstd/daftar.h"

OperatorPenugasanPenjumlahanContext::OperatorPenugasanPenjumlahanContext(
    nstd::bisa_kosong<Token> simbolOp
):
    simbolOp(std::move(simbolOp)) {}

OperatorPenugasanPenjumlahanContext
OperatorPenugasanPenjumlahanContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  const nstd::daftar<TokenType> tokenTypes = {
      TokenType::TAMBAH_SAMA_DENGAN, TokenType::KURANG_SAMA_DENGAN
  };
  if(nstd::contains(tokenTypes, type)) {
    nstd::bisa_kosong<Token> simbolOpPenugasanPenjumlahan = token;
    return OperatorPenugasanPenjumlahanContext(
        std::move(simbolOpPenugasanPenjumlahan)
    );
  }
  throw std::runtime_error("Operator penugasan penjumlahan tidak valid");
}

nstd::bisa_kosong<Token> OperatorPenugasanPenjumlahanContext::getSimbolOp(
) const {
  return this->simbolOp;
}
