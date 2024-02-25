#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTidakSamaContext: public Context {
  public:
    explicit OperasiTidakSamaContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiTidakSamaContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiSamaContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiSamaContext;
    std::vector<Token> kumpulanOperator;
};
