#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihBesarContext: public Context {
  public:
    explicit OperasiLebihBesarContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiLebihKecilSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiLebihBesarContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihKecilSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiLebihKecilSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
