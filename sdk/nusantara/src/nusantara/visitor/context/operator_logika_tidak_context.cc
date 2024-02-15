#include <nusantara/visitor/context/operator_logika_tidak_context.h>

#include <stdexcept>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/lexer/token_type.h"

OperatorLogikaTidakContext::OperatorLogikaTidakContext(
    nstd::bisa_kosong<Token> simbolOp
):
    simbolOp(std::move(simbolOp)) {}

OperatorLogikaTidakContext OperatorLogikaTidakContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  const nstd::daftar<TokenType> tokenTypes = {TokenType::TIDAK};
  if(nstd::contains(tokenTypes, type)) {
    nstd::bisa_kosong<Token> simbolOpLogika = token;
    return OperatorLogikaTidakContext(std::move(simbolOpLogika));
  }
  throw std::runtime_error("Operator logika tidak tidak valid");
}

nstd::bisa_kosong<Token> OperatorLogikaTidakContext::getSimbolOp() const {
  return this->simbolOp;
}
