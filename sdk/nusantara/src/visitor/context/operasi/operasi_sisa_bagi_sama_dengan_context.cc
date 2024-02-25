#include "visitor/context/operasi/operasi_sisa_bagi_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_bagi_sama_dengan_context.h"

OperasiSisaBagiSamaDenganContext::OperasiSisaBagiSamaDenganContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiBagiSamaDenganContext(
        std::move(kumpulanOperasiBagiSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiSisaBagiSamaDenganContext OperasiSisaBagiSamaDenganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_bagi_sama_dengan) {
        kumpulanOperasiBagiSamaDenganContext.push_back(
            std::make_unique<OperasiBagiSamaDenganContext>(
                OperasiBagiSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::SISA_BAGI_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiSisaBagiSamaDenganContext(
      std::move(kumpulanOperasiBagiSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiSisaBagiSamaDenganContext::getKumpulanOperasiBagiSamaDenganContext(
) const {
  return this->kumpulanOperasiBagiSamaDenganContext;
}

const std::vector<Token>&
OperasiSisaBagiSamaDenganContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
