#pragma once

#include <memory>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiLebihKecilContext: public Context {
  public:
    explicit OperasiLebihKecilContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiGeserKananBitContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiLebihKecilContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiGeserKananBitContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanOperasiGeserKananBitContext;
    std::vector<Token> kumpulanOperator;
};
