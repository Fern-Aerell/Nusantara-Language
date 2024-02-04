#include <nusantara/visitor/context/nusantara_context.h>

NusantaraContext::NusantaraContext(
    std::unique_ptr<std::vector<OperasiPenugasanContext>> kumpulanOperasiPenugasan
): 
kumpulanOperasiPenugasan(std::move(kumpulanOperasiPenugasan)) 
{}

std::vector<OperasiPenugasanContext>* NusantaraContext::getKumpulanOperasiPenugasan() const {return this->kumpulanOperasiPenugasan.get();}

NusantaraContext NusantaraContext::generateNusantaraContext(const std::vector<std::unique_ptr<ParserTree>>& children) {
    std::unique_ptr<std::vector<OperasiPenugasanContext>> kumpulanOperasiPenugasan;
    for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* pchild = dynamic_cast<ParserRuleTree*>(child.get())) {
        if(pchild->getRule() == ParserRule::operasi_penugasan) {
            kumpulanOperasiPenugasan->push_back(OperatorPenugasanContext::generateOperatorPenugasanContext(pchild->getChildren()));
        }
        }
    }
    return NusantaraContext(std::move(kumpulanOperasiPenugasan));
}