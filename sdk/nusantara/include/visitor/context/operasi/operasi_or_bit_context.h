#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiOrBitContext: public Context {
  public:
    explicit OperasiOrBitContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiOrBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiXorBitContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitContext;
    nstd::daftar<Token> kumpulanOperator;
};
