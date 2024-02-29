#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiPerkalianContext: public Context {
  public:
    explicit OperasiPerkalianContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiPerkalianContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiTidakContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTidakContext;
    std::vector<Token> kumpulanOperator;
};
