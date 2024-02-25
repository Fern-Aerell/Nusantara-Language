#include "visitor/context/operasi/operasi_tambah_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_sisa_bagi_sama_dengan_context.h"

OperasiTambahSamaDenganContext::OperasiTambahSamaDenganContext(
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiSisaBagiSamaDenganContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiSisaBagiSamaDenganContext(
        std::move(kumpulanOperasiSisaBagiSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiTambahSamaDenganContext OperasiTambahSamaDenganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>>
      kumpulanOperasiSisaBagiSamaDenganContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_sisa_bagi_sama_dengan) {
        kumpulanOperasiSisaBagiSamaDenganContext.push_back(
            std::make_unique<OperasiSisaBagiSamaDenganContext>(
                OperasiSisaBagiSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::TAMBAH_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiTambahSamaDenganContext(
      std::move(kumpulanOperasiSisaBagiSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiTambahSamaDenganContext::getKumpulanOperasiSisaBagiSamaDenganContext(
) const {
  return this->kumpulanOperasiSisaBagiSamaDenganContext;
}

const std::vector<Token>& OperasiTambahSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
