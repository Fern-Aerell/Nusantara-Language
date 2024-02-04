#include <nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h>

OperasiPenugasanPenjumlahanContext::OperasiPenugasanPenjumlahanContext(
    std::unique_ptr<std::vector<OperatorPenugasanPenjumlahanContext>> kumpulanOperatorPenugasanPenjumlahanContext,
    std::unique_ptr<std::vector<OperasiPenugasanPerkalianContext>> kumpulanOperasiPenugasanPerkalianContext
): 
kumpulanOperatorPenugasanPenjumlahanContext(std::move(kumpulanOperatorPenugasanPenjumlahanContext)),
kumpulanOperasiPenugasanPerkalianContext(std::move(kumpulanOperasiPenugasanPerkalianContext))
{}

std::vector<OperatorPenugasanPenjumlahanContext>* OperasiPenugasanPenjumlahanContext::getKumpulanOperatorPenugasanPenjumlahanContext() const {return this->kumpulanOperatorPenugasanPenjumlahanContext.get();}

std::vector<OperasiPenugasanPerkalianContext>* OperasiPenugasanPenjumlahanContext::getKumpulanOperasiPenugasanPerkalianContext() const {return this->kumpulanOperasiPenugasanPerkalianContext.get();}

OperasiPenugasanPenjumlahanContext OperasiPenugasanPenjumlahanContext::generateOperasiPenugasanPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPenugasanPenjumlahanContext>> kumpulanOperatorPenugasanPenjumlahanContext;
    std::unique_ptr<std::vector<OperasiPenugasanPerkalianContext>> kumpulanOperasiPenugasanPerkalianContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_penugasan_penjumlahan) {
            kumpulanOperatorPenugasanPenjumlahanContext->push_back(OperatorPenugasanPenjumlahanContext::generateOperatorPenugasanPenjumlahanContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_penugasan_perkalian) {
            kumpulanOperasiPenugasanPerkalianContext->push_back(OperasiPenugasanPerkalianContext::generateOperasiPenugasanPerkalianContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPenugasanPenjumlahanContext(
        std::move(kumpulanOperatorPenugasanPenjumlahanContext),
        std::move(kumpulanOperasiPenugasanPerkalianContext)
    );
}