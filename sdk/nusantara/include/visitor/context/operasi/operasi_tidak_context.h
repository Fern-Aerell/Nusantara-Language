#pragma once

#include <memory>

#include "lexer/token.h"
#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTidakContext: public Context {
  public:
    explicit OperasiTidakContext(
        const bool& isPre, std::unique_ptr<Context> operasiNotBitContext,
        nstd::bisa_kosong<Token> satuOperator
    );
    static OperasiTidakContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiNotBitContext(
    ) const;
    [[nodiscard]] const nstd::bisa_kosong<Token>& getSatuOperator() const;

  private:
    bool isPre;
    std::unique_ptr<Context> operasiNotBitContext;
    nstd::bisa_kosong<Token> satuOperator;
};
