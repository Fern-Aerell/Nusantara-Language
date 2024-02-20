#include "visitor/context/operasi/operasi_xor_bit_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_or_bit_sama_dengan_context.h"

OperasiXorBitSamaDenganContext::OperasiXorBitSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiOrBitSamaDenganContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiOrBitSamaDenganContext(
        std::move(kumpulanOperasiOrBitSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiXorBitSamaDenganContext OperasiXorBitSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitSamaDenganContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_or_bit_sama_dengan) {
        kumpulanOperasiOrBitSamaDenganContext.push_back(
            std::make_unique<OperasiOrBitSamaDenganContext>(
                OperasiOrBitSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::XOR_BIT_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiXorBitSamaDenganContext(
      std::move(kumpulanOperasiOrBitSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiXorBitSamaDenganContext::getKumpulanOperasiOrBitSamaDenganContext(
) const {
  return this->kumpulanOperasiOrBitSamaDenganContext;
}

const nstd::daftar<Token>& OperasiXorBitSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
