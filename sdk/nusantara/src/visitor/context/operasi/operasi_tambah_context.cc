#include "visitor/context/operasi/operasi_tambah_context.h"

#include "visitor/context/operasi/operasi_sisa_pembagian.h"

OperasiTambahContext::OperasiTambahContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaPembagianContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiSisaPembagianContext(
        std::move(kumpulanOperasiSisaPembagianContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiTambahContext OperasiTambahContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaPembagianContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_sisa_pembagian) {
        kumpulanOperasiSisaPembagianContext.push_back(
            std::make_unique<OperasiSisaPembagianContext>(
                OperasiSisaPembagianContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::TAMBAH) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiTambahContext(
      std::move(kumpulanOperasiSisaPembagianContext),
      std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiTambahContext::getKumpulanOperasiSisaPembagianContext() const {
  return this->kumpulanOperasiSisaPembagianContext;
}

const nstd::daftar<Token>& OperasiTambahContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
