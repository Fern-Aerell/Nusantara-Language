#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKananBitContext: public Context {
  public:
    explicit OperasiGeserKananBitContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiGeserKiriBitContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiGeserKananBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKiriBitContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitContext;
    nstd::daftar<Token> kumpulanOperator;
};
