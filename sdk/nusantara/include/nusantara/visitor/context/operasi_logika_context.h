#pragma once

#include "nusantara/visitor/context/context.h"
#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>
#include <memory>

class OperasiLogikaContext : public Context
{
public:
  OperasiLogikaContext(
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPerbandinganContext,
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorLogikaContext);
  static OperasiLogikaContext
  generate(const std::vector<std::unique_ptr<ParserTree>> &children);
  [[nodiscard]] nstd::konst<
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperasiPerbandinganContext() const;
  [[nodiscard]] nstd::konst<
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperatorLogikaContext() const;

private:
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperasiPerbandinganContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
    kumpulanOperatorLogikaContext;
};