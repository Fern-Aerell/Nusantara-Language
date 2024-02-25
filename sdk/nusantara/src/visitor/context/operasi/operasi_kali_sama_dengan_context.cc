#include "visitor/context/operasi/operasi_kali_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_sama_dengan_context.h"

OperasiKaliSamaDenganContext::OperasiKaliSamaDenganContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiSamaDenganContext(std::move(kumpulanOperasiSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiKaliSamaDenganContext OperasiKaliSamaDenganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_sama_dengan) {
        kumpulanOperasiSamaDenganContext.push_back(
            std::make_unique<OperasiSamaDenganContext>(
                OperasiSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::KALI_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiKaliSamaDenganContext(
      std::move(kumpulanOperasiSamaDenganContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiKaliSamaDenganContext::getKumpulanOperasiSamaDenganContext() const {
  return this->kumpulanOperasiSamaDenganContext;
}

const std::vector<Token>& OperasiKaliSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
