#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"
#include "nstd/kosong.h"

class OperasiNotBitContext: public Context {
  public:
    explicit OperasiNotBitContext(
      const bool& isPre,
    	std::unique_ptr<Context> operasiKurangSatuContext,
    	nstd::bisa_kosong<Token> satuOperator
		);
    static OperasiNotBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiKurangSatuContext() const;
    [[nodiscard]] const nstd::bisa_kosong<Token>& getSatuOperator() const;

  private:
    bool isPre;
    std::unique_ptr<Context> operasiKurangSatuContext;
    nstd::bisa_kosong<Token> satuOperator;
};
