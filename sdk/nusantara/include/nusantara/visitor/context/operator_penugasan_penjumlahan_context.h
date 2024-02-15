#pragma once

#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperatorPenugasanPenjumlahanContext: public Context {
  public:
    explicit OperatorPenugasanPenjumlahanContext(
        nstd::bisa_kosong<Token> simbolOp
    );
    static OperatorPenugasanPenjumlahanContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::bisa_kosong<Token> getSimbolOp() const;

  private:
    nstd::bisa_kosong<Token> simbolOp;
};
