#include "visitor/context/operasi/operasi_kurang_satu_context.h"

#include <optional>

#include "visitor/context/operasi/operasi_tambah_satu_context.h"

OperasiKurangSatuContext::OperasiKurangSatuContext(
    const bool& isPre, const bool& isPost,
    std::unique_ptr<Context> operasiTambahSatuContext,
    std::optional<Token> satuOperator
):
    isPre(isPre),
    isPost(isPost),
    operasiTambahSatuContext(std::move(operasiTambahSatuContext)),
    satuOperator(std::move(satuOperator)) {}

OperasiKurangSatuContext OperasiKurangSatuContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> operasiTambahSatuContext;
  std::optional<Token> satuOperator;
  bool isPre = false;
  bool isPost = false;
  size_t index = 0;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::KURANG_SATU) {
        if(index == 0) {
          isPre = true;
          isPost = false;
        } else {
          isPre = false;
          isPost = true;
        }
        satuOperator = ptt->getToken();
      }
    } else if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_tambah_satu) {
        operasiTambahSatuContext = std::make_unique<OperasiTambahSatuContext>(
            OperasiTambahSatuContext::generate(prt->getChildren())
        );
      }
    }
    ++index;
  }
  return OperasiKurangSatuContext(
      isPre, isPost, std::move(operasiTambahSatuContext),
      std::move(satuOperator)
  );
}

const bool& OperasiKurangSatuContext::getIsPre() const { return this->isPre; }

const bool& OperasiKurangSatuContext::getIsPost() const { return this->isPost; }

const std::unique_ptr<Context>&
OperasiKurangSatuContext::getOperasiTambahSatuContext() const {
  return this->operasiTambahSatuContext;
}

const std::optional<Token>& OperasiKurangSatuContext::getSatuOperator() const {
  return this->satuOperator;
}
