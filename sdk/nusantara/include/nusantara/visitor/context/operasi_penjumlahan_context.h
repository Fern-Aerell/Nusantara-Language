#pragma once

#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperasiPenjumlahanContext: public Context {
  public:
    OperasiPenjumlahanContext(
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperasiPerkalianContext,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperatorPenjumlahanContext
    );
    static OperasiPenjumlahanContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanOperasiPerkalianContext() const;
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanOperatorPenjumlahanContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperasiPerkalianContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPenjumlahanContext;
};
