#pragma once

#include <memory>
#include <vector>

#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NusantaraContext: public Context {
  public:
    explicit NusantaraContext(
        std::vector<std::unique_ptr<Context>> kumpulanPernyataanContext
    );
    static NusantaraContext generate(
        const std::vector<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const std::vector<std::unique_ptr<Context>>&
    getKumpulanPernyataan() const;

  private:
    std::vector<std::unique_ptr<Context>> kumpulanPernyataanContext;
};
