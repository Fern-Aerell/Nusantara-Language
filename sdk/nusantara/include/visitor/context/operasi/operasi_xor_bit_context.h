#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiXorBitContext: public Context {
  public:
    explicit OperasiXorBitContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiAndBitContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiXorBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiAndBitContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiAndBitContext;
    std::vector<Token> kumpulanOperator;
};
