#include <nusantara/visitor/context/operasi_penugasan_perkalian_context.h>

OperasiPenugasanPerkalianContext::OperasiPenugasanPerkalianContext(
    std::unique_ptr<std::vector<OperatorPenugasanPerkalianContext>> kumpulanOperatorPenugasanPerkalianContext,
    std::unique_ptr<std::vector<OperasiLogikaContext>> kumpulanOperasiLogikaContext
): 
kumpulanOperatorPenugasanPerkalianContext(std::move(kumpulanOperatorPenugasanPerkalianContext)),
kumpulanOperasiLogikaContext(std::move(kumpulanOperasiLogikaContext))
{}

std::vector<OperatorPenugasanPerkalianContext>* OperasiPenugasanPerkalianContext::getKumpulanOperatorPenugasanPerkalianContext() const {return this->kumpulanOperatorPenugasanPerkalianContext.get();}

std::vector<OperasiLogikaContext>* OperasiPenugasanPerkalianContext::getKumpulanOperasiLogikaContext() const {return this->kumpulanOperasiLogikaContext.get();}

OperasiPenugasanPerkalianContext OperasiPenugasanPerkalianContext::generateOperasiPenugasanPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPenugasanPerkalianContext>> kumpulanOperatorPenugasanPerkalianContext;
    std::unique_ptr<std::vector<OperasiLogikaContext>> kumpulanOperasiLogikaContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_penugasan_perkalian) {
            kumpulanOperatorPenugasanPerkalianContext->push_back(generateOperatorPenugasanPerkalianContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_logika) {
            kumpulanOperasiLogikaContext->push_back(generateOperasiLogikaContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPenugasanPerkalianContext(
        std::move(kumpulanOperatorPenugasanPerkalianContext),
        std::move(kumpulanOperasiLogikaContext)
    );
}