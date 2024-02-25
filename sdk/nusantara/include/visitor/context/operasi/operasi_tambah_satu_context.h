#pragma once

#include <memory>
#include <optional>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiTambahSatuContext: public Context {
  public:
    explicit OperasiTambahSatuContext(
        const bool& isPre, const bool& isPost,
        std::unique_ptr<Context> nilaiContext,
        std::optional<Token> satuOperator
    );
    static OperasiTambahSatuContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const bool& getIsPost() const;
    [[nodiscard]] const std::unique_ptr<Context>& getNilaiContext() const;
    [[nodiscard]] const std::optional<Token>& getSatuOperator() const;

  private:
    bool isPre;
    bool isPost;
    std::unique_ptr<Context> nilaiContext;
    std::optional<Token> satuOperator;
};
