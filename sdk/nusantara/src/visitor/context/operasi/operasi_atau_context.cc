#include "visitor/context/operasi/operasi_atau_context.h"

#include "visitor/context/operasi/operasi_dan_context.h"

OperasiAtauContext::OperasiAtauContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiDanContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiDanContext(std::move(kumpulanOperasiDanContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiAtauContext OperasiAtauContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiDanContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_dan) {
        kumpulanOperasiDanContext.push_back(std::make_unique<OperasiDanContext>(
            OperasiDanContext::generate(prt->getChildren())
        ));
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::ATAU) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiAtauContext(
      std::move(kumpulanOperasiDanContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiAtauContext::getKumpulanOperasiDanContext() const {
  return this->kumpulanOperasiDanContext;
}

const nstd::daftar<Token>& OperasiAtauContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
