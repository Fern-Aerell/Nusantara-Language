#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihBesarSamaDenganContext: public Context {
  public:
    explicit OperasiLebihBesarSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiLebihBesarSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihBesarContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext;
    nstd::daftar<Token> kumpulanOperator;
};
