#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>

class OperatorPenugasanPenjumlahanContext {
  public:
    explicit OperatorPenugasanPenjumlahanContext(std::unique_ptr<Token> opsymbol);
    [[nodiscard]] Token* getOpSymbol() const;
    static OperatorPenugasanPenjumlahanContext generateOperatorPenugasanPenjumlahanContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<Token> opsymbol;
};