#pragma once

#include <memory>
#include <vector>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NilaiKalimatContext: public Context {
  public:
    NilaiKalimatContext(
        std::vector<Token> kumpulanToken,
        std::vector<std::unique_ptr<Context>> kumpulanEkspresiContext
    );

    static NilaiKalimatContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );

    [[nodiscard]] const std::vector<Token>& getKumpulanToken() const;

    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getkumpulanEkspresiContext() const;

  private:
    std::vector<Token> kumpulanToken;
    std::vector<std::unique_ptr<Context>> kumpulanEkspresiContext;
};
