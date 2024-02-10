#pragma once

#include <nusantara/core/core.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperasiPenugasanContext : public Context {
 public:
  OperasiPenugasanContext(
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
          kumpulanOperasiPenugasanPenjumlahanContext,
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
          kumpulanOperatorPenugasanContext);
  static OperasiPenugasanContext generate(
      const std::vector<std::unique_ptr<ParserTree>> &children);
  [[nodiscard]] nstd::konst<
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperasiPenugasanPenjumlahanContext() const;
  [[nodiscard]] nstd::konst<
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>> &
  getKumpulanOperatorPenugasanContext() const;

 private:
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperasiPenugasanPenjumlahanContext;
  nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
      kumpulanOperatorPenugasanContext;
};