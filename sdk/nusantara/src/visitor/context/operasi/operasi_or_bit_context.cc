#include "visitor/context/operasi/operasi_or_bit_context.h"

#include "visitor/context/operasi/operasi_xor_bit_context.h"

OperasiOrBitContext::OperasiOrBitContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiXorBitContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiXorBitContext(std::move(kumpulanOperasiXorBitContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiOrBitContext OperasiOrBitContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiXorBitContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_xor_bit) {
        kumpulanOperasiXorBitContext.push_back(
            std::make_unique<OperasiXorBitContext>(
                OperasiXorBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::OR_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiOrBitContext(
      std::move(kumpulanOperasiXorBitContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiOrBitContext::getKumpulanOperasiXorBitContext() const {
  return this->kumpulanOperasiXorBitContext;
}

const std::vector<Token>& OperasiOrBitContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
