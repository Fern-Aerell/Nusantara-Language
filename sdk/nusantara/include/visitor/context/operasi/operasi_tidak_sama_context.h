#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTidakSamaContext: public Context {
  public:
    explicit OperasiTidakSamaContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSamaContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiTidakSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiSamaContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSamaContext;
    nstd::daftar<Token> kumpulanOperator;
};
