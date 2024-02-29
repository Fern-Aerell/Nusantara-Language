#include "visitor/context/operasi/operasi_perkalian_context.h"

#include "visitor/context/operasi/operasi_tidak_context.h"

OperasiPerkalianContext::OperasiPerkalianContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiTidakContext(std::move(kumpulanOperasiTidakContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiPerkalianContext OperasiPerkalianContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_tidak) {
        kumpulanOperasiTidakContext.push_back(
            std::make_unique<OperasiTidakContext>(
                OperasiTidakContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::KALI) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiPerkalianContext(
      std::move(kumpulanOperasiTidakContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiPerkalianContext::getKumpulanOperasiTidakContext() const {
  return this->kumpulanOperasiTidakContext;
}

const std::vector<Token>& OperasiPerkalianContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
