#include "visitor/context/operasi/operasi_xor_bit_context.h"

#include "visitor/context/operasi/operasi_and_bit_context.h"

OperasiXorBitContext::OperasiXorBitContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiAndBitContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiAndBitContext(std::move(kumpulanOperasiAndBitContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiXorBitContext OperasiXorBitContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiAndBitContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_and_bit) {
        kumpulanOperasiAndBitContext.push_back(
            std::make_unique<OperasiAndBitContext>(
                OperasiAndBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::XOR_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiXorBitContext(
      std::move(kumpulanOperasiAndBitContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiXorBitContext::getKumpulanOperasiAndBitContext() const {
  return this->kumpulanOperasiAndBitContext;
}

const std::vector<Token>& OperasiXorBitContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
