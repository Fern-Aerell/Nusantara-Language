#include "nusantara/core/core.h"
#include "nusantara/lexer/token_type.h"
#include <nusantara/visitor/context/operator_penjumlahan_context.h>
#include <stdexcept>

OperatorPenjumlahanContext::OperatorPenjumlahanContext(
  nstd::bisa_kosong<Token> simbolOp)
    : simbolOp(std::move(simbolOp))
{}

OperatorPenjumlahanContext OperatorPenjumlahanContext::generate(
  const std::vector<std::unique_ptr<ParserTree>> &children)
{
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  nstd::konst<nstd::daftar<TokenType>> tokenTypes
    = {TokenType::TAMBAH, TokenType::KURANG};
  if(nstd::contains(tokenTypes, type))
    {
      nstd::bisa_kosong<Token> simbolOpPenjumlahan = token;
      return OperatorPenjumlahanContext(std::move(simbolOpPenjumlahan));
    }
  throw std::runtime_error("Operator penjumlahan tidak valid");
}

nstd::bisa_kosong<Token> OperatorPenjumlahanContext::getSimbolOp() const
{
  return this->simbolOp;
}