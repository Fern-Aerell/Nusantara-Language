#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/operator_penugasan_context.h"
#include <nusantara/visitor/context/operasi_penugasan_context.h>

OperasiPenugasanContext::OperasiPenugasanContext(
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanNilaiContext,
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperatorPenugasanContext
):
kumpulanNilaiContext(std::move(kumpulanNilaiContext)),
kumpulanOperatorPenugasanContext(std::move(kumpulanOperatorPenugasanContext))
{}

OperasiPenugasanContext OperasiPenugasanContext::generate(const std::vector<std::unique_ptr<ParserTree>>& children) {
  nstd::bisa_kosong<nstd::daftar<Context>> kumpulanNilaiContext = nstd::daftar<Context>();
  nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperatorPenugasanContext = nstd::daftar<Context>();
  for(const std::unique_ptr<ParserTree>& child : children) {
    auto* ptchild = dynamic_cast<ParserRuleTree*>(child.get());
    const ParserRule rule = ptchild->getRule();
    if(rule == ParserRule::nilai) {
      kumpulanNilaiContext.value().push_back(NilaiContext::generate(ptchild->getChildren()));
    }else if(rule == ParserRule::operator_penugasan) {
      kumpulanOperatorPenugasanContext.value().push_back(OperatorPenugasanContext::generate(ptchild->getChildren()));
    }
  }
  return {
    std::move(kumpulanNilaiContext),
    std::move(kumpulanOperatorPenugasanContext)
  };
}

nstd::bisa_kosong<nstd::daftar<Context>> OperasiPenugasanContext::getKumpulanNilaiContext() const {
    return this->kumpulanNilaiContext;
}

nstd::bisa_kosong<nstd::daftar<Context>> OperasiPenugasanContext::getKumpulanOperatorPenugasanContext() const {
    return this->kumpulanOperatorPenugasanContext;
}