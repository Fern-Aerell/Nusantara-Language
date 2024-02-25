#include "visitor/context/operasi/operasi_geser_kanan_bit_context.h"

#include "visitor/context/operasi/operasi_geser_kiri_bit_context.h"

OperasiGeserKananBitContext::OperasiGeserKananBitContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiGeserKiriBitContext(
        std::move(kumpulanOperasiGeserKiriBitContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiGeserKananBitContext OperasiGeserKananBitContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_geser_kiri_bit) {
        kumpulanOperasiGeserKiriBitContext.push_back(
            std::make_unique<OperasiGeserKiriBitContext>(
                OperasiGeserKiriBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::GESER_KANAN_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiGeserKananBitContext(
      std::move(kumpulanOperasiGeserKiriBitContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiGeserKananBitContext::getKumpulanOperasiGeserKiriBitContext() const {
  return this->kumpulanOperasiGeserKiriBitContext;
}

const std::vector<Token>& OperasiGeserKananBitContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
