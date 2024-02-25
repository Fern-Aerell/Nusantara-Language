#pragma once

#include <memory>
#include <vector>
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiBagiSamaDenganContext: public Context {
  public:
    explicit OperasiBagiSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiKaliSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiBagiSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiKaliSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiKaliSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
