#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiOrBitSamaDenganContext: public Context {
  public:
    explicit OperasiOrBitSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiAndBitSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiOrBitSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiAndBitSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiAndBitSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
