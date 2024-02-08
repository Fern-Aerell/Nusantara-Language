#include <nusantara/visitor/context/operator_penugasan_context.h>

OperatorPenugasanContext::OperatorPenugasanContext(nstd::bisa_kosong<Token> simbolOp): simbolOp(std::move(simbolOp)) {}

OperatorPenugasanContext OperatorPenugasanContext::generate(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const auto* ptchild0 = dynamic_cast<ParserTokenTree*>(children[0].get());
    const Token token = ptchild0->getToken();
    const TokenType type = token.getType();
    if(type == TokenType::SAMA_DENGAN) {
        nstd::bisa_kosong<Token> simbolOpPenugasan = token;
        return OperatorPenugasanContext(std::move(simbolOpPenugasan));
    }
    throw std::runtime_error("Operator penugasan tidak valid");
}

nstd::bisa_kosong<Token> OperatorPenugasanContext::getSimbolOp() const {
    return this->simbolOp;
}