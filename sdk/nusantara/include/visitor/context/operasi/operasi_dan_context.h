#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiDanContext: public Context {
  public:
    explicit OperasiDanContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiDanContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiOrBitContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitContext;
    nstd::daftar<Token> kumpulanOperator;
};
