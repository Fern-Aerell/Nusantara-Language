#include "nusantara/core/core.h"
#include "nusantara/visitor/context/context.h"
#include <memory>
#include <nusantara/visitor/context/nusantara_context.h>

#include <nusantara/visitor/context/operasi_penugasan_context.h>

NusantaraContext::NusantaraContext(
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperasiPenugasanContext
):
kumpulanOperasiPenugasanContext(std::move(kumpulanOperasiPenugasanContext))
{}

NusantaraContext NusantaraContext::generate(const std::vector<std::unique_ptr<ParserTree>>& children) {
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperasiPenugasanContext;
    for(const std::unique_ptr<ParserTree>& child : children) {
        auto* ptchild = dynamic_cast<ParserRuleTree*>(child.get());
        const ParserRule rule = ptchild->getRule();
        if(rule == ParserRule::operasi_penugasan) {
            if(nstd::isKosong(kumpulanOperasiPenugasanContext)) {
                kumpulanOperasiPenugasanContext = nstd::daftar<std::unique_ptr<Context>>();
            }
            std::unique_ptr<Context> context = std::make_unique<OperasiPenugasanContext>(OperasiPenugasanContext::generate(ptchild->getChildren()));
            kumpulanOperasiPenugasanContext.value().push_back(std::move(context));
        }
    }
    return NusantaraContext(std::move(kumpulanOperasiPenugasanContext));
}

nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>>& NusantaraContext::getKumpulanOperasiPenugasanContext() const {
    return this->kumpulanOperasiPenugasanContext;
}