#pragma once

#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperasiPerkalianContext: public Context {
  public:
    OperasiPerkalianContext(
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanNilaiContext,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanOperatorPerkalianContext
    );
    static OperasiPerkalianContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanNilaiContext() const;
    [[nodiscard]] nstd::konst<
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
    getKumpulanOperatorPerkalianContext() const;

  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanNilaiContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanOperatorPerkalianContext;
};
