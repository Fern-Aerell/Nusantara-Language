#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSamaContext: public Context {
  public:
    explicit OperasiSamaContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiLebihBesarSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihBesarSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiLebihBesarSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
