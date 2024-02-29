#pragma once

#include <memory>
#include <vector>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAndBitSamaDenganContext: public Context {
  public:
    explicit OperasiAndBitSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiKurangSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiAndBitSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiKurangSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiKurangSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
