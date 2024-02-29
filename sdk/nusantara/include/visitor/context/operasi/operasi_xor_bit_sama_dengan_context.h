#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiXorBitSamaDenganContext: public Context {
  public:
    explicit OperasiXorBitSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiOrBitSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiXorBitSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiOrBitSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiOrBitSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
