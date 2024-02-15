#include "nusantara/visitor/context/operasi_logika_context.h"

#include <memory>

#include "nusantara/parser/parser_rule.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_logika_tidak_context.h"
#include "nusantara/visitor/context/operator_logika_context.h"
#include "nstd/kosong.h"
#include "nstd/daftar.h"

OperasiLogikaContext::OperasiLogikaContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiLogikaTidakContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorLogikaContext
):
    kumpulanOperasiLogikaTidakContext(
        std::move(kumpulanOperasiLogikaTidakContext)
    ),
    kumpulanOperatorLogikaContext(std::move(kumpulanOperatorLogikaContext)) {}

OperasiLogikaContext OperasiLogikaContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiLogikaTidakContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorLogikaContext;
  for(const auto &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    if(ptchild != nullptr) {
      const ParserRule rule = ptchild->getRule();
      if(rule == ParserRule::operasi_logika_tidak) {
        if(nstd::kosong(kumpulanOperasiLogikaTidakContext)) {
          kumpulanOperasiLogikaTidakContext =
              nstd::daftar<std::unique_ptr<Context>>();
        }
        std::unique_ptr<Context> context =
            std::make_unique<OperasiLogikaTidakContext>(
                OperasiLogikaTidakContext::generate(ptchild->getChildren())
            );
        kumpulanOperasiLogikaTidakContext.value().push_back(std::move(context));
      } else if(rule == ParserRule::operator_logika) {
        if(nstd::kosong(kumpulanOperatorLogikaContext)) {
          kumpulanOperatorLogikaContext =
              nstd::daftar<std::unique_ptr<Context>>();
        }
        std::unique_ptr<Context> context =
            std::make_unique<OperatorLogikaContext>(
                OperatorLogikaContext::generate(ptchild->getChildren())
            );
        kumpulanOperatorLogikaContext.value().push_back(std::move(context));
      }
    }
  }
  return {
      std::move(kumpulanOperasiLogikaTidakContext),
      std::move(kumpulanOperatorLogikaContext)
  };
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiLogikaContext::getKumpulanOperasiLogikaTidakContext() const {
  return this->kumpulanOperasiLogikaTidakContext;
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> &
OperasiLogikaContext::getKumpulanOperatorLogikaContext() const {
  return this->kumpulanOperatorLogikaContext;
}
