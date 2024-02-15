#include <nusantara/visitor/context/operator_pre_post_context.h>

#include <stdexcept>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/lexer/token_type.h"

OperatorPrePostContext::OperatorPrePostContext(nstd::bisa_kosong<Token> simbolOp
):
    simbolOp(std::move(simbolOp)) {}

OperatorPrePostContext OperatorPrePostContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  const nstd::daftar<TokenType> tokenTypes = {
      TokenType::TAMBAH_SATU, TokenType::KURANG_SATU
  };
  if(nstd::contains(tokenTypes, type)) {
    nstd::bisa_kosong<Token> simbolOpPrePost = token;
    return OperatorPrePostContext(std::move(simbolOpPrePost));
  }
  throw std::runtime_error("Operator pre post tidak valid");
}

nstd::bisa_kosong<Token> OperatorPrePostContext::getSimbolOp() const {
  return this->simbolOp;
}
