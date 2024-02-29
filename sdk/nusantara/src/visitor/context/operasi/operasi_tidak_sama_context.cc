#include "visitor/context/operasi/operasi_tidak_sama_context.h"

#include "visitor/context/operasi/operasi_sama_context.h"

OperasiTidakSamaContext::OperasiTidakSamaContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiSamaContext(std::move(kumpulanOperasiSamaContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiTidakSamaContext OperasiTidakSamaContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_sama) {
        kumpulanOperasiSamaContext.push_back(
            std::make_unique<OperasiSamaContext>(
                OperasiSamaContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::TIDAK_SAMA) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiTidakSamaContext(
      std::move(kumpulanOperasiSamaContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiTidakSamaContext::getKumpulanOperasiSamaContext() const {
  return this->kumpulanOperasiSamaContext;
}

const std::vector<Token>& OperasiTidakSamaContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
