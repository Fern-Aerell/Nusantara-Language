#pragma once

#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperasiPrePostContext: public Context {
  public:
    OperasiPrePostContext(
        nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenjumlahanContext,
        nstd::bisa_kosong<std::unique_ptr<Context>> operatorPrePostContext,
        const bool &isPre
    );
    static OperasiPrePostContext generate(
        const std::vector<std::unique_ptr<ParserTree>> &children
    );
    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>> &
    getOperasiPenjumlahanContext() const;
    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>> &
    getOperatorPrePostContext() const;
    [[nodiscard]] bool getIsPre() const;

  private:
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenjumlahanContext;
    nstd::bisa_kosong<std::unique_ptr<Context>> operatorPrePostContext;
    bool isPre;
};
