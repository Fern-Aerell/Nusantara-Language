#include "visitor/context/operasi/operasi_sisa_pembagian.h"

#include "visitor/context/operasi/operasi_pembagian_context.h"

OperasiSisaPembagianContext::OperasiSisaPembagianContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPembagianContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiPembagianContext(std::move(kumpulanOperasiPembagianContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiSisaPembagianContext OperasiSisaPembagianContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPembagianContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_sisa_pembagian) {
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

const nstd::daftar<std::unique_ptr<Context>>&
OperasiSisaPembagianContext::getKumpulanOperasiPembagianContext() const {
  return this->kumpulanOperasiPembagianContext;
}

const nstd::daftar<Token>& OperasiSisaPembagianContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
