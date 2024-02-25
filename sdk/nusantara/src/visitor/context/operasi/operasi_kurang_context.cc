#include "visitor/context/operasi/operasi_kurang_context.h"

#include "visitor/context/operasi/operasi_tambah_context.h"

OperasiKurangContext::OperasiKurangContext(
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTambahContext,
    std::vector<Token> kumpulanOperator
):
    kumpulanOperasiTambahContext(std::move(kumpulanOperasiTambahContext)),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiKurangContext OperasiKurangContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::vector<std::unique_ptr<Context>> kumpulanOperasiTambahContext;
  std::vector<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_tambah) {
        kumpulanOperasiTambahContext.push_back(
            std::make_unique<OperasiTambahContext>(
                OperasiTambahContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::KURANG) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiKurangContext(
      std::move(kumpulanOperasiTambahContext), std::move(kumpulanOperator)
  );
}

const std::vector<std::unique_ptr<Context>>&
OperasiKurangContext::getKumpulanOperasiTambahContext() const {
  return this->kumpulanOperasiTambahContext;
}

const std::vector<Token>& OperasiKurangContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
