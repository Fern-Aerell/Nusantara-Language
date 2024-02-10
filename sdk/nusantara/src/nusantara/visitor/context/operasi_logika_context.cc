#include "nusantara/visitor/context/operasi_logika_context.h"

#include <memory>

#include "nusantara/core/core.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_perbandingan_context.h"
#include "nusantara/visitor/context/operator_logika_context.h"

OperasiLogikaContext::OperasiLogikaContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPerbandinganContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorLogikaContext)
    : kumpulanOperasiPerbandinganContext(
          std::move(kumpulanOperasiPerbandinganContext)),
      kumpulanOperatorLogikaContext(std::move(kumpulanOperatorLogikaContext)) {}

OperasiLogikaContext OperasiLogikaContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPerbandinganContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorLogikaContext;
  for (const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if (rule == ParserRule::operasi_perbandingan) {
      if (nstd::isKosong(kumpulanOperasiPerbandinganContext)) {
        kumpulanOperasiPerbandinganContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperasiPerbandinganContext>(
              OperasiPerbandinganContext::generate(ptchild->getChildren()));
      kumpulanOperasiPerbandinganContext.value().push_back(std::move(context));
    } else if (rule == ParserRule::operator_logika) {
      if (nstd::isKosong(kumpulanOperatorLogikaContext)) {
        kumpulanOperatorLogikaContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperatorLogikaContext>(
              OperatorLogikaContext::generate(ptchild->getChildren()));
      kumpulanOperatorLogikaContext.value().push_back(std::move(context));
    }
  }
  return {std::move(kumpulanOperasiPerbandinganContext),
          std::move(kumpulanOperatorLogikaContext)};
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiLogikaContext::getKumpulanOperasiPerbandinganContext() const {
  return this->kumpulanOperasiPerbandinganContext;
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiLogikaContext::getKumpulanOperatorLogikaContext() const {
  return this->kumpulanOperatorLogikaContext;
}