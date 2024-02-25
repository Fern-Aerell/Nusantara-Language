#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiGeserKananBitContext: public Context {
  public:
    explicit OperasiGeserKananBitContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiGeserKiriBitContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiGeserKananBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKiriBitContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitContext;
    std::vector<Token> kumpulanOperator;
};
