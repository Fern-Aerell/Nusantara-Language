#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSamaDenganContext: public Context {
  public:
    explicit OperasiSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiKondisionalContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiKondisionalContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiKondisionalContext;
    std::vector<Token> kumpulanOperator;
};
