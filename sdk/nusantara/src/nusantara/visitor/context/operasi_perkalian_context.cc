#include <nusantara/visitor/context/operasi_perkalian_context.h>

OperasiPerkalianContext::OperasiPerkalianContext(
    std::unique_ptr<std::vector<OperatorPerkalianContext>> kumpulanOperatorPerkalianContext,
    std::unique_ptr<std::vector<NilaiContext>> kumpulanNilaiContext
): 
kumpulanOperatorPerkalianContext(std::move(kumpulanOperatorPerkalianContext)),
kumpulanNilaiContext(std::move(kumpulanNilaiContext))
{}

std::vector<OperatorPerkalianContext>* OperasiPerkalianContext::getKumpulanOperatorPerkalianContext() const {return this->kumpulanOperatorPerkalianContext.get();}

std::vector<NilaiContext>* OperasiPerkalianContext::getKumpulanNilaiContext() const {return this->kumpulanNilaiContext.get();}

OperasiPerkalianContext OperasiPerkalianContext::generateOperasiPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPerkalianContext>> kumpulanOperatorPerkalianContext;
    std::unique_ptr<std::vector<NilaiContext>> kumpulanNilaiContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_perkalian) {
            kumpulanOperatorPerkalianContext->push_back(OperatorPerkalianContext::generateOperatorPerkalianContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::nilai) {
            kumpulanNilaiContext->push_back(NilaiContext::generateNilaiContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPerkalianContext(
        std::move(kumpulanOperatorPerkalianContext),
        std::move(kumpulanNilaiContext)
    );
}