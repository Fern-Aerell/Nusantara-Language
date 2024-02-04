#include <nusantara/visitor/context/operasi_pre_post_context.h>

OperasiPrePostContext::OperasiPrePostContext(
    std::unique_ptr<OperatorPrePostContext> operatorPrePostContext,
    std::unique_ptr<OperasiPenjumlahanContext> operasiPenjumlahanContext,
    const bool& isPre
): 
operatorPrePostContext(std::move(operatorPrePostContext)),
operasiPenjumlahanContext(std::move(operasiPenjumlahanContext)),
isPre(isPre)
{}

OperatorPrePostContext* OperasiPrePostContext::getOperatorPrePostContext() const {return this->operatorPrePostContext.get();}

OperasiPenjumlahanContext* OperasiPrePostContext::getOperasiPenjumlahanContext() const {return this->operasiPenjumlahanContext.get();}

bool OperasiPrePostContext::getIsPre() const {return this->isPre;}

OperasiPrePostContext OperasiPrePostContext::generateOperasiPrePostContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<OperatorPrePostContext> operatorPrePostContext;
    std::unique_ptr<OperasiPenjumlahanContext> operasiPenjumlahanContext;
    bool isPre = false;
    int index = 0;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_pre_post) {
            if(index == 0) {isPre = true;}
            operatorPrePostContext = std::make_unique<OperatorPrePostContext>(OperatorPrePostContext::generateOperatorPrePostContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_penjumlahan) {
            operasiPenjumlahanContext = std::make_unique<OperasiPenjumlahanContext>(OperasiPenjumlahanContext::generateOperasiPenjumlahanContext(pchild->getChildren()));
        }
        }
        index++;
    }
    return OperasiPrePostContext(
        std::move(operatorPrePostContext),
        std::move(operasiPenjumlahanContext),
        isPre
    );
}