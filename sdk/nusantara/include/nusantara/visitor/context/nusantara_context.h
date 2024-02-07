#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class NusantaraContext: public Context {
  public:
    explicit NusantaraContext(
      nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperasiPenugasanContext
    );
    static NusantaraContext generate(const std::vector<std::unique_ptr<ParserTree>>& children);
    [[nodiscard]] nstd::bisa_kosong<nstd::daftar<Context>> getKumpulanOperasiPenugasanContext() const;
  private:
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperasiPenugasanContext;
};