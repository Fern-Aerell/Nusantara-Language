#include "visitor/context/operasi/operasi_not_bit_context.h"

#include "visitor/context/operasi/operasi_kurang_satu_context.h"

OperasiNotBitContext::OperasiNotBitContext(
		const bool& isPre, 
		std::unique_ptr<Context> operasiKurangSatuContext,
    nstd::bisa_kosong<Token> satuOperator
):
		isPre(isPre),
  	operasiKurangSatuContext(std::move(operasiKurangSatuContext)),
    satuOperator(std::move(satuOperator)) {}

OperasiNotBitContext OperasiNotBitContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> operasiKurangSatuContext;
  nstd::bisa_kosong<Token> satuOperator;
  bool isPre = false;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::NOT_BIT) {
        isPre = true;
        satuOperator = ptt->getToken();
      }
    } else if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_kurang_satu) {
        operasiKurangSatuContext = std::make_unique<OperasiKurangSatuContext>(
            OperasiKurangSatuContext::generate(prt->getChildren())
        );
      }
    }
  }
  return OperasiNotBitContext(
      isPre, 
			std::move(operasiKurangSatuContext), 
			std::move(satuOperator)
  );
}

const bool& OperasiNotBitContext::getIsPre() const { return this->isPre; }

const std::unique_ptr<Context>& OperasiNotBitContext::getOperasiKurangSatuContext(
) const {
  return this->operasiKurangSatuContext;
}

const nstd::bisa_kosong<Token>& OperasiNotBitContext::getSatuOperator() const {
  return this->satuOperator;
}
