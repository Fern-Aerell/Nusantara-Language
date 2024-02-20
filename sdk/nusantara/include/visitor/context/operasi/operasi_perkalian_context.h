#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiPerkalianContext: public Context {
  public:
    explicit OperasiPerkalianContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTidakContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiPerkalianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiTidakContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTidakContext;
    nstd::daftar<Token> kumpulanOperator;
};
