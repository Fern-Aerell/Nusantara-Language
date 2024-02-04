#include <nusantara/visitor/context/operator_penugasan_penjumlahan_context.h>

OperatorPenugasanPenjumlahanContext::OperatorPenugasanPenjumlahanContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPenugasanPenjumlahanContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPenugasanPenjumlahanContext OperatorPenugasanPenjumlahanContext::generateOperatorPenugasanPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
  const std::unique_ptr<ParserTree>& child0 = children[0];
  auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
  return OperatorPenugasanPenjumlahanContext(
    std::make_unique<Token>(pttchild0->getToken())
  );
}