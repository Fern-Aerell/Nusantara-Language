#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operasi_pre_post_context.h>
#include <nusantara/visitor/context/operator_perbandingan_context.h>

class OperasiPerbandinganContext {
  public:
    explicit OperasiPerbandinganContext(
      std::unique_ptr<std::vector<OperatorPerbandinganContext>> kumpulanOperatorPerbandinganContext,
      std::unique_ptr<std::vector<OperasiPrePostContext>> kumpulanOperasiPrePostContext
    );
    [[nodiscard]] std::vector<OperatorPerbandinganContext>* getKumpulanOperatorPerbandinganContext() const;
    [[nodiscard]] std::vector<OperasiPrePostContext>* getKumpulanOperasiPrePostContext() const;
    static OperasiPerbandinganContext generateOperasiPerbandinganContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPerbandinganContext>> kumpulanOperatorPerbandinganContext;
    std::unique_ptr<std::vector<OperasiPrePostContext>> kumpulanOperasiPrePostContext;
};