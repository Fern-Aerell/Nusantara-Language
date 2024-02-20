#include "visitor/context/operasi/operasi_pembagian_context.h"

#include "visitor/context/operasi/operasi_perkalian_context.h"

OperasiPembagianContext::OperasiPembagianContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiPerkalianContext(std::move(kumpulanOperasiPerkalianContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiPembagianContext OperasiPembagianContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_perkalian) {
        kumpulanOperasiPerkalianContext.push_back(
            std::make_unique<OperasiPerkalianContext>(
                OperasiPerkalianContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::BAGI) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiPembagianContext(
      std::move(kumpulanOperasiPerkalianContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiPembagianContext::getKumpulanOperasiPerkalianContext() const {
  return this->kumpulanOperasiPerkalianContext;
}

const nstd::daftar<Token>& OperasiPembagianContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
