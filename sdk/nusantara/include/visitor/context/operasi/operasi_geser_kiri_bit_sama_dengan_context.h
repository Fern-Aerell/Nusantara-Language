#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKiriBitSamaDenganContext: public Context {
  public:
    explicit OperasiGeserKiriBitSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiXorBitSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiGeserKiriBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiXorBitSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiXorBitSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
