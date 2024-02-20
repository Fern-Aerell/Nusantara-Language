#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiXorBitContext: public Context {
  public:
    explicit OperasiXorBitContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiXorBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiAndBitContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitContext;
    nstd::daftar<Token> kumpulanOperator;
};
