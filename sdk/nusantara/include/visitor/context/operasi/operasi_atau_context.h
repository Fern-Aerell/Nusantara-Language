#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAtauContext: public Context {
  public:
    explicit OperasiAtauContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiDanContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiAtauContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiDanContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiDanContext;
    nstd::daftar<Token> kumpulanOperator;
};
