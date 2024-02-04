#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operator_penjumlahan_context.h>
#include <nusantara/visitor/context/operasi_perkalian_context.h>

class OperasiPenjumlahanContext {
  public:
    explicit OperasiPenjumlahanContext(
      std::unique_ptr<std::vector<OperatorPenjumlahanContext>> kumpulanOperatorPenjumlahanContext,
      std::unique_ptr<std::vector<OperasiPerkalianContext>> kumpulanOperasiPerkalianContext
    );
    [[nodiscard]] std::vector<OperatorPenjumlahanContext>* getKumpulanOperatorPenjumlahanContext() const;
    [[nodiscard]] std::vector<OperasiPerkalianContext>* getKumpulanOperasiPerkalianContext() const;
    static OperasiPenjumlahanContext generateOperasiPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPenjumlahanContext>> kumpulanOperatorPenjumlahanContext;
    std::unique_ptr<std::vector<OperasiPerkalianContext>> kumpulanOperasiPerkalianContext;
};