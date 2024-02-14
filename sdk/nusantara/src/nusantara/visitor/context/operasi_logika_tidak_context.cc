#include "nusantara/visitor/context/operasi_logika_tidak_context.h"

#include <memory>

#include "nusantara/core/core.h"
#include "nusantara/parser/parser_rule.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_perbandingan_context.h"
#include "nusantara/visitor/context/operator_logika_tidak_context.h"

OperasiLogikaTidakContext::OperasiLogikaTidakContext(
    nstd::bisa_kosong<std::unique_ptr<Context>> operatorLogikaTidakContext,
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPerbandinganContext
):
    operatorLogikaTidakContext(std::move(operatorLogikaTidakContext)),
    operasiPerbandinganContext(std::move(operasiPerbandinganContext)) {}

OperasiLogikaTidakContext OperasiLogikaTidakContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<std::unique_ptr<Context>> operatorLogikaTidakContext;
  nstd::bisa_kosong<std::unique_ptr<Context>> operasiPerbandinganContext;
  for(const auto &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    if(ptchild != nullptr) {
      nstd::konst<ParserRule> rule = ptchild->getRule();
      if(rule == ParserRule::operator_logika_tidak) {
        operatorLogikaTidakContext =
            std::make_unique<OperatorLogikaTidakContext>(
                OperatorLogikaTidakContext::generate(ptchild->getChildren())
            );
      } else if(rule == ParserRule::operasi_perbandingan) {
        operasiPerbandinganContext =
            std::make_unique<OperasiPerbandinganContext>(
                OperasiPerbandinganContext::generate(ptchild->getChildren())
            );
      }
    }
  }
  return {
      std::move(operatorLogikaTidakContext),
      std::move(operasiPerbandinganContext)
  };
}

nstd::konst<nstd::bisa_kosong<std::unique_ptr<Context>>> &
OperasiLogikaTidakContext::getOperasiPerbandinganContext() const {
  return this->operasiPerbandinganContext;
}

nstd::konst<nstd::bisa_kosong<std::unique_ptr<Context>>> &
OperasiLogikaTidakContext::getOperatorLogikaTidakContext() const {
  return this->operatorLogikaTidakContext;
}
