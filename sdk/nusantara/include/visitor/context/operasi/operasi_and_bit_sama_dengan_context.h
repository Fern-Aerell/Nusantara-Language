#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAndBitSamaDenganContext: public Context {
  public:
    explicit OperasiAndBitSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiKurangSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiAndBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiKurangSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiKurangSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
