#pragma once

#include "nusantara/parser/parser_rule.h"
#include "nusantara/visitor/context/nusantara_context.h"
#include <memory>
#include <nusantara/parser/parser_tree.h>

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
                    return this->visitNusantara(generateNusantaraContext(rule->getChildren()));
                  case ParserRule::operator_penugasan:
                    return this->visitOperatorPenugasan(generateOperatorPenugasanContext(rule->getChildren()));
                  case ParserRule::operasi_penugasan:
                    return this->visitOperasiPenugasan(generateOperasiPenugasanContext(rule->getChildren()));
                  case ParserRule::operator_penugasan_penjumlahan:
                    return this->visitOperatorPenugasanPenjumlahan(generateOperatorPenugasanPenjumlahanContext(rule->getChildren()));
                  case ParserRule::operasi_penugasan_penjumlahan:
                    return this->visitOperasiPenugasanPenjumlahan(generateOperasiPenugasanPenjumlahanContext(rule->getChildren()));
                  case ParserRule::operator_penugasan_perkalian:
                    return this->visitOperatorPenugasanPerkalian(generateOperatorPenugasanPerkalianContext(rule->getChildren()));
                  case ParserRule::operasi_penugasan_perkalian:
                    return this->visitOperasiPenugasanPerkalian(generateOperasiPenugasanPerkalianContext(rule->getChildren()));
                  case ParserRule::operator_logika:
                    return this->visitOperatorLogika(generateOperatorLogikaContext(rule->getChildren()));
                  case ParserRule::operasi_logika:
                    return this->visitOperasiLogika(generateOperasiLogikaContext(rule->getChildren()));
                  case ParserRule::operator_perbandingan:
                    return this->visitOperatorPerbandingan(generateOperatorPerbandinganContext(rule->getChildren()));
                  case ParserRule::operasi_perbandingan:
                    return this->visitOperasiPerbandingan(generateOperasiPerbandinganContext(rule->getChildren()));
                  case ParserRule::operator_pre_post:
                    return this->visitOperatorPrePost(generateOperatorPrePostContext(rule->getChildren()));
                  case ParserRule::operasi_pre_post:
                    return this->visitOperasiPrePost(generateOperasiPrePostContext(rule->getChildren()));
                  case ParserRule::operator_penjumlahan:
                    return this->visitOperatorPenjumlahan(generateOperatorPenjumlahanContext(rule->getChildren()));
                  case ParserRule::operasi_penjumlahan:
                    return this->visitOperasiPenjumlahan(generateOperasiPenjumlahanContext(rule->getChildren()));
                  case ParserRule::operator_perkalian:
                    return this->visitOperatorPerkalian(generateOperatorPerkalianContext(rule->getChildren()));
                  case ParserRule::operasi_perkalian:
                    return this->visitOperasiPerkalian(generateOperasiPerkalianContext(rule->getChildren()));
                  case ParserRule::nilai:
                    return this->visitNilai(generateNilaiContext(rule->getChildren()));
                }
            }
            return T{};
        }
        virtual T visitNusantara(const NusantaraContext& ctx) = 0;
        virtual T visitOperatorPenugasan(const OperatorPenugasanContext& ctx) = 0;
        virtual T visitOperasiPenugasan(const OperasiPenugasanContext& ctx) = 0;
        virtual T visitOperatorPenugasanPenjumlahan(const OperatorPenugasanPenjumlahanContext& ctx) = 0;
        virtual T visitOperasiPenugasanPenjumlahan(const OperasiPenugasanPenjumlahanContext& ctx) = 0;
        virtual T visitOperatorPenugasanPerkalian(const OperatorPenugasanPerkalianContext& ctx) = 0;
        virtual T visitOperasiPenugasanPerkalian(const OperasiPenugasanPerkalianContext& ctx) = 0;
        virtual T visitOperatorLogika(const OperatorLogikaContext& ctx) = 0;
        virtual T visitOperasiLogika(const OperasiLogikaContext& ctx) = 0;
        virtual T visitOperatorPerbandingan(const OperatorPerbandinganContext& ctx) = 0;
        virtual T visitOperasiPerbandingan(const OperasiPerbandinganContext& ctx) = 0;
        virtual T visitOperatorPenjumlahan(const OperatorPenjumlahanContext& ctx) = 0;
        virtual T visitOperasiPenjumlahan(const OperasiPenjumlahanContext& ctx) = 0;
        virtual T visitOperatorPrePost(const OperatorPrePostContext& ctx) = 0;
        virtual T visitOperasiPrePost(const OperasiPrePostContext& ctx) = 0;
        virtual T visitOperatorPerkalian(const OperatorPerkalianContext& ctx) = 0;
        virtual T visitOperasiPerkalian(const OperasiPerkalianContext& ctx) = 0;
        virtual T visitNilai(const NilaiContext& ctx) = 0;
    private:
};