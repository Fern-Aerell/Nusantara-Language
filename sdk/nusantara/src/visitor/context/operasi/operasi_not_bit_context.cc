#include "visitor/context/operasi/operasi_not_bit_context.h"

#include "visitor/context/operasi/operasi_kurang_satu_context.h"

OperasiNotBitContext::OperasiNotBitContext(
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSatuContext,
    nstd::daftar<Token> kumpulanOperator
):
    kumpulanOperasiKurangSatuContext(std::move(kumpulanOperasiKurangSatuContext)
    ),
    kumpulanOperator(std::move(kumpulanOperator)) {}

OperasiNotBitContext OperasiNotBitContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSatuContext;
  nstd::daftar<Token> kumpulanOperator;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kurang_satu) {
        kumpulanOperasiKurangSatuContext.push_back(
            std::make_unique<OperasiKurangSatuContext>(
                OperasiKurangSatuContext::generate(prt->getChildren())
            )
        );
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::NOT_BIT) {
        kumpulanOperator.push_back(ptt->getToken());
      }
    }
  }
  return OperasiNotBitContext(
      std::move(kumpulanOperasiKurangSatuContext), std::move(kumpulanOperator)
  );
}

const nstd::daftar<std::unique_ptr<Context>>&
OperasiNotBitContext::getKumpulanOperasiKurangSatuContext() const {
  return this->kumpulanOperasiKurangSatuContext;
}

const nstd::daftar<Token>& OperasiNotBitContext::getKumpulanOperator() const {
  return this->kumpulanOperator;
}
