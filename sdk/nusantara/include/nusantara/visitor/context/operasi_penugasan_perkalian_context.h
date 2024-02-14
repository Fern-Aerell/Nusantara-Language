#pragma once


#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperasiPenugasanPerkalianContext: public Context {
  public:
    OperasiPenugasanPerkalianContext(
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperasiLogikaContext,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperatorPenugasanPerkalianContext
    );
    static OperasiPenugasanPerkalianContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] const
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>&
    getKumpulanOperasiLogikaContext() const;
    [[nodiscard]] const
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>&
    getKumpulanOperatorPenugasanPerkalianContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiLogikaContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenugasanPerkalianContext;
};
