#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>

class OperatorPerkalianContext {
  public:
    explicit OperatorPerkalianContext(std::unique_ptr<Token> opsymbol);
    [[nodiscard]] Token* getOpSymbol() const;
    static OperatorPerkalianContext generateOperatorPerkalianContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<Token> opsymbol;
};