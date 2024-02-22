#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSamaDenganContext: public Context {
  public:
    explicit OperasiSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiKondisionalContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiKondisionalContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKondisionalContext;
    nstd::daftar<Token> kumpulanOperator;
};
