#pragma once


#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperatorPenugasanContext: public Context {
  public:
    explicit OperatorPenugasanContext(nstd::bisa_kosong<Token> simbolOp);
    static OperatorPenugasanContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] nstd::bisa_kosong<Token> getSimbolOp() const;

  private:
    nstd::bisa_kosong<Token> simbolOp;
};
