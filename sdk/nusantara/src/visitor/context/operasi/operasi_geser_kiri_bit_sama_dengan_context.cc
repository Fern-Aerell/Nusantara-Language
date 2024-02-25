#include "visitor/context/operasi/operasi_geser_kiri_bit_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_xor_bit_sama_dengan_context.h"

OperasiGeserKiriBitSamaDenganContext::OperasiGeserKiriBitSamaDenganContext(
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiXorBitSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiXorBitSamaDenganContext(
        std::move(kumpulanOperasiXorBitSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiGeserKiriBitSamaDenganContext
OperasiGeserKiriBitSamaDenganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiXorBitSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_xor_bit_sama_dengan) {
        kumpulanOperasiXorBitSamaDenganContext.push_back(
            std::make_unique<OperasiXorBitSamaDenganContext>(
                OperasiXorBitSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::GESER_KIRI_BIT_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiGeserKiriBitSamaDenganContext(
      std::move(kumpulanOperasiXorBitSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiGeserKiriBitSamaDenganContext::getKumpulanOperasiXorBitSamaDenganContext(
) const {
  return this->kumpulanOperasiXorBitSamaDenganContext;
}

const std::vector<Token>&
OperasiGeserKiriBitSamaDenganContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
