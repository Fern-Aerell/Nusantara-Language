#include "visitor/context/operasi/operasi_tidak_context.h"

#include "visitor/context/operasi/operasi_not_bit_context.h"

OperasiTidakContext::OperasiTidakContext(
    const bool& isPre, std::unique_ptr<Context> operasiNotBitContext,
    nstd::bisa_kosong<Token> satuOperator
):
    isPre(isPre),
    operasiNotBitContext(std::move(operasiNotBitContext)),
    satuOperator(std::move(satuOperator)) {}

OperasiTidakContext OperasiTidakContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> operasiNotBitContext;
  nstd::bisa_kosong<Token> satuOperator;
  bool isPre = false;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::TIDAK) {
        isPre = true;
        satuOperator = ptt->getToken();
      }
    } else if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_not_bit) {
        operasiNotBitContext = std::make_unique<OperasiNotBitContext>(
            OperasiNotBitContext::generate(prt->getChildren())
        );
      }
    }
  }
  return OperasiTidakContext(
      isPre, std::move(operasiNotBitContext), std::move(satuOperator)
  );
}

const bool& OperasiTidakContext::getIsPre() const { return this->isPre; }

const std::unique_ptr<Context>& OperasiTidakContext::getOperasiNotBitContext(
) const {
  return this->operasiNotBitContext;
}

const nstd::bisa_kosong<Token>& OperasiTidakContext::getSatuOperator() const {
  return this->satuOperator;
}
