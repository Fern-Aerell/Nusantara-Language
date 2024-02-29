#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKiriBitSamaDenganContext: public Context {
  public:
    explicit OperasiGeserKiriBitSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiXorBitSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiGeserKiriBitSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiXorBitSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiXorBitSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
