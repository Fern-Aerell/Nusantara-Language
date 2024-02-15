#include <nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h>

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_penugasan_perkalian_context.h"
#include "nusantara/visitor/context/operator_penugasan_penjumlahan_context.h"

OperasiPenugasanPenjumlahanContext::OperasiPenugasanPenjumlahanContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPenugasanPerkalianContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenugasanPenjumlahanContext
):
    kumpulanOperasiPenugasanPerkalianContext(
        std::move(kumpulanOperasiPenugasanPerkalianContext)
    ),
    kumpulanOperatorPenugasanPenjumlahanContext(
        std::move(kumpulanOperatorPenugasanPenjumlahanContext)
    ) {}

OperasiPenugasanPenjumlahanContext OperasiPenugasanPenjumlahanContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPenugasanPerkalianContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPenugasanPenjumlahanContext;
  for(const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::operasi_penugasan_perkalian) {
      if(nstd::kosong(kumpulanOperasiPenugasanPerkalianContext)) {
        kumpulanOperasiPenugasanPerkalianContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperasiPenugasanPerkalianContext>(
              OperasiPenugasanPerkalianContext::generate(ptchild->getChildren())
          );
      kumpulanOperasiPenugasanPerkalianContext.value().push_back(
          std::move(context)
      );
    } else if(rule == ParserRule::operator_penugasan_penjumlahan) {
      if(nstd::kosong(kumpulanOperatorPenugasanPenjumlahanContext)) {
        kumpulanOperatorPenugasanPenjumlahanContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperatorPenugasanPenjumlahanContext>(
              OperatorPenugasanPenjumlahanContext::generate(
                  ptchild->getChildren()
              )
          );
      kumpulanOperatorPenugasanPenjumlahanContext.value().push_back(
          std::move(context)
      );
    }
  }
  return {
      std::move(kumpulanOperasiPenugasanPerkalianContext),
      std::move(kumpulanOperatorPenugasanPenjumlahanContext)
  };
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPenugasanPenjumlahanContext::getKumpulanOperasiPenugasanPerkalianContext(
) const {
  return this->kumpulanOperasiPenugasanPerkalianContext;
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPenugasanPenjumlahanContext::
    getKumpulanOperatorPenugasanPenjumlahanContext() const {
  return this->kumpulanOperatorPenugasanPenjumlahanContext;
}
