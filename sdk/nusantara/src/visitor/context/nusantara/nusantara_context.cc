#include "visitor/context/nusantara/nusantara_context.h"

#include "visitor/context/pernyataan/pernyataan_context.h"

NusantaraContext::NusantaraContext(
    std::vector<std::unique_ptr<Context>> kumpulanPernyataanContext
):
    kumpulanPernyataanContext(std::move(kumpulanPernyataanContext)) {}

NusantaraContext NusantaraContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanPernyataanContext;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::pernyataan) {
        kumpulanPernyataanContext.push_back(std::make_unique<PernyataanContext>(
            PernyataanContext::generate(prt->getChildren())
        ));
      }
    }
  }
  return NusantaraContext(std::move(kumpulanPernyataanContext));
}

const std::vector<std::unique_ptr<Context>>&
NusantaraContext::getKumpulanPernyataan() const {
  return this->kumpulanPernyataanContext;
}
