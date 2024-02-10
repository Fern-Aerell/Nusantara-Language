#include "nusantara/core/core.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/operator_perkalian_context.h"
#include <memory>
#include "nusantara/visitor/context/operasi_perkalian_context.h"

OperasiPerkalianContext::OperasiPerkalianContext(
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanNilaiContext,
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorPerkalianContext)
    : kumpulanNilaiContext(std::move(kumpulanNilaiContext)),
      kumpulanOperatorPerkalianContext(
        std::move(kumpulanOperatorPerkalianContext))
{}

OperasiPerkalianContext OperasiPerkalianContext::generate(
  const std::vector<std::unique_ptr<ParserTree>> &children)
{
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanNilaiContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorPerkalianContext;
  for(const std::unique_ptr<ParserTree> &child : children)
    {
      auto *ptchild = dynamic_cast<ParserRuleTree *>(child.get());
      const ParserRule rule = ptchild->getRule();
      if(rule == ParserRule::nilai)
        {
          if(nstd::isKosong(kumpulanNilaiContext))
            {
              kumpulanNilaiContext = nstd::daftar<std::unique_ptr<Context>>();
            }
          std::unique_ptr<Context> context = std::make_unique<NilaiContext>(
            NilaiContext::generate(ptchild->getChildren()));
          kumpulanNilaiContext.value().push_back(std::move(context));
        }
      else if(rule == ParserRule::operator_perkalian)
        {
          if(nstd::isKosong(kumpulanOperatorPerkalianContext))
            {
              kumpulanOperatorPerkalianContext
                = nstd::daftar<std::unique_ptr<Context>>();
            }
          std::unique_ptr<Context> context
            = std::make_unique<OperatorPerkalianContext>(
              OperatorPerkalianContext::generate(ptchild->getChildren()));
          kumpulanOperatorPerkalianContext.value().push_back(
            std::move(context));
        }
    }
  return {std::move(kumpulanNilaiContext),
          std::move(kumpulanOperatorPerkalianContext)};
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPerkalianContext::getKumpulanNilaiContext() const
{
  return this->kumpulanNilaiContext;
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
OperasiPerkalianContext::getKumpulanOperatorPerkalianContext() const
{
  return this->kumpulanOperatorPerkalianContext;
}