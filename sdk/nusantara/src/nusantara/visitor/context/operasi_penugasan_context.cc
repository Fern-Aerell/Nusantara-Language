#include "nusantara/core/core.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_penugasan_context.h"
#include <memory>
#include <nusantara/visitor/context/operasi_penugasan_context.h>

OperasiPenugasanContext::OperasiPenugasanContext(
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperasiPenugasanPenjumlahanContext,
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorPenugasanContext)
    : kumpulanOperasiPenugasanPenjumlahanContext(
      std::move(kumpulanOperasiPenugasanPenjumlahanContext)),
      kumpulanOperatorPenugasanContext(
        std::move(kumpulanOperatorPenugasanContext))
{}

OperasiPenugasanContext OperasiPenugasanContext::generate(
  const std::vector<std::unique_ptr<ParserTree>> &children)
{
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperasiPenugasanPenjumlahanContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorPenugasanContext;
  for(const std::unique_ptr<ParserTree> &child : children)
    {
      auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
      const ParserRule rule = ptchild->getRule();
      if(rule == ParserRule::operasi_penugasan_penjumlahan)
        {
          if(nstd::isKosong(kumpulanOperasiPenugasanPenjumlahanContext))
            {
              kumpulanOperasiPenugasanPenjumlahanContext
                = nstd::daftar<std::unique_ptr<Context>>();
            }
          std::unique_ptr<Context> context
            = std::make_unique<OperasiPenugasanPenjumlahanContext>(
              OperasiPenugasanPenjumlahanContext::generate(
                ptchild->getChildren()));
          kumpulanOperasiPenugasanPenjumlahanContext.value().push_back(
            std::move(context));
        }
      else if(rule == ParserRule::operator_penugasan)
        {
          if(nstd::isKosong(kumpulanOperatorPenugasanContext))
            {
              kumpulanOperatorPenugasanContext
                = nstd::daftar<std::unique_ptr<Context>>();
            }
          std::unique_ptr<Context> context
            = std::make_unique<OperatorPenugasanContext>(
              OperatorPenugasanContext::generate(ptchild->getChildren()));
          kumpulanOperatorPenugasanContext.value().push_back(
            std::move(context));
        }
    }
  return {std::move(kumpulanOperasiPenugasanPenjumlahanContext),
          std::move(kumpulanOperatorPenugasanContext)};
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPenugasanContext::getKumpulanOperasiPenugasanPenjumlahanContext() const
{
  return this->kumpulanOperasiPenugasanPenjumlahanContext;
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPenugasanContext::getKumpulanOperatorPenugasanContext() const
{
  return this->kumpulanOperatorPenugasanContext;
}