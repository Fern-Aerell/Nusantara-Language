#include "nusantara/visitor/context/operasi_penugasan_perkalian_context.h"

#include <memory>

#include "nusantara/core/core.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_logika_context.h"
#include "nusantara/visitor/context/operator_penugasan_perkalian_context.h"

OperasiPenugasanPerkalianContext::OperasiPenugasanPerkalianContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiLogikaContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenugasanPerkalianContext
):
    kumpulanOperasiLogikaContext(std::move(kumpulanOperasiLogikaContext)),
    kumpulanOperatorPenugasanPerkalianContext(
        std::move(kumpulanOperatorPenugasanPerkalianContext)
    ) {}

OperasiPenugasanPerkalianContext OperasiPenugasanPerkalianContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiLogikaContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPenugasanPerkalianContext;
  for(const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::operasi_logika) {
      if(nstd::isKosong(kumpulanOperasiLogikaContext)) {
        kumpulanOperasiLogikaContext = nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context = std::make_unique<OperasiLogikaContext>(
          OperasiLogikaContext::generate(ptchild->getChildren())
      );
      kumpulanOperasiLogikaContext.value().push_back(std::move(context));
    } else if(rule == ParserRule::operator_penugasan_perkalian) {
      if(nstd::isKosong(kumpulanOperatorPenugasanPerkalianContext)) {
        kumpulanOperatorPenugasanPerkalianContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperatorPenugasanPerkalianContext>(
              OperatorPenugasanPerkalianContext::generate(ptchild->getChildren()
              )
          );
      kumpulanOperatorPenugasanPerkalianContext.value().push_back(
          std::move(context)
      );
    }
  }
  return {
      std::move(kumpulanOperasiLogikaContext),
      std::move(kumpulanOperatorPenugasanPerkalianContext)
  };
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPenugasanPerkalianContext::getKumpulanOperasiLogikaContext() const {
  return this->kumpulanOperasiLogikaContext;
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPenugasanPerkalianContext::getKumpulanOperatorPenugasanPerkalianContext(
) const {
  return this->kumpulanOperatorPenugasanPerkalianContext;
}
