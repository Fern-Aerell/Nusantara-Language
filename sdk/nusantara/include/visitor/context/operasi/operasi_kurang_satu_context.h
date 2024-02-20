#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangSatuContext: public Context {
  public:
    explicit OperasiKurangSatuContext(
        const bool& isPre, const bool& isPost,
        std::unique_ptr<Context> operasiTambahSatuContext,
        nstd::bisa_kosong<Token> satuOperator
    );
    static OperasiKurangSatuContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const bool& getIsPost() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiTambahSatuContext(
    ) const;
    [[nodiscard]] const nstd::bisa_kosong<Token>& getSatuOperator() const;

  private:
    bool isPre;
    bool isPost;
    std::unique_ptr<Context> operasiTambahSatuContext;
    nstd::bisa_kosong<Token> satuOperator;
};
