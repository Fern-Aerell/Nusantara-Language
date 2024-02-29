#include "visitor/context/operasi/operasi_tambah_satu_context.h"

#include <optional>

#include "visitor/context/nilai/nilai_context.h"

OperasiTambahSatuContext::OperasiTambahSatuContext(
    const bool& isPre, const bool& isPost,
    std::unique_ptr<Context> nilaiContext, std::optional<Token> satuOperator
):
    isPre(isPre),
    isPost(isPost),
    nilaiContext(std::move(nilaiContext)),
    satuOperator(std::move(satuOperator)) {}

OperasiTambahSatuContext OperasiTambahSatuContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> nilaiContext;
  std::optional<Token> satuOperator;
  bool isPre = false;
  bool isPost = false;
  size_t index = 0;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(ptt->getToken().getType() == TokenType::TAMBAH_SATU) {
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
      if(prt->getRule() == ParserRule::nilai) {
        nilaiContext = std::make_unique<NilaiContext>(
            NilaiContext::generate(prt->getChildren())
        );
      }
    }
    ++index;
  }
  return OperasiTambahSatuContext(
      isPre, isPost, std::move(nilaiContext), std::move(satuOperator)
  );
}

const bool& OperasiTambahSatuContext::getIsPre() const { return this->isPre; }

const bool& OperasiTambahSatuContext::getIsPost() const { return this->isPost; }

const std::unique_ptr<Context>& OperasiTambahSatuContext::getNilaiContext(
) const {
  return this->nilaiContext;
}

const std::optional<Token>& OperasiTambahSatuContext::getSatuOperator() const {
  return this->satuOperator;
}
