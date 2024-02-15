#include "nusantara/visitor/context/operasi_penjumlahan_context.h"

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_perkalian_context.h"
#include "nusantara/visitor/context/operator_penjumlahan_context.h"

OperasiPenjumlahanContext::OperasiPenjumlahanContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPerkalianContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenjumlahanContext
):
    kumpulanOperasiPerkalianContext(std::move(kumpulanOperasiPerkalianContext)),
    kumpulanOperatorPenjumlahanContext(
        std::move(kumpulanOperatorPenjumlahanContext)
    ) {}

OperasiPenjumlahanContext OperasiPenjumlahanContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPerkalianContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPenjumlahanContext;
  for(const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::operasi_perkalian) {
      if(nstd::kosong(kumpulanOperasiPerkalianContext)) {
        kumpulanOperasiPerkalianContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperasiPerkalianContext>(
              OperasiPerkalianContext::generate(ptchild->getChildren())
          );
      kumpulanOperasiPerkalianContext.value().push_back(std::move(context));
    } else if(rule == ParserRule::operator_penjumlahan) {
      if(nstd::kosong(kumpulanOperatorPenjumlahanContext)) {
        kumpulanOperatorPenjumlahanContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperatorPenjumlahanContext>(
              OperatorPenjumlahanContext::generate(ptchild->getChildren())
          );
      kumpulanOperatorPenjumlahanContext.value().push_back(std::move(context));
    }
  }
  return {
      std::move(kumpulanOperasiPerkalianContext),
      std::move(kumpulanOperatorPenjumlahanContext)
  };
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPenjumlahanContext::getKumpulanOperasiPerkalianContext() const {
  return this->kumpulanOperasiPerkalianContext;
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPenjumlahanContext::getKumpulanOperatorPenjumlahanContext() const {
  return this->kumpulanOperatorPenjumlahanContext;
}
