#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihKecilSamaDenganContext: public Context {
  public:
    explicit OperasiLebihKecilSamaDenganContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiLebihKecilSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihKecilContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiLebihKecilContext;
    std::vector<Token> kumpulanOperator;
};
