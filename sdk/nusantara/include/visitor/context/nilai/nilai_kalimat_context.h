#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NilaiKalimatContext: public Context {
  public:
    NilaiKalimatContext(
        nstd::daftar<Token> kumpulanToken,
        nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext
    );

    static NilaiKalimatContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );

    [[nodiscard]] const nstd::daftar<Token>& getKumpulanToken() const;

    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getkumpulanEkspresiContext() const;

  private:
    nstd::daftar<Token> kumpulanToken;
    nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext;
};
