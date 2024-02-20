#include "visitor/context/operasi/operasi_or_bit_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_and_bit_sama_dengan_context.h"

OperasiOrBitSamaDenganContext::OperasiOrBitSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiAndBitSamaDenganContext,
    nstd::daftar<Token> kumpulanOperator

):
    kumpulanOperasiAndBitSamaDenganContext(
        std::move(kumpulanOperasiAndBitSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiOrBitSamaDenganContext OperasiOrBitSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitSamaDenganContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_and_bit_sama_dengan) {
        kumpulanOperasiAndBitSamaDenganContext.push_back(
            std::make_unique<OperasiAndBitSamaDenganContext>(
                OperasiAndBitSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::OR_BIT_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiOrBitSamaDenganContext(
      std::move(kumpulanOperasiAndBitSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiOrBitSamaDenganContext::getKumpulanOperasiAndBitSamaDenganContext(
) const {
  return this->kumpulanOperasiAndBitSamaDenganContext;
}

const nstd::daftar<Token>& OperasiOrBitSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
