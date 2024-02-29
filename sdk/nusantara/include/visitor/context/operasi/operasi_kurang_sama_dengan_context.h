#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangSamaDenganContext: public Context {
  public:
    explicit OperasiKurangSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiTambahSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiKurangSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiTambahSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiTambahSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
