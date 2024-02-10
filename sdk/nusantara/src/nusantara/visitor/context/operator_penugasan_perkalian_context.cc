#include <nusantara/visitor/context/operator_penugasan_perkalian_context.h>

#include <stdexcept>

#include "nusantara/core/core.h"
#include "nusantara/lexer/token_type.h"

OperatorPenugasanPerkalianContext::OperatorPenugasanPerkalianContext(
    nstd::bisa_kosong<Token> simbolOp)
    : simbolOp(std::move(simbolOp)) {}

OperatorPenugasanPerkalianContext OperatorPenugasanPerkalianContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children) {
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  nstd::konst<nstd::daftar<TokenType>> tokenTypes = {
      TokenType::KALI_SAMA_DENGAN, TokenType::BAGI_SAMA_DENGAN,
      TokenType::SISA_BAGI_SAMA_DENGAN};
  if (nstd::contains(tokenTypes, type)) {
    nstd::bisa_kosong<Token> simbolOpPenugasanPerkalian = token;
    return OperatorPenugasanPerkalianContext(
        std::move(simbolOpPenugasanPerkalian));
  }
  throw std::runtime_error("Operator penugasan perkalian tidak valid");
}

nstd::bisa_kosong<Token> OperatorPenugasanPerkalianContext::getSimbolOp()
    const {
  return this->simbolOp;
}