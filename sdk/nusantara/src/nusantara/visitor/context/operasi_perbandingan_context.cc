#include "nusantara/visitor/context/operasi_perbandingan_context.h"

#include <memory>

#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_pre_post_context.h"
#include "nusantara/visitor/context/operator_perbandingan_context.h"
#include "nstd/kosong.h"
#include "nstd/daftar.h"

OperasiPerbandinganContext::OperasiPerbandinganContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPrePostContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPerbandinganContext
):
    kumpulanOperasiPrePostContext(std::move(kumpulanOperasiPrePostContext)),
    kumpulanOperatorPerbandinganContext(
        std::move(kumpulanOperatorPerbandinganContext)
    ) {}

OperasiPerbandinganContext OperasiPerbandinganContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPrePostContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPerbandinganContext;
  for(const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::operasi_pre_post) {
      if(nstd::kosong(kumpulanOperasiPrePostContext)) {
        kumpulanOperasiPrePostContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperasiPrePostContext>(
              OperasiPrePostContext::generate(ptchild->getChildren())
          );
      kumpulanOperasiPrePostContext.value().push_back(std::move(context));
    } else if(rule == ParserRule::operator_perbandingan) {
      if(nstd::kosong(kumpulanOperatorPerbandinganContext)) {
        kumpulanOperatorPerbandinganContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperatorPerbandinganContext>(
              OperatorPerbandinganContext::generate(ptchild->getChildren())
          );
      kumpulanOperatorPerbandinganContext.value().push_back(std::move(context));
    }
  }
  return {
      std::move(kumpulanOperasiPrePostContext),
      std::move(kumpulanOperatorPerbandinganContext)
  };
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPerbandinganContext::getKumpulanOperasiPrePostContext() const {
  return this->kumpulanOperasiPrePostContext;
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiPerbandinganContext::getKumpulanOperatorPerbandinganContext() const {
  return this->kumpulanOperatorPerbandinganContext;
}
