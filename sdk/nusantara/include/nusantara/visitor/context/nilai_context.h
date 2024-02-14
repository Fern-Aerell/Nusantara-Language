#pragma once

#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class NilaiContext: public Context {
  public:
    explicit NilaiContext(
        nstd::bisa_kosong<Token> nilai, nstd::bisa_kosong<Token> kurungBuka,
        nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenugasanContext,
        nstd::bisa_kosong<Token> kurungTutup
    );
    static NilaiContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::bisa_kosong<Token> getNilai() const;
    [[nodiscard]] nstd::bisa_kosong<Token> getKurungBuka() const;
    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>& getOperasiPenugasanContext() const;
    [[nodiscard]] nstd::bisa_kosong<Token> getKurungTutup() const;

  private:
    nstd::bisa_kosong<Token> nilai;
    nstd::bisa_kosong<Token> kurungBuka;
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenugasanContext;
    nstd::bisa_kosong<Token> kurungTutup;
};
