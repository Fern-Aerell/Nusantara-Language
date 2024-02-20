#include "visitor/context/operasi/operasi_bagi_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_kali_sama_dengan_context.h"

OperasiBagiSamaDenganContext::OperasiBagiSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKaliSamaDenganContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiKaliSamaDenganContext(
        std::move(kumpulanOperasiKaliSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiBagiSamaDenganContext OperasiBagiSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKaliSamaDenganContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kali_sama_dengan) {
        kumpulanOperasiKaliSamaDenganContext.push_back(
            std::make_unique<OperasiKaliSamaDenganContext>(
                OperasiKaliSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::BAGI_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiBagiSamaDenganContext(
      std::move(kumpulanOperasiKaliSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiBagiSamaDenganContext::getKumpulanOperasiKaliSamaDenganContext() const {
  return this->kumpulanOperasiKaliSamaDenganContext;
}

const nstd::daftar<Token>& OperasiBagiSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
