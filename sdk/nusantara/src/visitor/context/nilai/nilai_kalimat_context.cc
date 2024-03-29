#include "visitor/context/nilai/nilai_kalimat_context.h"

#include "visitor/context/ekspresi/ekspresi_context.h"

NilaiKalimatContext::NilaiKalimatContext(
    std::vector<Token> kumpulanToken,
    std::vector<std::unique_ptr<Context>> kumpulanEkspresiContext
):
    kumpulanToken(std::move(kumpulanToken)),
    kumpulanEkspresiContext(std::move(kumpulanEkspresiContext)){};

NilaiKalimatContext NilaiKalimatContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<Token> kumpulanToken;
  std::vector<std::unique_ptr<Context>> kumpulanEkspresiContext;
  for(size_t index = 0; index < children.size(); ++index) {
    if(index != 0 && index != (children.size() - 1)) {
      if(auto* ptchildRule =
             dynamic_cast<ParserRuleTree*>(children[index].get())) {
        kumpulanEkspresiContext.push_back(std::make_unique<EkspresiContext>(
            EkspresiContext::generate(ptchildRule->getChildren())
        ));
      } else if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(children[index].get())) {
        kumpulanToken.push_back(ptchildToken->getToken());
      }
    }
  }
  return {std::move(kumpulanToken), std::move(kumpulanEkspresiContext)};
}

const std::vector<Token>& NilaiKalimatContext::getKumpulanToken() const {
  return this->kumpulanToken;
}

const std::vector<std::unique_ptr<Context>>&
NilaiKalimatContext::getkumpulanEkspresiContext() const {
  return this->kumpulanEkspresiContext;
}
