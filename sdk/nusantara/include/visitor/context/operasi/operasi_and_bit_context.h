#pragma once

#include <memory>

#include "lexer/token.h"
#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAndBitContext: public Context {
  public:
    explicit OperasiAndBitContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiAndBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiTidakSamaContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext;
    nstd::daftar<Token> kumpulanOperator;
};
