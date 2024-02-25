#include "visitor/context/operasi/operasi_sisa_pembagian.h"

#include "visitor/context/operasi/operasi_pembagian_context.h"

OperasiSisaPembagianContext::OperasiSisaPembagianContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiPembagianContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiPembagianContext(std::move(kumpulanOperasiPembagianContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiSisaPembagianContext OperasiSisaPembagianContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiPembagianContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_pembagian) {
        kumpulanOperasiPembagianContext.push_back(
            std::make_unique<OperasiPembagianContext>(
                OperasiPembagianContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::SISA_BAGI) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiSisaPembagianContext(
      std::move(kumpulanOperasiPembagianContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiSisaPembagianContext::getKumpulanOperasiPembagianContext() const {
  return this->kumpulanOperasiPembagianContext;
}

const std::vector<Token>& OperasiSisaPembagianContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
