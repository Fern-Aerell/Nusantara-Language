#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKiriBitContext: public Context {
  public:
    explicit OperasiGeserKiriBitContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiKurangContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiGeserKiriBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiKurangContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiKurangContext;
    std::vector<Token> kumpulanOperator;
};
