#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiOrBitContext: public Context {
  public:
    explicit OperasiOrBitContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiXorBitContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiOrBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiXorBitContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiXorBitContext;
    std::vector<Token> kumpulanOperator;
};
