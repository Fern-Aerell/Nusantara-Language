#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiSamaContext: public Context {
  public:
    explicit OperasiSamaContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiLebihBesarSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiSamaContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihBesarSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiLebihBesarSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
