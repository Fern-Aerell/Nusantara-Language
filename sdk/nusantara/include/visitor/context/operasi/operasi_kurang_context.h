#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangContext: public Context {
  public:
    explicit OperasiKurangContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiTambahContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiKurangContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiTambahContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiTambahContext;
    std::vector<Token> kumpulanOperator;
};
