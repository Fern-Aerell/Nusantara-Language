#include <nusantara/visitor/context/operator_perbandingan_context.h>

OperatorPerbandinganContext::OperatorPerbandinganContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPerbandinganContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPerbandinganContext OperatorPerbandinganContext::generateOperatorPerbandinganContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorPerbandinganContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}