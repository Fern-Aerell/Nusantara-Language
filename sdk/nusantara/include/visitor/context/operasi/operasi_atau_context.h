#pragma once

#include <memory>
#include <vector>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiAtauContext: public Context {
  public:
    explicit OperasiAtauContext(
        std::vector<std::unique_ptr<Context>> kumpulanOperasiDanContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiAtauContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiDanContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiDanContext;
    std::vector<Token> kumpulanOperator;
};
