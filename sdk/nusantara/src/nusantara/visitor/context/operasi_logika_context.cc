#include <nusantara/visitor/context/operasi_logika_context.h>

OperasiLogikaContext::OperasiLogikaContext(
    std::unique_ptr<std::vector<OperatorLogikaContext>> kumpulanOperatorLogikaContext,
    std::unique_ptr<std::vector<OperasiPerbandinganContext>> kumpulanOperasiPerbandinganContext
): 
kumpulanOperatorLogikaContext(std::move(kumpulanOperatorLogikaContext)),
kumpulanOperasiPerbandinganContext(std::move(kumpulanOperasiPerbandinganContext))
{}

std::vector<OperatorLogikaContext>* OperasiLogikaContext::getKumpulanOperatorLogikaContext() const {return this->kumpulanOperatorLogikaContext.get();}

std::vector<OperasiPerbandinganContext>* OperasiLogikaContext::getKumpulanOperasiPerbandinganContext() const {return this->kumpulanOperasiPerbandinganContext.get();}

OperasiLogikaContext OperasiLogikaContext::generateOperasiLogikaContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorLogikaContext>> kumpulanOperatorLogikaContext;
    std::unique_ptr<std::vector<OperasiPerbandinganContext>> kumpulanOperasiPerbandinganContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_logika) {
            kumpulanOperatorLogikaContext->push_back(OperatorLogikaContext::generateOperatorLogikaContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_perbandingan) {
            kumpulanOperasiPerbandinganContext->push_back(OperasiPerbandinganContext::generateOperasiPerbandinganContext(pchild->getChildren()));
        }
        }
    }
    return OperasiLogikaContext(
        std::move(kumpulanOperatorLogikaContext),
        std::move(kumpulanOperasiPerbandinganContext)
    );
}