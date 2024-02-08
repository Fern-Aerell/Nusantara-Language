#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class OperasiPerbandinganContext: public Context {
  public:
    OperasiPerbandinganContext(
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperasiPrePostContext,
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperatorPerbandinganContext
    );
    static OperasiPerbandinganContext generate(const std::vector<std::unique_ptr<ParserTree>>& children);
    [[nodiscard]] nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>>& getKumpulanOperasiPrePostContext() const;
    [[nodiscard]] nstd::konst<nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>>& getKumpulanOperatorPerbandinganContext() const;
  private:
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperasiPrePostContext;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>> kumpulanOperatorPerbandinganContext;
};