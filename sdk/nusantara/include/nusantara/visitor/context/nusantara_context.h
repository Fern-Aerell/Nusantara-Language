#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class NusantaraContext : public Context
{
public:
  explicit NusantaraContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPenugasanContext);
  static NusantaraContext
  generate(const std::vector<std::unique_ptr<ParserTree>> &children);
  [[nodiscard]] nstd::konst<
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperasiPenugasanContext() const;

private:
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperasiPenugasanContext;
};