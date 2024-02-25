#pragma once

#include <memory>
#include <vector>

#include "lexer/token.h"

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAndBitContext: public Context {
  public:
    explicit OperasiAndBitContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiAndBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiTidakSamaContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakSamaContext;
    std::vector<Token> kumpulanOperator;
};
