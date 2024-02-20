#include "visitor/context/operasi/operasi_geser_kiri_bit_context.h"

#include "visitor/context/operasi/operasi_kurang_context.h"

OperasiGeserKiriBitContext::OperasiGeserKiriBitContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiKurangContext(std::move(kumpulanOperasiKurangContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiGeserKiriBitContext OperasiGeserKiriBitContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kurang) {
        kumpulanOperasiKurangContext.push_back(
            std::make_unique<OperasiKurangContext>(
                OperasiKurangContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::GESER_KIRI_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiGeserKiriBitContext(
      std::move(kumpulanOperasiKurangContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiGeserKiriBitContext::getKumpulanOperasiKurangContext() const {
  return this->kumpulanOperasiKurangContext;
}

const nstd::daftar<Token>& OperasiGeserKiriBitContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
