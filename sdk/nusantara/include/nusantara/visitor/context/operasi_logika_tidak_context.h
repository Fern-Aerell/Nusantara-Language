#pragma once


#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/context.h"

class OperasiLogikaTidakContext: public Context {
  public:
    OperasiLogikaTidakContext(
        nstd::bisa_kosong<std::unique_ptr<Context>> operatorLogikaTidakContext,
        nstd::bisa_kosong<std::unique_ptr<Context>> operasiPerbandinganContext
    );
    static OperasiLogikaTidakContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] nstd::bisa_kosong<std::unique_ptr<Context>>&
    getOperasiPerbandinganContext() const;
    [[nodiscard]] nstd::bisa_kosong<std::unique_ptr<Context>>&
    getOperatorLogikaTidakContext() const;

  private:
    nstd::bisa_kosong<std::unique_ptr<Context>> operatorLogikaTidakContext;
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPerbandinganContext;
};
