#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKananBitSamaDenganContext: public Context {
  public:
    explicit OperasiGeserKananBitSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiGeserKiriBitSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiGeserKananBitSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKiriBitSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiGeserKiriBitSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
