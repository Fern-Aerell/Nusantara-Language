#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihKecilContext: public Context {
  public:
    explicit OperasiLebihKecilContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiGeserKananBitContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiLebihKecilContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKananBitContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiGeserKananBitContext;
    nstd::daftar<Token> kumpulanOperator;
};
