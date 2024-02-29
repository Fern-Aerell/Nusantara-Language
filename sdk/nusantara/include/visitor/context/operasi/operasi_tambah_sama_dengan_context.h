#pragma once

#include <memory>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTambahSamaDenganContext: public Context {
  public:
    explicit OperasiTambahSamaDenganContext(
        std::vector<std::unique_ptr<Context>>
            kumpulanOperasiSisaBagiSamaDenganContext,
        std::vector<Token> kumpulanOperator
    );
    static OperasiTambahSamaDenganContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanOperasiSisaBagiSamaDenganContext() const;
    [[nodiscard]] const std::vector<Token>& getKumpulanOperator() const;

  private:
    std::vector<std::unique_ptr<Context>>
        kumpulanOperasiSisaBagiSamaDenganContext;
    std::vector<Token> kumpulanOperator;
};
