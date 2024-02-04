#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h>
#include <nusantara/visitor/context/operator_penugasan_context.h>

class OperasiPenugasanContext {
  public:
    explicit OperasiPenugasanContext(
      std::unique_ptr<std::vector<OperatorPenugasanContext>> kumpulanOperatorPenugasanContext,
      std::unique_ptr<std::vector<OperasiPenugasanPenjumlahanContext>> kumpulanOperasiPenugasanPenjumlahanContext
    );
    [[nodiscard]] std::vector<OperatorPenugasanContext>* getKumpulanOperatorPenugasanContext() const;
    [[nodiscard]] std::vector<OperasiPenugasanPenjumlahanContext>* getKumpulanOperasiPenugasanPenjumlahanContext() const;
    static OperasiPenugasanContext generateOperasiPenugasanContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPenugasanContext>> kumpulanOperatorPenugasanContext;
    std::unique_ptr<std::vector<OperasiPenugasanPenjumlahanContext>> kumpulanOperasiPenugasanPenjumlahanContext;
};