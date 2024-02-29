#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiPembagianContext: public Context {
  public:
    explicit OperasiPembagianContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiPembagianContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiPerkalianContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiPerkalianContext;
    std::vector<Token> kumpulanOperator;
};
