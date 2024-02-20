#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTambahSamaDenganContext: public Context {
  public:
    explicit OperasiTambahSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiSisaBagiSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiTambahSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiSisaBagiSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiSisaBagiSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
