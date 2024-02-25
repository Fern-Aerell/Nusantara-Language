#include "visitor/context/operasi/operasi_sama_context.h"

#include "visitor/context/operasi/operasi_lebih_besar_sama_dengan_context.h"

OperasiSamaContext::OperasiSamaContext(
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiLebihBesarSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiLebihBesarSamaDenganContext(
        std::move(kumpulanOperasiLebihBesarSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiSamaContext OperasiSamaContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>>
      kumpulanOperasiLebihBesarSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_lebih_besar_sama_dengan) {
        kumpulanOperasiLebihBesarSamaDenganContext.push_back(
            std::make_unique<OperasiLebihBesarSamaDenganContext>(
                OperasiLebihBesarSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::SAMA) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiSamaContext(
      std::move(kumpulanOperasiLebihBesarSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiSamaContext::getKumpulanOperasiLebihBesarSamaDenganContext() const {
  return this->kumpulanOperasiLebihBesarSamaDenganContext;
}

const std::vector<Token>& OperasiSamaContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
