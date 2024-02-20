#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSisaPembagianContext: public Context {
  public:
    explicit OperasiSisaPembagianContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPembagianContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiSisaPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiPembagianContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPembagianContext;
    nstd::daftar<Token> kumpulanOperator;
};
