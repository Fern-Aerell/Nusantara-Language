#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTambahContext: public Context {
  public:
    explicit OperasiTambahContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiSisaPembagianContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiTambahContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiSisaPembagianContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiSisaPembagianContext;
    std::vector<Token> kumpulanOperator;
};
