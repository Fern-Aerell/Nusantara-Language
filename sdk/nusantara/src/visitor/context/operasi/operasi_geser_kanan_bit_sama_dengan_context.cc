#include "visitor/context/operasi/operasi_geser_kanan_bit_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_geser_kiri_bit_sama_dengan_context.h"

OperasiGeserKananBitSamaDenganContext::OperasiGeserKananBitSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiGeserKiriBitSamaDenganContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiGeserKiriBitSamaDenganContext(
        std::move(kumpulanOperasiGeserKiriBitSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiGeserKananBitSamaDenganContext
OperasiGeserKananBitSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>>
      kumpulanOperasiGeserKiriBitSamaDenganContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_geser_kiri_bit_sama_dengan) {
        kumpulanOperasiGeserKiriBitSamaDenganContext.push_back(
            std::make_unique<OperasiGeserKiriBitSamaDenganContext>(
                OperasiGeserKiriBitSamaDenganContext::generate(prt->getChildren(
                ))
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::GESER_KANAN_BIT_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiGeserKananBitSamaDenganContext(
      std::move(kumpulanOperasiGeserKiriBitSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiGeserKananBitSamaDenganContext::
    getKumpulanOperasiGeserKiriBitSamaDenganContext() const {
  return this->kumpulanOperasiGeserKiriBitSamaDenganContext;
}

const nstd::daftar<Token>&
OperasiGeserKananBitSamaDenganContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
