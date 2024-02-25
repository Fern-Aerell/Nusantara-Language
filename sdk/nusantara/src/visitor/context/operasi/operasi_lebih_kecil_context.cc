#include "visitor/context/operasi/operasi_lebih_kecil_context.h"

#include "visitor/context/operasi/operasi_geser_kanan_bit_context.h"

OperasiLebihKecilContext::OperasiLebihKecilContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKananBitContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiGeserKananBitContext(
        std::move(kumpulanOperasiGeserKananBitContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiLebihKecilContext OperasiLebihKecilContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKananBitContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_geser_kanan_bit) {
        kumpulanOperasiGeserKananBitContext.push_back(
            std::make_unique<OperasiGeserKananBitContext>(
                OperasiGeserKananBitContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::LEBIH_KECIL) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiLebihKecilContext(
      std::move(kumpulanOperasiGeserKananBitContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiLebihKecilContext::getKumpulanOperasiGeserKananBitContext() const {
  return this->kumpulanOperasiGeserKananBitContext;
}

const std::vector<Token>& OperasiLebihKecilContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
