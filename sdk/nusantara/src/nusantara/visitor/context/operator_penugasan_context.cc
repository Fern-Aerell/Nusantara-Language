#include <nusantara/visitor/context/operator_penugasan_context.h>

OperatorPenugasanContext::OperatorPenugasanContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPenugasanContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPenugasanContext OperatorPenugasanContext::generateOperatorPenugasanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorPenugasanContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}