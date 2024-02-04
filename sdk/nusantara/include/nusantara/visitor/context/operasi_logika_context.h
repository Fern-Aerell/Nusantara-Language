#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operator_logika_context.h>
#include <nusantara/visitor/context/operasi_perbandingan_context.h>

class OperasiLogikaContext {
  public:
    explicit OperasiLogikaContext(
      std::unique_ptr<std::vector<OperatorLogikaContext>> kumpulanOperatorLogikaContext,
      std::unique_ptr<std::vector<OperasiPerbandinganContext>> kumpulanOperasiPerbandinganContext
    );
    [[nodiscard]] std::vector<OperatorLogikaContext>* getKumpulanOperatorLogikaContext() const;
    [[nodiscard]] std::vector<OperasiPerbandinganContext>* getKumpulanOperasiPerbandinganContext() const;
    static OperasiLogikaContext generateOperasiLogikaContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorLogikaContext>> kumpulanOperatorLogikaContext;
    std::unique_ptr<std::vector<OperasiPerbandinganContext>> kumpulanOperasiPerbandinganContext;
};