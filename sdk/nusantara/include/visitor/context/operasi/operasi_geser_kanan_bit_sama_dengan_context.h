#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKananBitSamaDenganContext: public Context {
  public:
    explicit OperasiGeserKananBitSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiGeserKiriBitSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiGeserKananBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKiriBitSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiGeserKiriBitSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
