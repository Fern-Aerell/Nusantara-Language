#include "nusantara/visitor/context/operasi_pre_post_context.h"

#include <memory>

#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_pre_post_context.h"
#include "nstd/kosong.h"

OperasiPrePostContext::OperasiPrePostContext(
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenjumlahanContext,
    nstd::bisa_kosong<std::unique_ptr<Context>> operatorPrePostContext,
    const bool &isPre
):
    operasiPenjumlahanContext(std::move(operasiPenjumlahanContext)),
    operatorPrePostContext(std::move(operatorPrePostContext)),
    isPre(isPre) {}

OperasiPrePostContext OperasiPrePostContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenjumlahanContext;
  nstd::bisa_kosong<std::unique_ptr<Context>> operatorPrePostContext;
  int index = 0;
  bool isPre = false;
  for(const std::unique_ptr<ParserTree> &child : children) {
    auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::operasi_penjumlahan) {
      operasiPenjumlahanContext = std::make_unique<OperasiPenjumlahanContext>(
          OperasiPenjumlahanContext::generate(ptchild->getChildren())
      );
    } else if(rule == ParserRule::operator_pre_post) {
      if(index == 0) { isPre = true; }
      operatorPrePostContext = std::make_unique<OperatorPrePostContext>(
          OperatorPrePostContext::generate(ptchild->getChildren())
      );
    }
    index++;
  }
  return {
      std::move(operasiPenjumlahanContext), std::move(operatorPrePostContext),
      isPre
  };
}

bool OperasiPrePostContext::getIsPre() const { return this->isPre; }

const nstd::bisa_kosong<std::unique_ptr<Context>> &
OperasiPrePostContext::getOperasiPenjumlahanContext() const {
  return this->operasiPenjumlahanContext;
}

const nstd::bisa_kosong<std::unique_ptr<Context>> &
OperasiPrePostContext::getOperatorPrePostContext() const {
  return this->operatorPrePostContext;
}
