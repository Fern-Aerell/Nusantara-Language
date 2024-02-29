#pragma once

#include <memory>
#include <vector>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class EkspresiContext: public Context {
  public:
    explicit EkspresiContext(
        std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext
    );
    static EkspresiContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::unique_ptr<Context>&
    getOperasiGeserKananBitSamaDenganContext() const;

  private:
    std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext;
};
