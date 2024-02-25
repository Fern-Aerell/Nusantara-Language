#include "visitor/context/operasi/operasi_atau_context.h"

#include "visitor/context/operasi/operasi_dan_context.h"

OperasiAtauContext::OperasiAtauContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiDanContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiDanContext(std::move(kumpulanOperasiDanContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiAtauContext OperasiAtauContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiDanContext;
  std::vector<Token> kumpulanOperator;
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

const std::vector<std::unique_ptr<Context>>&
OperasiAtauContext::getKumpulanOperasiDanContext() const {
  return this->kumpulanOperasiDanContext;
}

const std::vector<Token>& OperasiAtauContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
