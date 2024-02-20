#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiOrBitSamaDenganContext: public Context {
  public:
    explicit OperasiOrBitSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiAndBitSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiOrBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiAndBitSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiAndBitSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
