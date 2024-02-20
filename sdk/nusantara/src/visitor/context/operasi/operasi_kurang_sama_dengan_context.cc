#include "visitor/context/operasi/operasi_kurang_sama_dengan_context.h"

#include "visitor/context/operasi/operasi_tambah_sama_dengan_context.h"

OperasiKurangSamaDenganContext::OperasiKurangSamaDenganContext(
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiTambahSamaDenganContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiTambahSamaDenganContext(
        std::move(kumpulanOperasiTambahSamaDenganContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiKurangSamaDenganContext OperasiKurangSamaDenganContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahSamaDenganContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_tambah_sama_dengan) {
        kumpulanOperasiTambahSamaDenganContext.push_back(
            std::make_unique<OperasiTambahSamaDenganContext>(
                OperasiTambahSamaDenganContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::KURANG_SAMA_DENGAN) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiKurangSamaDenganContext(
      std::move(kumpulanOperasiTambahSamaDenganContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiKurangSamaDenganContext::getKumpulanOperasiTambahSamaDenganContext(
) const {
  return this->kumpulanOperasiTambahSamaDenganContext;
}

const nstd::daftar<Token>& OperasiKurangSamaDenganContext::getKumpulanOperator(
) const {
  return this->kumpulanOperator;
}
