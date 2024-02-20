#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSisaBagiSamaDenganContext: public Context {
  public:
    explicit OperasiSisaBagiSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiBagiSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiSisaBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiBagiSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
