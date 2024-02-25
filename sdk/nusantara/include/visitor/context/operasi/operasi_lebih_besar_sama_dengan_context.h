#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihBesarSamaDenganContext: public Context {
  public:
    explicit OperasiLebihBesarSamaDenganContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiLebihBesarSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiLebihBesarContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiLebihBesarContext;
    std::vector<Token> kumpulanOperator;
};
