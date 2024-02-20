#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihBesarContext: public Context {
  public:
    explicit OperasiLebihBesarContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiLebihKecilSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiLebihBesarContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihKecilSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiLebihKecilSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
