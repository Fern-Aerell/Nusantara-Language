#include <nusantara/visitor/context/operasi_penugasan_context.h>

OperasiPenugasanContext::OperasiPenugasanContext(
    std::unique_ptr<std::vector<OperatorPenugasanContext>> kumpulanOperatorPenugasanContext,
    std::unique_ptr<std::vector<OperasiPenugasanPenjumlahanContext>> kumpulanOperasiPenugasanPenjumlahanContext
): 
kumpulanOperatorPenugasanContext(std::move(kumpulanOperatorPenugasanContext)),
kumpulanOperasiPenugasanPenjumlahanContext(std::move(kumpulanOperasiPenugasanPenjumlahanContext))
{}

std::vector<OperatorPenugasanContext>* OperasiPenugasanContext::getKumpulanOperatorPenugasanContext() const {return this->kumpulanOperatorPenugasanContext.get();}

std::vector<OperasiPenugasanPenjumlahanContext>* OperasiPenugasanContext::getKumpulanOperasiPenugasanPenjumlahanContext() const {return this->kumpulanOperasiPenugasanPenjumlahanContext.get();}

OperasiPenugasanContext OperasiPenugasanContext::generateOperasiPenugasanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPenugasanContext>> kumpulanOperatorPenugasanContext;
    std::unique_ptr<std::vector<OperasiPenugasanPenjumlahanContext>> kumpulanOperasiPenugasanPenjumlahanContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_penugasan) {
            kumpulanOperatorPenugasanContext->push_back(OperatorPenugasanContext::generateOperatorPenugasanContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_penugasan_penjumlahan) {
            kumpulanOperasiPenugasanPenjumlahanContext->push_back(OperasiPenugasanPenjumlahanContext::generateOperasiPenugasanPenjumlahanContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPenugasanContext(
        std::move(kumpulanOperatorPenugasanContext),
        std::move(kumpulanOperasiPenugasanPenjumlahanContext)
    );
}