#pragma once

#include <nusantara/core/core.h>
#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperatorPenjumlahanContext: public Context {
  public:
    explicit OperatorPenjumlahanContext(nstd::bisa_kosong<Token> simbolOp);
    static OperatorPenjumlahanContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::bisa_kosong<Token> getSimbolOp() const;

  private:
    nstd::bisa_kosong<Token> simbolOp;
};
