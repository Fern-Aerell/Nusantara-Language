#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class EkspresiContext: public Context {
  public:
    explicit EkspresiContext(
        std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext
    );
    static EkspresiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::unique_ptr<Context>&
    getOperasiGeserKananBitSamaDenganContext() const;

  private:
    std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext;
};
