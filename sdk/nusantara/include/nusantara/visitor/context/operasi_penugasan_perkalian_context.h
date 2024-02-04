#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operasi_logika_context.h>
#include <nusantara/visitor/context/operator_penugasan_perkalian_context.h>

class OperasiPenugasanPerkalianContext {
  public:
    explicit OperasiPenugasanPerkalianContext(
      std::unique_ptr<std::vector<OperatorPenugasanPerkalianContext>> kumpulanOperatorPenugasanPerkalianContext,
      std::unique_ptr<std::vector<OperasiLogikaContext>> kumpulanOperasiLogikaContext
    );
    [[nodiscard]] std::vector<OperatorPenugasanPerkalianContext>* getKumpulanOperatorPenugasanPerkalianContext() const;
    [[nodiscard]] std::vector<OperasiLogikaContext>* getKumpulanOperasiLogikaContext() const;
    static OperasiPenugasanPerkalianContext generateOperasiPenugasanPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPenugasanPerkalianContext>> kumpulanOperatorPenugasanPerkalianContext;
    std::unique_ptr<std::vector<OperasiLogikaContext>> kumpulanOperasiLogikaContext;
};