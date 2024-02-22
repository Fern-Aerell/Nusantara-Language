#include "visitor/context/operasi/operasi_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_kondisional_context.h"

OperasiSamaDenganContext::OperasiSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKondisionalContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiKondisionalContext(
        std::move(kumpulanOperasiKondisionalContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiSamaDenganContext OperasiSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKondisionalContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kondisional) {
        kumpulanOperasiKondisionalContext.push_back(
            std::make_unique<OperasiKondisionalContext>(
                OperasiKondisionalContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiSamaDenganContext(
      std::move(kumpulanOperasiKondisionalContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiSamaDenganContext::getKumpulanOperasiKondisionalContext() const {
  return this->kumpulanOperasiKondisionalContext;
}

const nstd::daftar<Token>& OperasiSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
