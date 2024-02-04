#include <nusantara/visitor/context/nilai_context.h>

NilaiContext::NilaiContext(
    std::unique_ptr<Token> nilai,
    std::unique_ptr<Token> kurungBuka,
    std::unique_ptr<OperasiPenugasanContext> operasiPenugasanContext,
    std::unique_ptr<Token> kurungTutup
): 
nilai(std::move(nilai)),
kurungBuka(std::move(kurungBuka)),
operasiPenugasanContext(std::move(operasiPenugasanContext)),
kurungTutup(std::move(kurungTutup))
{}

Token* NilaiContext::getNilai() const {return this->nilai.get();}

Token* NilaiContext::getKurungBuka() const {return this->kurungBuka.get();}

OperasiPenugasanContext* NilaiContext::getOperasiPenugasan() const {return this->operasiPenugasanContext.get();}

Token* NilaiContext::getKurungTutup() const {return this->kurungTutup.get();}

NilaiContext NilaiContext::generateNilaiContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    const std::unique_ptr<ParserTree>& child0 = children[0];
    auto* pttchild0 = dynamic_cast<ParserTokenTree*>(child0.get());
    if(pttchild0->getToken().getType() == TokenType::KURUNG_BUKA) {
        const std::unique_ptr<ParserTree>& child1 = children[1];
        auto* pttchild1 = dynamic_cast<ParserRuleTree*>(child1.get());
        const std::unique_ptr<ParserTree>& child2 = children[2];
        auto* pttchild2 = dynamic_cast<ParserTokenTree*>(child2.get());
        return NilaiContext(
        nullptr,
        std::make_unique<Token>(pttchild0->getToken()),
        std::make_unique<OperasiPenugasanContext>(generateOperasiPenugasanContext(pttchild1->getChildren())),
        std::make_unique<Token>(pttchild2->getToken())
        );
    }
    return NilaiContext(
        std::make_unique<Token>(pttchild0->getToken()), 
        nullptr, 
        nullptr, 
        nullptr
    );
}