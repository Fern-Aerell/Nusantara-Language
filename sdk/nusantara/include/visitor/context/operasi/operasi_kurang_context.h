#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangContext: public Context {
  public:
    explicit OperasiKurangContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiKurangContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiTambahContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahContext;
    nstd::daftar<Token> kumpulanOperator;
};
