#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class NusantaraContext: public Context {
  public:
    explicit NusantaraContext(
        nstd::daftar<std::unique_ptr<Context>> kumpulanPernyataanContext
    );
    static NusantaraContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanPernyataan() const;

  private:
    nstd::daftar<std::unique_ptr<Context>> kumpulanPernyataanContext;
};
