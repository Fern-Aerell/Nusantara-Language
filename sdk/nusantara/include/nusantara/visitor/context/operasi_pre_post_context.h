#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operator_pre_post_context.h>
#include <nusantara/visitor/context/operasi_penjumlahan_context.h>

class OperasiPrePostContext {
  public:
    explicit OperasiPrePostContext(
      std::unique_ptr<OperatorPrePostContext> operatorPrePostContext,
      std::unique_ptr<OperasiPenjumlahanContext> operasiPenjumlahanContext,
      const bool& isPre
    );
    [[nodiscard]] OperatorPrePostContext* getOperatorPrePostContext() const;
    [[nodiscard]] OperasiPenjumlahanContext* getOperasiPenjumlahanContext() const;
    [[nodiscard]] bool getIsPre() const;
    static OperasiPrePostContext generateOperasiPrePostContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    bool isPre;
    std::unique_ptr<OperatorPrePostContext> operatorPrePostContext;
    std::unique_ptr<OperasiPenjumlahanContext> operasiPenjumlahanContext;
};