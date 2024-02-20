#include "visitor/context/operasi/operasi_lebih_besar_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_lebih_besar_context.h"

OperasiLebihBesarSamaDenganContext::OperasiLebihBesarSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiLebihBesarContext(std::move(kumpulanOperasiLebihBesarContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiLebihBesarSamaDenganContext OperasiLebihBesarSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_lebih_besar) {
        kumpulanOperasiLebihBesarContext.push_back(
            std::make_unique<OperasiLebihBesarContext>(
                OperasiLebihBesarContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::LEBIH_BESAR_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiLebihBesarSamaDenganContext(
      std::move(kumpulanOperasiLebihBesarContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiLebihBesarSamaDenganContext::getKumpulanOperasiLebihBesarContext(
) const {
  return this->kumpulanOperasiLebihBesarContext;
}

const nstd::daftar<Token>&
OperasiLebihBesarSamaDenganContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
