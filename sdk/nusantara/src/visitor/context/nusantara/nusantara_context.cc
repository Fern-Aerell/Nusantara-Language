#include "visitor/context/nusantara/nusantara_context.h"

#include "visitor/context/ekspresi/ekspresi_context.h"

NusantaraContext::NusantaraContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext
):
    kumpulanEkspresiContext(std::move(kumpulanEkspresiContext)) {}

NusantaraContext NusantaraContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::ekspresi) {
        kumpulanEkspresiContext.push_back(std::make_unique<EkspresiContext>(
            EkspresiContext::generate(prt->getChildren())
        ));
      }
    }
  }
  return NusantaraContext(std::move(kumpulanEkspresiContext));
}

const nstd::daftar<std::unique_ptr<Context>>&
NusantaraContext::getKumpulanEkspresi() const {
  return this->kumpulanEkspresiContext;
}
