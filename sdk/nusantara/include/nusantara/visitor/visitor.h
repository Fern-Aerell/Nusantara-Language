#pragma once

#include "nusantara/parser/parser_rule.h"
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
                    return this->visitNusantara(rule->getChildren());
                  case ParserRule::operator_penugasan:
                    return this->visitOperatorPenugasan(rule->getChildren());
                  case ParserRule::operasi_penugasan:
                    return this->visitOperasiPenugasan(rule->getChildren());
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
                    return this->visitNilai(rule->getChildren());
                }
            }
            return T{};
        }
        virtual T visitNusantara(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperatorPenugasan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
        virtual T visitOperasiPenugasan(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
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
        virtual T visitNilai(const std::vector<std::unique_ptr<ParserTree>>& children) = 0;
    private:
};