#include <nusantara/visitor/context/operator_logika_context.h>

OperatorLogikaContext::OperatorLogikaContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorLogikaContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorLogikaContext OperatorLogikaContext::generateOperatorLogikaContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorLogikaContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}