#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihKecilSamaDenganContext: public Context {
  public:
    explicit OperasiLebihKecilSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiLebihKecilSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihKecilContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext;
    nstd::daftar<Token> kumpulanOperator;
};
