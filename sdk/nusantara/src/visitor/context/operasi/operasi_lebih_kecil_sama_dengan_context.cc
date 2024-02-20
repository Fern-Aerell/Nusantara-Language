#include "visitor/context/operasi/operasi_lebih_kecil_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_lebih_kecil_context.h"

OperasiLebihKecilSamaDenganContext::OperasiLebihKecilSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiLebihKecilContext(std::move(kumpulanOperasiLebihKecilContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiLebihKecilSamaDenganContext OperasiLebihKecilSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_lebih_kecil) {
        kumpulanOperasiLebihKecilContext.push_back(
            std::make_unique<OperasiLebihKecilContext>(
                OperasiLebihKecilContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::LEBIH_KECIL_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiLebihKecilSamaDenganContext(
      std::move(kumpulanOperasiLebihKecilContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiLebihKecilSamaDenganContext::getKumpulanOperasiLebihKecilContext(
) const {
  return this->kumpulanOperasiLebihKecilContext;
}

const nstd::daftar<Token>&
OperasiLebihKecilSamaDenganContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
