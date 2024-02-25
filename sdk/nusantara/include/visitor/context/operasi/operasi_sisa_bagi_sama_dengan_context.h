#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSisaBagiSamaDenganContext: public Context {
  public:
    explicit OperasiSisaBagiSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiBagiSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiSisaBagiSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiBagiSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
