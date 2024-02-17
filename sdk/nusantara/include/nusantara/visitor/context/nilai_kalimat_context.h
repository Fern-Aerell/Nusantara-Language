#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/lexer/token.h"
#include "nusantara/parser/parser_tree.h"
#include "nusantara/visitor/context/context.h"

class NilaiKalimatContext: public Context {
  public:
    NilaiKalimatContext(
        nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperasiPenugasanContext
    );
    static NilaiKalimatContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::bisa_kosong<nstd::daftar<Token>>&
    getKumpulanToken() const;
    [[nodiscard]] const nstd::bisa_kosong<
        nstd::daftar<std::unique_ptr<Context>>>&
    getKumpulanOperasiPenugasanContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPenugasanContext;
};
