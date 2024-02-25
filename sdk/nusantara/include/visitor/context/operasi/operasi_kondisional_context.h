#pragma once

#include <memory>
#include <optional>

#include "lexer/token.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKondisionalContext: public Context {
  public:
    OperasiKondisionalContext(
        std::unique_ptr<Context> kondisiOperasiAtauContext,
        std::optional<Token> tandaTanya,
        std::optional<std::unique_ptr<Context>> nilaiBenarEkspresiContext,
        std::optional<Token> titikDua,
        std::optional<std::unique_ptr<Context>> nilaiSalahEkspresiContext
    );
    static OperasiKondisionalContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::unique_ptr<Context>& getKondisiOperasiAtauContext(
    ) const;
    [[nodiscard]] const std::optional<Token>& getTandaTanya() const;
    [[nodiscard]] const std::optional<std::unique_ptr<Context>>&
    getNilaiBenarEkspresiContext() const;
    [[nodiscard]] const std::optional<Token>& getTitikDua() const;
    [[nodiscard]] const std::optional<std::unique_ptr<Context>>&
    getNilaiSalahEkspresiContext() const;

  private:
    std::unique_ptr<Context> kondisiOperasiAtauContext;
    std::optional<Token> tandaTanya;
    std::optional<std::unique_ptr<Context>> nilaiBenarEkspresiContext;
    std::optional<Token> titikDua;
    std::optional<std::unique_ptr<Context>> nilaiSalahEkspresiContext;
};
