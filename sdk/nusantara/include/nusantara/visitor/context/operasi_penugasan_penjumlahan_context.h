#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operasi_penugasan_perkalian_context.h>
#include <nusantara/visitor/context/operator_penugasan_penjumlahan_context.h>

class OperasiPenugasanPenjumlahanContext {
  public:
    explicit OperasiPenugasanPenjumlahanContext(
      std::unique_ptr<std::vector<OperatorPenugasanPenjumlahanContext>> kumpulanOperatorPenugasanPenjumlahanContext,
      std::unique_ptr<std::vector<OperasiPenugasanPerkalianContext>> kumpulanOperasiPenugasanPerkalianContext
    );
    [[nodiscard]] std::vector<OperatorPenugasanPenjumlahanContext>* getKumpulanOperatorPenugasanPenjumlahanContext() const;
    [[nodiscard]] std::vector<OperasiPenugasanPerkalianContext>* getKumpulanOperasiPenugasanPerkalianContext() const;
    static OperasiPenugasanPenjumlahanContext generateOperasiPenugasanPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPenugasanPenjumlahanContext>> kumpulanOperatorPenugasanPenjumlahanContext;
    std::unique_ptr<std::vector<OperasiPenugasanPerkalianContext>> kumpulanOperasiPenugasanPerkalianContext;
};