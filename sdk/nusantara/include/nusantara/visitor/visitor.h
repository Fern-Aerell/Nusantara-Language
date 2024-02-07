#pragma once

#include "nusantara/core/core.h"
#include "nusantara/lexer/token_type.h"
#include "nusantara/parser/parser_rule.h"
#include "nusantara/visitor/context/context.h"
#include "nusantara/visitor/context/nilai_context.h"
#include "nusantara/visitor/context/nusantara_context.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"
#include "nusantara/visitor/context/operator_penugasan_context.h"
#include <memory>
#include <nusantara/parser/parser_tree.h>
#include <stdexcept>
#include <string>

template<typename T>
class Visitor {
    public:
        Visitor() = default; // constructor
        virtual ~Visitor() = default;                     // destructor (virtual if X is meant to be a base class)
        Visitor(const Visitor&) = default;                // copy constructor
        Visitor& operator=(const Visitor&) = default;     // copy assignment
        Visitor(Visitor&&) noexcept = default;            // move constructor
        Visitor& operator=(Visitor&&) noexcept = default; // move assignment
        T visit(const std::unique_ptr<ParserTree>& tree) {
            if(auto* rule = dynamic_cast<ParserRuleTree*>(tree.get())) {
                switch (rule->getRule()) {
                  case ParserRule::nusantara:
                    return this->visitNusantara(NusantaraContext::generate(rule->getChildren()));
                  case ParserRule::operator_penugasan:
                    return this->visitOperatorPenugasan(OperatorPenugasanContext::generate(rule->getChildren()));
                  case ParserRule::operasi_penugasan:
                    return this->visitOperasiPenugasan(OperasiPenugasanContext::generate(rule->getChildren()));
                  case ParserRule::operator_penugasan_penjumlahan:
                    return this->visitOperatorPenugasanPenjumlahan(rule->getChildren());
                  case ParserRule::operasi_penugasan_penjumlahan:
                    return this->visitOperasiPenugasanPenjumlahan(rule->getChildren());
                  case ParserRule::operator_penugasan_perkalian:
                    return this->visitOperatorPenugasanPerkalian(rule->getChildren());
                  case ParserRule::operasi_penugasan_perkalian:
                    return this->visitOperasiPenugasanPerkalian(rule->getChildren());
                  case ParserRule::operator_logika:
                    return this->visitOperatorLogika(rule->getChildren());
                  case ParserRule::operasi_logika:
                    return this->visitOperasiLogika(rule->getChildren());
                  case ParserRule::operator_perbandingan:
                    return this->visitOperatorPerbandingan(rule->getChildren());
                  case ParserRule::operasi_perbandingan:
                    return this->visitOperasiPerbandingan(rule->getChildren());
                  case ParserRule::operator_pre_post:
                    return this->visitOperatorPrePost(rule->getChildren());
                  case ParserRule::operasi_pre_post:
                    return this->visitOperasiPrePost(rule->getChildren());
                  case ParserRule::operator_penjumlahan:
                    return this->visitOperatorPenjumlahan(rule->getChildren());
                  case ParserRule::operasi_penjumlahan:
                    return this->visitOperasiPenjumlahan(rule->getChildren());
                  case ParserRule::operator_perkalian:
                    return this->visitOperatorPerkalian(rule->getChildren());
                  case ParserRule::operasi_perkalian:
                    return this->visitOperasiPerkalian(rule->getChildren());
                  case ParserRule::nilai:
                    return this->visitNilai(NilaiContext::generate(rule->getChildren()));
                }
            }
            return T{};
        }
        virtual T visitNusantara(nstd::konst<NusantaraContext>& ctx) = 0;
        virtual T visitOperatorPenugasan(nstd::konst<OperatorPenugasanContext>& ctx) = 0;
        virtual T visitOperasiPenugasan(nstd::konst<OperasiPenugasanContext>& ctx) = 0;
        virtual T visitOperatorPenugasanPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPenugasanPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPenugasanPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPenugasanPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorLogika(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiLogika(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPerbandingan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPerbandingan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPrePost(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPrePost(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitNilai(nstd::konst<NilaiContext>& ctx) = 0;
    private:
};

class TestVisitor: public Visitor<nstd::dinamis> {
  nstd::dinamis visitNusantara(nstd::konst<NusantaraContext>& ctx) override {
    return {};
  }
  nstd::dinamis visitOperatorPenugasan(nstd::konst<OperatorPenugasanContext>& ctx) override {
    return {};
  }
  nstd::dinamis visitOperasiPenugasan(nstd::konst<OperasiPenugasanContext>& ctx) override {
    return {};
  }
  nstd::dinamis visitOperatorPenugasanPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPenugasanPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorPenugasanPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPenugasanPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorLogika(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiLogika(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorPerbandingan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPerbandingan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPenjumlahan(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorPrePost(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPrePost(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperatorPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitOperasiPerkalian(const std::vector<std::unique_ptr<ParserTree>>& children) override {
    return {};
  }
  nstd::dinamis visitNilai(nstd::konst<NilaiContext>& ctx) override {
    if(!nstd::isKosong(ctx.getNilai())) {
      const TokenType& type = ctx.getNilai().value().getType();
      const nstd::kalimat& value = ctx.getNilai().value().getValue();
      if(type == TokenType::BULAT) {
        return std::stoi(value);
      }else if(type == TokenType::DESIMAL) {
        return std::stod(value);
      }else if(type == TokenType::KARAKTER) {
        return value[0];
      }else if(type == TokenType::KALIMAT) {
        return value;
      }else if(type == TokenType::BENAR) {
        return benar;
      }else if(type == TokenType::SALAH) {
        return salah;
      }
    }else if(!nstd::isKosong(ctx.getKurungBuka())) {
      Context context = ctx.getOperasiPenugasanContext().value();
      auto* value = dynamic_cast<OperasiPenugasanContext*>(&context);
      if(value != nullptr) {
        return this->visitOperasiPenugasan(*value);
      }
    }
    throw std::runtime_error("Nilai tidak valid.");
  }
};