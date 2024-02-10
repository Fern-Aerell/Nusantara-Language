#include "nusantara/core/core.h"
#include "nusantara/lexer/token_type.h"
#include <nusantara/visitor/context/operator_perkalian_context.h>
#include <stdexcept>

OperatorPerkalianContext::OperatorPerkalianContext(
  nstd::bisa_kosong<Token> simbolOp)
    : simbolOp(std::move(simbolOp))
{}

OperatorPerkalianContext OperatorPerkalianContext::generate(
  const std::vector<std::unique_ptr<ParserTree>> &children)
{
  const auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  const Token token = ptchild0->getToken();
  const TokenType type = token.getType();
  nstd::konst<nstd::daftar<TokenType>> tokenTypes
    = {TokenType::KALI, TokenType::BAGI, TokenType::SISA_BAGI};
  if(nstd::contains(tokenTypes, type))
    {
      nstd::bisa_kosong<Token> simbolOpPerkalian = token;
      return OperatorPerkalianContext(std::move(simbolOpPerkalian));
    }
  throw std::runtime_error("Operator perkalian tidak valid");
}

nstd::bisa_kosong<Token> OperatorPerkalianContext::getSimbolOp() const
{
  return this->simbolOp;
}