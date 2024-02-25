#pragma once

#include <memory>
#include <optional>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiNotBitContext: public Context {
  public:
    explicit OperasiNotBitContext(
        const bool& isPre, std::unique_ptr<Context> operasiKurangSatuContext,
        std::optional<Token> satuOperator
    );
    static OperasiNotBitContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiKurangSatuContext(
    ) const;
    [[nodiscard]] const std::optional<Token>& getSatuOperator() const;

  private:
    bool isPre;
    std::unique_ptr<Context> operasiKurangSatuContext;
    std::optional<Token> satuOperator;
};
