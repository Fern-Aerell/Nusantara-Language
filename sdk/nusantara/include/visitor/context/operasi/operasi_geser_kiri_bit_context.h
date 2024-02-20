#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKiriBitContext: public Context {
  public:
    explicit OperasiGeserKiriBitContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiGeserKiriBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiKurangContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangContext;
    nstd::daftar<Token> kumpulanOperator;
};
