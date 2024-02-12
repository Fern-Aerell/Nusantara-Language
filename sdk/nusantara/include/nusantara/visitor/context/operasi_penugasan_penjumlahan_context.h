#pragma once

#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperasiPenugasanPenjumlahanContext: public Context {
  public:
    OperasiPenugasanPenjumlahanContext(
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperasiPenugasanPerkalianContext,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperatorPenugasanPenjumlahanContext
    );
    static OperasiPenugasanPenjumlahanContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanOperasiPenugasanPerkalianContext() const;
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanOperatorPenugasanPenjumlahanContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPenugasanPerkalianContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenugasanPenjumlahanContext;
};
