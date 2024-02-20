#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NilaiContext: public Context {
  public:
    NilaiContext(
        nstd::bisa_kosong<Token> nilai,
        nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext,
        nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext
    );

    static NilaiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );

    [[nodiscard]] const nstd::bisa_kosong<Token>& getNilai() const;

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getEkspresiContext() const;

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getNilaiKalimatContext() const;

  private:
    nstd::bisa_kosong<Token> nilai;
    nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext;
};
