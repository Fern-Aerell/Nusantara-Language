#include "visitor/context/operasi/operasi_or_bit_context.h"

#include "visitor/context/operasi/operasi_xor_bit_context.h"

OperasiOrBitContext::OperasiOrBitContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiXorBitContext(std::move(kumpulanOperasiXorBitContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiOrBitContext OperasiOrBitContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_xor_bit) {
        kumpulanOperasiXorBitContext.push_back(
            std::make_unique<OperasiXorBitContext>(
                OperasiXorBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::OR_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiOrBitContext(
      std::move(kumpulanOperasiXorBitContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiOrBitContext::getKumpulanOperasiXorBitContext() const {
  return this->kumpulanOperasiXorBitContext;
}

const nstd::daftar<Token>& OperasiOrBitContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
