#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiNotBitContext: public Context {
  public:
    explicit OperasiNotBitContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSatuContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiNotBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiKurangSatuContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSatuContext;
    nstd::daftar<Token> kumpulanOperator;
};
