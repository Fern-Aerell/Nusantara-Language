#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class OperasiPenugasanPerkalianContext : public Context
{
public:
  OperasiPenugasanPerkalianContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiLogikaContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPenugasanPerkalianContext);
  static OperasiPenugasanPerkalianContext
  generate(const std::vector<std::unique_ptr<ParserTree>> &children);
  [[nodiscard]] nstd::konst<
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperasiLogikaContext() const;
  [[nodiscard]] nstd::konst<
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperatorPenugasanPerkalianContext() const;

private:
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperasiLogikaContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorPenugasanPerkalianContext;
};