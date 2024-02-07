#include <nusantara/visitor/context/nusantara_context.h>

#include <nusantara/visitor/context/operasi_penugasan_context.h>

NusantaraContext::NusantaraContext(
      nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperasiPenugasanContext
):
kumpulanOperasiPenugasanContext(std::move(kumpulanOperasiPenugasanContext))
{}

NusantaraContext NusantaraContext::generate(const std::vector<std::unique_ptr<ParserTree>>& children) {
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperasiPenugasanContext = nstd::daftar<Context>();
    for(const std::unique_ptr<ParserTree>& child : children) {
        auto* ptchild = dynamic_cast<ParserRuleTree*>(child.get());
        const ParserRule rule = ptchild->getRule();
        if(rule == ParserRule::operasi_penugasan) {
            kumpulanOperasiPenugasanContext.value().push_back(OperasiPenugasanContext::generate(ptchild->getChildren()));
        }
    }
    return NusantaraContext(std::move(kumpulanOperasiPenugasanContext));
}

nstd::bisa_kosong<nstd::daftar<Context>> NusantaraContext::getKumpulanOperasiPenugasanContext() const {
    return this->kumpulanOperasiPenugasanContext;
}