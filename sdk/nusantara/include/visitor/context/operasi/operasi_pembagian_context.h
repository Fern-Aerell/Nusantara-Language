#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiPembagianContext: public Context {
  public:
    explicit OperasiPembagianContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiPerkalianContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext;
    nstd::daftar<Token> kumpulanOperator;
};
