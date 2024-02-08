#include "nusantara/core/core.h"
#include "nusantara/lexer/token_type.h"
#include <nusantara/visitor/context/operator_perbandingan_context.h>

OperatorPerbandinganContext::OperatorPerbandinganContext(nstd::bisa_kosong<Token> simbolOp): simbolOp(std::move(simbolOp)) {}

OperatorPerbandinganContext OperatorPerbandinganContext::generate(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const auto* ptchild0 = dynamic_cast<ParserTokenTree*>(children[0].get());
    const Token token = ptchild0->getToken();
    const TokenType type = token.getType();
    nstd::konst<nstd::daftar<TokenType>> tokenTypes = {
        TokenType::SAMA,
        TokenType::TIDAK_SAMA,
        TokenType::LEBIH_BESAR,
        TokenType::LEBIH_KECIL,
        TokenType::LEBIH_BESAR_SAMA_DENGAN,
        TokenType::LEBIH_KECIL_SAMA_DENGAN
    };
    if(nstd::contains(tokenTypes, type)) {
        nstd::bisa_kosong<Token> simbolOpPerbandingan = token;
        return OperatorPerbandinganContext(std::move(simbolOpPerbandingan));
    }
    throw std::runtime_error("Operator perbandingan tidak valid");
}

nstd::bisa_kosong<Token> OperatorPerbandinganContext::getSimbolOp() const {
    return this->simbolOp;
}