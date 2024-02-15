#pragma once

#include <nusantara/parser/parser_tree.h>

#include <memory>
#include <stdexcept>

#include "nusantara/parser/parser_rule.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/nusantara_context.h"
#include "nusantara/visitor/context/operasi_logika_context.h"
#include "nusantara/visitor/context/operasi_logika_tidak_context.h"
#include "nusantara/visitor/context/operasi_penjumlahan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operasi_penugasan_perkalian_context.h"
#include "nusantara/visitor/context/operasi_perbandingan_context.h"
#include "nusantara/visitor/context/operasi_perkalian_context.h"
#include "nusantara/visitor/context/operasi_pre_post_context.h"
#include "nusantara/visitor/context/operator_logika_context.h"
#include "nusantara/visitor/context/operator_logika_tidak_context.h"
#include "nusantara/visitor/context/operator_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_penugasan_context.h"
#include "nusantara/visitor/context/operator_penugasan_penjumlahan_context.h"
#include "nusantara/visitor/context/operator_penugasan_perkalian_context.h"
#include "nusantara/visitor/context/operator_perbandingan_context.h"
#include "nusantara/visitor/context/operator_perkalian_context.h"
#include "nusantara/visitor/context/operator_pre_post_context.h"

template<typename T>
class Visitor {
  public:
    Visitor() = default;  // constructor
    virtual ~Visitor() =
        default;  // destructor (virtual if X is meant to be a base class)
    Visitor(const Visitor &) = default;                 // copy constructor
    Visitor &operator=(const Visitor &) = default;      // copy assignment
    Visitor(Visitor &&) noexcept = default;             // move constructor
    Visitor &operator=(Visitor &&) noexcept = default;  // move assignment

    T visit(const std::unique_ptr<ParserTree> &tree) {
      if(auto *rule = dynamic_cast<ParserRuleTree *>(tree.get())) {
        switch(rule->getRule()) {
          case ParserRule::nusantara:
            return this->visitNusantara(
                NusantaraContext::generate(rule->getChildren())
            );
          case ParserRule::operator_penugasan:
            return this->visitOperatorPenugasan(
                OperatorPenugasanContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_penugasan:
            return this->visitOperasiPenugasan(
                OperasiPenugasanContext::generate(rule->getChildren())
            );
          case ParserRule::operator_penugasan_penjumlahan:
            return this->visitOperatorPenugasanPenjumlahan(
                OperatorPenugasanPenjumlahanContext::generate(rule->getChildren(
                ))
            );
          case ParserRule::operasi_penugasan_penjumlahan:
            return this->visitOperasiPenugasanPenjumlahan(
                OperasiPenugasanPenjumlahanContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operator_penugasan_perkalian:
            return this->visitOperatorPenugasanPerkalian(
                OperatorPenugasanPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_penugasan_perkalian:
            return this->visitOperasiPenugasanPerkalian(
                OperasiPenugasanPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operator_logika:
            return this->visitOperatorLogika(
                OperatorLogikaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_logika:
            return this->visitOperasiLogika(
                OperasiLogikaContext::generate(rule->getChildren())
            );
          case ParserRule::operator_logika_tidak:
            return this->visitOperatorLogikaTidak(
                OperatorLogikaTidakContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_logika_tidak:
            return this->visitOperasiLogikaTidak(
                OperasiLogikaTidakContext::generate(rule->getChildren())
            );
          case ParserRule::operator_perbandingan:
            return this->visitOperatorPerbandingan(
                OperatorPerbandinganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_perbandingan:
            return this->visitOperasiPerbandingan(
                OperasiPerbandinganContext::generate(rule->getChildren())
            );
          case ParserRule::operator_pre_post:
            return this->visitOperatorPrePost(
                OperatorPrePostContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_pre_post:
            return this->visitOperasiPrePost(
                OperasiPrePostContext::generate(rule->getChildren())
            );
          case ParserRule::operator_penjumlahan:
            return this->visitOperatorPenjumlahan(
                OperatorPenjumlahanContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_penjumlahan:
            return this->visitOperasiPenjumlahan(
                OperasiPenjumlahanContext::generate(rule->getChildren())
            );
          case ParserRule::operator_perkalian:
            return this->visitOperatorPerkalian(
                OperatorPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_perkalian:
            return this->visitOperasiPerkalian(
                OperasiPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::nilai:
            return this->visitNilai(NilaiContext::generate(rule->getChildren())
            );
        }
      }
      throw std::runtime_error("Aturan tidak valid.");
    }

    virtual T visitNusantara(const NusantaraContext &ctx) = 0;
    virtual T visitOperatorPenugasan(const OperatorPenugasanContext &ctx) = 0;
    virtual T visitOperasiPenugasan(const OperasiPenugasanContext &ctx) = 0;
    virtual T visitOperatorPenugasanPenjumlahan(
        const OperatorPenugasanPenjumlahanContext &ctx
    ) = 0;
    virtual T visitOperasiPenugasanPenjumlahan(
        const OperasiPenugasanPenjumlahanContext &ctx
    ) = 0;
    virtual T visitOperatorPenugasanPerkalian(
        const OperatorPenugasanPerkalianContext &ctx
    ) = 0;
    virtual T visitOperasiPenugasanPerkalian(
        const OperasiPenugasanPerkalianContext &ctx
    ) = 0;
    virtual T visitOperatorLogika(const OperatorLogikaContext &ctx) = 0;
    virtual T visitOperasiLogika(const OperasiLogikaContext &ctx) = 0;
    virtual T visitOperatorLogikaTidak(const OperatorLogikaTidakContext &ctx
    ) = 0;
    virtual T visitOperasiLogikaTidak(const OperasiLogikaTidakContext &ctx) = 0;
    virtual T visitOperatorPerbandingan(const OperatorPerbandinganContext &ctx
    ) = 0;
    virtual T visitOperasiPerbandingan(const OperasiPerbandinganContext &ctx
    ) = 0;
    virtual T visitOperatorPrePost(const OperatorPrePostContext &ctx) = 0;
    virtual T visitOperasiPrePost(const OperasiPrePostContext &ctx) = 0;
    virtual T visitOperatorPenjumlahan(const OperatorPenjumlahanContext &ctx
    ) = 0;
    virtual T visitOperasiPenjumlahan(const OperasiPenjumlahanContext &ctx) = 0;
    virtual T visitOperatorPerkalian(const OperatorPerkalianContext &ctx) = 0;
    virtual T visitOperasiPerkalian(const OperasiPerkalianContext &ctx) = 0;
    virtual T visitNilai(const NilaiContext &ctx) = 0;

  private:
};
