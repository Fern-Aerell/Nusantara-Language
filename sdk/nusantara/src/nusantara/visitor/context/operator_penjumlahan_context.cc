#include <nusantara/visitor/context/operator_penjumlahan_context.h>

OperatorPenjumlahanContext::OperatorPenjumlahanContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPenjumlahanContext::getOpSymbol() const {return this->opsymbol.get();}
    
OperatorPenjumlahanContext OperatorPenjumlahanContext::generateOperatorPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorPenjumlahanContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}