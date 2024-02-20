#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKaliSamaDenganContext: public Context {
  public:
    explicit OperasiKaliSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiKaliSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
