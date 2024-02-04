#include <nusantara/visitor/context/operator_perkalian_context.h>

OperatorPerkalianContext::OperatorPerkalianContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPerkalianContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPerkalianContext OperatorPerkalianContext::generateOperatorPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
  const std::unique_ptr<ParserTree>& child0 = children[0];
  auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
  return OperatorPerkalianContext(
    std::make_unique<Token>(pttchild0->getToken())
  );
}