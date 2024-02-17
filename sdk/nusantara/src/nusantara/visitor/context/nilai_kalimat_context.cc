#include "nusantara/visitor/context/nilai_kalimat_context.h"

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/lexer/token.h"
#include "nusantara/parser/parser_tree.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"

NilaiKalimatContext::NilaiKalimatContext(
    nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPenugasanContext
):
    kumpulanToken(std::move(kumpulanToken)),
    kumpulanOperasiPenugasanContext(std::move(kumpulanOperasiPenugasanContext)
    ) {}

NilaiKalimatContext NilaiKalimatContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPenugasanContext;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(nstd::kosong(kumpulanOperasiPenugasanContext)) {
        kumpulanOperasiPenugasanContext =
            nstd::daftar<std::unique_ptr<Context>>();
      }
      std::unique_ptr<Context> context =
          std::make_unique<OperasiPenugasanContext>(
              OperasiPenugasanContext::generate(ptchildRule->getChildren())
          );
      kumpulanOperasiPenugasanContext->push_back(std::move(context));
    } else if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(child.get())) {
      if(nstd::kosong(kumpulanToken)) { kumpulanToken = nstd::daftar<Token>(); }
      kumpulanToken->push_back(ptchildToken->getToken());
    }
  }
  return {std::move(kumpulanToken), std::move(kumpulanOperasiPenugasanContext)};
}

const nstd::bisa_kosong<nstd::daftar<Token>>&
NilaiKalimatContext::getKumpulanToken() const {
  return this->kumpulanToken;
}

const nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>&
NilaiKalimatContext::getKumpulanOperasiPenugasanContext() const {
  return this->kumpulanOperasiPenugasanContext;
}
