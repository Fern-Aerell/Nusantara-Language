#include "visitor/context/operasi/operasi_lebih_besar_context.h"

#include "visitor/context/operasi/operasi_lebih_kecil_sama_dengan_context.h"

OperasiLebihBesarContext::OperasiLebihBesarContext(
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiLebihKecilSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiLebihKecilSamaDenganContext(
        std::move(kumpulanOperasiLebihKecilSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiLebihBesarContext OperasiLebihBesarContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>>
      kumpulanOperasiLebihKecilSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_lebih_kecil_sama_dengan) {
        kumpulanOperasiLebihKecilSamaDenganContext.push_back(
            std::make_unique<OperasiLebihKecilSamaDenganContext>(
                OperasiLebihKecilSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::LEBIH_BESAR) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiLebihBesarContext(
      std::move(kumpulanOperasiLebihKecilSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiLebihBesarContext::getKumpulanOperasiLebihKecilSamaDenganContext(
) const {
  return this->kumpulanOperasiLebihKecilSamaDenganContext;
}

const std::vector<Token>& OperasiLebihBesarContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
