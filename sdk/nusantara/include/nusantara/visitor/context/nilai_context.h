#pragma once

#include "nusantara/visitor/context/operasi_penugasan_context.h"
#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>

class NilaiContext {
  public:
    explicit NilaiContext(
      std::unique_ptr<Token> nilai,
      std::unique_ptr<Token> kurungBuka,
      std::unique_ptr<OperasiPenugasanContext> operasiPenugasanContext,
      std::unique_ptr<Token> kurungTutup
    );
    [[nodiscard]] Token* getNilai() const;
    [[nodiscard]] Token* getKurungBuka() const;
    [[nodiscard]] OperasiPenugasanContext* getOperasiPenugasan() const;
    [[nodiscard]] Token* getKurungTutup() const;
    static NilaiContext generateNilaiContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<Token> nilai;
    std::unique_ptr<Token> kurungBuka;
    std::unique_ptr<OperasiPenugasanContext> operasiPenugasanContext;
    std::unique_ptr<Token> kurungTutup;
};