#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSisaPembagianContext: public Context {
  public:
    explicit OperasiSisaPembagianContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiPembagianContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiSisaPembagianContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiPembagianContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiPembagianContext;
    std::vector<Token> kumpulanOperator;
};
