#include <nusantara/visitor/context/operator_logika_context.h>

#include <stdexcept>

#include "nstd/daftar.h"
#include "nusantara/lexer/token_type.h"

OperatorLogikaContext::OperatorLogikaContext(nstd::bisa_kosong<Token> simbolOp):
    simbolOp(std::move(simbolOp)) {}

OperatorLogikaContext OperatorLogikaContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  const nstd::daftar<TokenType> tokenTypes = {TokenType::DAN, TokenType::ATAU};
  if(nstd::contains(tokenTypes, type)) {
    nstd::bisa_kosong<Token> simbolOpLogika = token;
    return OperatorLogikaContext(std::move(simbolOpLogika));
  }
  throw std::runtime_error("Operator logika tidak valid");
}

nstd::bisa_kosong<Token> OperatorLogikaContext::getSimbolOp() const {
  return this->simbolOp;
}
