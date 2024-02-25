#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NilaiContext: public Context {
  public:
    NilaiContext(
        std::optional<Token> nilai,
        std::optional<std::unique_ptr<Context>> ekspresiContext,
        std::optional<std::unique_ptr<Context>> nilaiKalimatContext
    );

    static NilaiContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );

    [[nodiscard]] const std::optional<Token>& getNilai() const;

    [[nodiscard]] const std::optional<std::unique_ptr<Context>>&
    getEkspresiContext() const;

    [[nodiscard]] const std::optional<std::unique_ptr<Context>>&
    getNilaiKalimatContext() const;

  private:
    std::optional<Token> nilai;
    std::optional<std::unique_ptr<Context>> ekspresiContext;
    std::optional<std::unique_ptr<Context>> nilaiKalimatContext;
};
