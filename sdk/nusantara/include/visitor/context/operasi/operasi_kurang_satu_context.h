#pragma once

#include <memory>
#include <optional>


#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangSatuContext: public Context {
  public:
    explicit OperasiKurangSatuContext(
        const bool& isPre, const bool& isPost,
        std::unique_ptr<Context> operasiTambahSatuContext,
        std::optional<Token> satuOperator
    );
    static OperasiKurangSatuContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const bool& getIsPre() const;
    [[nodiscard]] const bool& getIsPost() const;
    [[nodiscard]] const std::unique_ptr<Context>& getOperasiTambahSatuContext(
    ) const;
    [[nodiscard]] const std::optional<Token>& getSatuOperator() const;

  private:
    bool isPre;
    bool isPost;
    std::unique_ptr<Context> operasiTambahSatuContext;
    std::optional<Token> satuOperator;
};
