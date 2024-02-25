#pragma once

#include <memory>
#include <optional>

#include "lexer/token.h"

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTidakContext: public Context {
  public:
    explicit OperasiTidakContext(
        const bool& isPre, std::unique_ptr<Context> operasiNotBitContext,
        std::optional<Token> satuOperator
    );
    static OperasiTidakContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiNotBitContext(
    ) const;
    [[nodiscard]] const std::optional<Token>& getSatuOperator() const;

  private:
    bool isPre;
    std::unique_ptr<Context> operasiNotBitContext;
    std::optional<Token> satuOperator;
};
