#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTambahContext: public Context {
  public:
    explicit OperasiTambahContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiSisaPembagianContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiTambahContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiSisaPembagianContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaPembagianContext;
    nstd::daftar<Token> kumpulanOperator;
};
