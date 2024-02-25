#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKaliSamaDenganContext: public Context {
  public:
    explicit OperasiKaliSamaDenganContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiKaliSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
