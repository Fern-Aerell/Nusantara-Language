#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiBagiSamaDenganContext: public Context {
  public:
    explicit OperasiBagiSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiKaliSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiKaliSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKaliSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
