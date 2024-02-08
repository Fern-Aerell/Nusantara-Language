#pragma once

#include "nusantara/visitor/context/context.h"
#include <memory>
#include <nusantara/core/core.h>
#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

class OperatorPrePostContext: public Context {
  public:
    explicit OperatorPrePostContext(nstd::bisa_kosong<Token> simbolOp);
    static OperatorPrePostContext generate(const std::vector<std::unique_ptr<ParserTree>>& children);
    [[nodiscard]] nstd::bisa_kosong<Token> getSimbolOp() const;
  private:
    nstd::bisa_kosong<Token> simbolOp;
};