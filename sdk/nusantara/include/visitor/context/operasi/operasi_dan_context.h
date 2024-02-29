#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiDanContext: public Context {
  public:
    explicit OperasiDanContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiOrBitContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiDanContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiOrBitContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiOrBitContext;
    std::vector<Token> kumpulanOperator;
};
