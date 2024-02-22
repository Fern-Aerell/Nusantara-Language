#pragma once

#include <memory>

#include "lexer/token.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKondisionalContext: public Context {
  public:
    OperasiKondisionalContext(
        std::unique_ptr<Context> kondisiOperasiAtauContext,
        nstd::bisa_kosong<Token> tandaTanya,
        nstd::bisa_kosong<std::unique_ptr<Context>> nilaiBenarEkspresiContext,
        nstd::bisa_kosong<Token> titikDua,
        nstd::bisa_kosong<std::unique_ptr<Context>> nilaiSalahEkspresiContext
    );
    static OperasiKondisionalContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::unique_ptr<Context>& getKondisiOperasiAtauContext(
    ) const;
    [[nodiscard]] const nstd::bisa_kosong<Token>& getTandaTanya() const;
    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getNilaiBenarEkspresiContext() const;
    [[nodiscard]] const nstd::bisa_kosong<Token>& getTitikDua() const;
    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getNilaiSalahEkspresiContext() const;

  private:
    std::unique_ptr<Context> kondisiOperasiAtauContext;
    nstd::bisa_kosong<Token> tandaTanya;
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiBenarEkspresiContext;
    nstd::bisa_kosong<Token> titikDua;
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiSalahEkspresiContext;
};
