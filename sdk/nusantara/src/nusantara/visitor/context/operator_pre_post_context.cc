#include <nusantara/visitor/context/operator_pre_post_context.h>

OperatorPrePostContext::OperatorPrePostContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPrePostContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPrePostContext OperatorPrePostContext::generateOperatorPrePostContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorPrePostContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}