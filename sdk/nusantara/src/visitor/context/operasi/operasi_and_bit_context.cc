#include "visitor/context/operasi/operasi_and_bit_context.h"

#include "lexer/token_type.h"
#include "parser/parser_tree.h"
#include "visitor/context/operasi/operasi_tidak_sama_context.h"

OperasiAndBitContext::OperasiAndBitContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiTidakSamaContext(std::move(kumpulanOperasiTidakSamaContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiAndBitContext OperasiAndBitContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_tidak_sama) {
        kumpulanOperasiTidakSamaContext.push_back(
            std::make_unique<OperasiTidakSamaContext>(
                OperasiTidakSamaContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::AND_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiAndBitContext(
      std::move(kumpulanOperasiTidakSamaContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiAndBitContext::getKumpulanOperasiTidakSamaContext() const {
  return this->kumpulanOperasiTidakSamaContext;
}

const std::vector<Token>& OperasiAndBitContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
