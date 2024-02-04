#include <nusantara/visitor/context/operasi_penjumlahan_context.h>

OperasiPenjumlahanContext::OperasiPenjumlahanContext(
    std::unique_ptr<std::vector<OperatorPenjumlahanContext>> kumpulanOperatorPenjumlahanContext,
    std::unique_ptr<std::vector<OperasiPerkalianContext>> kumpulanOperasiPerkalianContext
): 
kumpulanOperatorPenjumlahanContext(std::move(kumpulanOperatorPenjumlahanContext)),
kumpulanOperasiPerkalianContext(std::move(kumpulanOperasiPerkalianContext))
{}

[[nodiscard]] std::vector<OperatorPenjumlahanContext>* OperasiPenjumlahanContext::getKumpulanOperatorPenjumlahanContext() const {return this->kumpulanOperatorPenjumlahanContext.get();}
[[nodiscard]] std::vector<OperasiPerkalianContext>* OperasiPenjumlahanContext::getKumpulanOperasiPerkalianContext() const {return this->kumpulanOperasiPerkalianContext.get();}

OperasiPenjumlahanContext OperasiPenjumlahanContext::generateOperasiPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperatorPenjumlahanContext>> kumpulanOperatorPenjumlahanContext;
    std::unique_ptr<std::vector<OperasiPerkalianContext>> kumpulanOperasiPerkalianContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operator_penjumlahan) {
            kumpulanOperatorPenjumlahanContext->push_back(OperatorPenjumlahanContext::generateOperatorPenjumlahanContext(pchild->getChildren()));
        }else if(pchild->getRule() == ParserRule::operasi_perkalian) {
            kumpulanOperasiPerkalianContext->push_back(OperasiPerkalianContext::generateOperasiPerkalianContext(pchild->getChildren()));
        }
        }
    }
    return OperasiPenjumlahanContext(
        std::move(kumpulanOperatorPenjumlahanContext),
        std::move(kumpulanOperasiPerkalianContext)
    );
}