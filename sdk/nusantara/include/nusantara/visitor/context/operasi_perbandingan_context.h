#pragma once

#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperasiPerbandinganContext: public Context {
  public:
    OperasiPerbandinganContext(
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperasiPrePostContext,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperatorPerbandinganContext
    );
    static OperasiPerbandinganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::bisa_kosong<
        nstd::daftar<std::unique_ptr<Context>>>&
    getKumpulanOperasiPrePostContext() const;
    [[nodiscard]] const nstd::bisa_kosong<
        nstd::daftar<std::unique_ptr<Context>>>&
    getKumpulanOperatorPerbandinganContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPrePostContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPerbandinganContext;
};
