#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/nilai_context.h>
#include <nusantara/visitor/context/operator_perkalian_context.h>

class OperasiPerkalianContext {
  public:
    explicit OperasiPerkalianContext(
      std::unique_ptr<std::vector<OperatorPerkalianContext>> kumpulanOperatorPerkalianContext,
      std::unique_ptr<std::vector<NilaiContext>> kumpulanNilaiContext
    );
    [[nodiscard]] std::vector<OperatorPerkalianContext>* getKumpulanOperatorPerkalianContext() const;
    [[nodiscard]] std::vector<NilaiContext>* getKumpulanNilaiContext() const;
    static OperasiPerkalianContext generateOperasiPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperatorPerkalianContext>> kumpulanOperatorPerkalianContext;
    std::unique_ptr<std::vector<NilaiContext>> kumpulanNilaiContext;
};