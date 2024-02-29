#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "lexer/token.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class VariableContext: public Context {
  public:
    VariableContext(
        Token tipe, Token nama, std::optional<Token> samaDengan,
        std::optional<std::unique_ptr<Context>> ekspresiContext
    );
    static VariableContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const Token& getTipe() const;
    [[nodiscard]] const Token& getNama() const;
    [[nodiscard]] const std::optional<Token>& getSamaDengan() const;
    [[nodiscard]] const std::optional<std::unique_ptr<Context>>&
    getEkspresiContext() const;

  private:
    Token tipe;
    Token nama;
    std::optional<Token> samaDengan;
    std::optional<std::unique_ptr<Context>> ekspresiContext;
};
