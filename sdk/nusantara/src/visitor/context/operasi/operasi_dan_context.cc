#include "visitor/context/operasi/operasi_dan_context.h"

#include "visitor/context/operasi/operasi_or_bit_context.h"

OperasiDanContext::OperasiDanContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiOrBitContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiOrBitContext(std::move(kumpulanOperasiOrBitContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiDanContext OperasiDanContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiOrBitContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_or_bit) {
        kumpulanOperasiOrBitContext.push_back(
            std::make_unique<OperasiOrBitContext>(
                OperasiOrBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::DAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiDanContext(
      std::move(kumpulanOperasiOrBitContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiDanContext::getKumpulanOperasiOrBitContext() const {
  return this->kumpulanOperasiOrBitContext;
}

const std::vector<Token>& OperasiDanContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
