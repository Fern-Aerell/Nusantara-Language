#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiXorBitSamaDenganContext: public Context {
  public:
    explicit OperasiXorBitSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiOrBitSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiXorBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiOrBitSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiOrBitSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
