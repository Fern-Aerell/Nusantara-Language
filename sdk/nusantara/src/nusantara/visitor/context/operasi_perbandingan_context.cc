#include <nusantara/visitor/context/operasi_perbandingan_context.h>

OperasiPerbandinganContext::OperasiPerbandinganContext(
    std::unique_ptr<std::vector<OperatorPerbandinganContext>> kumpulanOperatorPerbandinganContext,
    std::unique_ptr<std::vector<OperasiPrePostContext>> kumpulanOperasiPrePostContext
): 
kumpulanOperatorPerbandinganContext(std::move(kumpulanOperatorPerbandinganContext)),
kumpulanOperasiPrePostContext(std::move(kumpulanOperasiPrePostContext))
{}

std::vector<OperatorPerbandinganContext>* OperasiPerbandinganContext::getKumpulanOperatorPerbandinganContext() const {return this->kumpulanOperatorPerbandinganContext.get();}

std::vector<OperasiPrePostContext>* OperasiPerbandinganContext::getKumpulanOperasiPrePostContext() const {return this->kumpulanOperasiPrePostContext.get();}

OperasiPerbandinganContext OperasiPerbandinganContext::generateOperasiPerbandinganContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPerbandinganContext>> kumpulanOperatorPerbandinganContext;
    std::unique_ptr<std::vector<OperasiPrePostContext>> kumpulanOperasiPrePostContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_perbandingan) {
            kumpulanOperatorPerbandinganContext->push_back(OperatorPerbandinganContext::generateOperatorPerbandinganContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_pre_post) {
            kumpulanOperasiPrePostContext->push_back(OperasiPrePostContext::generateOperasiPrePostContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPerbandinganContext(
        std::move(kumpulanOperatorPerbandinganContext),
        std::move(kumpulanOperasiPrePostContext)
    );
}