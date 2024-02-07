#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class OperasiPenugasanContext: public Context {
  public:
    OperasiPenugasanContext(
      nstd::bisa_kosong<nstd::daftar<Context>> kumpulanNilaiContext,
      nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperatorPenugasanContext
    );
    static OperasiPenugasanContext generate(const std::vector<std::unique_ptr<ParserTree>>& children);
    [[nodiscard]] nstd::bisa_kosong<nstd::daftar<Context>> getKumpulanNilaiContext() const;
    [[nodiscard]] nstd::bisa_kosong<nstd::daftar<Context>> getKumpulanOperatorPenugasanContext() const;
  private:
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanNilaiContext;
    nstd::bisa_kosong<nstd::daftar<Context>> kumpulanOperatorPenugasanContext;
};