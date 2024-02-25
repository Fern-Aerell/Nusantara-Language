#include "visitor/context/operasi/operasi_and_bit_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_kurang_sama_dengan_context.h"

OperasiAndBitSamaDenganContext::OperasiAndBitSamaDenganContext(
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiKurangSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiKurangSamaDenganContext(
        std::move(kumpulanOperasiKurangSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiAndBitSamaDenganContext OperasiAndBitSamaDenganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiKurangSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kurang_sama_dengan) {
        kumpulanOperasiKurangSamaDenganContext.push_back(
            std::make_unique<OperasiKurangSamaDenganContext>(
                OperasiKurangSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::AND_BIT_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiAndBitSamaDenganContext(
      std::move(kumpulanOperasiKurangSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiAndBitSamaDenganContext::getKumpulanOperasiKurangSamaDenganContext(
) const {
  return this->kumpulanOperasiKurangSamaDenganContext;
}

const std::vector<Token>& OperasiAndBitSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
