#pragma once

#include <memory>

#include "nstd/daftar.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"

class OperasiKurangSamaDenganContext: public Context {
  public:
    explicit OperasiKurangSamaDenganContext(
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanOperasiTambahSamaDenganContext,
        nstd::daftar<Token> kumpulanOperator
    );
    static OperasiKurangSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    );
    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getKumpulanOperasiTambahSamaDenganContext() const;
    [[nodiscard]] const nstd::daftar<Token>& getKumpulanOperator() const;

  private:
    nstd::daftar<std::unique_ptr<Context>>
        kumpulanOperasiTambahSamaDenganContext;
    nstd::daftar<Token> kumpulanOperator;
};
