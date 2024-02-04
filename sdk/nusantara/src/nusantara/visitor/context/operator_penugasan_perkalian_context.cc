#include <nusantara/visitor/context/operator_penugasan_perkalian_context.h>

OperatorPenugasanPerkalianContext::OperatorPenugasanPerkalianContext(std::unique_ptr<Token> opsymbol): opsymbol(std::move(opsymbol)) {}

Token* OperatorPenugasanPerkalianContext::getOpSymbol() const {return this->opsymbol.get();}

OperatorPenugasanPerkalianContext OperatorPenugasanPerkalianContext::generateOperatorPenugasanPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    return OperatorPenugasanPerkalianContext(
        std::make_unique<Token>(pttchild0->getToken())
    );
}