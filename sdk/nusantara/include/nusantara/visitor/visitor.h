#pragma once

#include <nusantara/parser/parser_tree.h>

#include <memory>
#include <stdexcept>

#include "nstd/kosong.h"

class Context {
  public:
    Context() = default;  // constructor
    virtual ~Context() =
        default;  // destructor (virtual if X is meant to be a base class)
    Context(const Context&) = default;                 // copy constructor
    Context& operator=(const Context&) = default;      // copy assignment
    Context(Context&&) noexcept = default;             // move constructor
    Context& operator=(Context&&) noexcept = default;  // move assignment

  private:
};

class NusantaraContext: public Context {
  public:
    static NusantaraContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class EkspresiContext: public Context {
  public:
    static EkspresiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKananBitSamaDenganContext: public Context {
  public:
    static OperasiGeserKananBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKiriBitSamaDenganContext: public Context {
  public:
    static OperasiGeserKiriBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiXorBitSamaDenganContext: public Context {
  public:
    static OperasiXorBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiOrBitSamaDenganContext: public Context {
  public:
    static OperasiOrBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiAndBitSamaDenganContext: public Context {
  public:
    static OperasiAndBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKurangSamaDenganContext: public Context {
  public:
    static OperasiKurangSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTambahSamaDenganContext: public Context {
  public:
    static OperasiTambahSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSisaBagiSamaDenganContext: public Context {
  public:
    static OperasiSisaBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiBagiSamaDenganContext: public Context {
  public:
    static OperasiBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKaliSamaDenganContext: public Context {
  public:
    static OperasiKaliSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSamaDenganContext: public Context {
  public:
    static OperasiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiAtauContext: public Context {
  public:
    static OperasiAtauContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiDanContext: public Context {
  public:
    static OperasiDanContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiOrBitContext: public Context {
  public:
    static OperasiOrBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiXorBitContext: public Context {
  public:
    static OperasiXorBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiAndBitContext: public Context {
  public:
    static OperasiAndBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTidakSamaContext: public Context {
  public:
    static OperasiTidakSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSamaContext: public Context {
  public:
    static OperasiSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihBesarSamaDenganContext: public Context {
  public:
    static OperasiLebihBesarSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihBesarContext: public Context {
  public:
    static OperasiLebihBesarContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihKecilSamaDenganContext: public Context {
  public:
    static OperasiLebihKecilSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihKecilContext: public Context {
  public:
    static OperasiLebihKecilContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKananBitContext: public Context {
  public:
    static OperasiGeserKananBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKiriBitContext: public Context {
  public:
    static OperasiGeserKiriBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKurangContext: public Context {
  public:
    static OperasiKurangContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTambahContext: public Context {
  public:
    static OperasiTambahContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSisaPembagianContext: public Context {
  public:
    static OperasiSisaPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiPembagianContext: public Context {
  public:
    static OperasiPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiPerkalianContext: public Context {
  public:
    static OperasiPerkalianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTidakContext: public Context {
  public:
    static OperasiTidakContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiNotBitContext: public Context {
  public:
    static OperasiNotBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKurangSatuContext: public Context {
  public:
    static OperasiKurangSatuContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class NilaiKalimatContext: public Context {
  public:
    NilaiKalimatContext(
        nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken,
        nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
            kumpulanEkspresiContext
    ):
        kumpulanToken(std::move(kumpulanToken)),
        kumpulanEkspresiContext(std::move(kumpulanEkspresiContext)){};

    static NilaiKalimatContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken;
      nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
          kumpulanEkspresiContext;
      for(const std::unique_ptr<ParserTree>& child : children) {
        if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(child.get())) {
          if(nstd::kosong(kumpulanEkspresiContext)) {
            kumpulanEkspresiContext = nstd::daftar<std::unique_ptr<Context>>();
          }
          std::unique_ptr<Context> context = std::make_unique<EkspresiContext>(
              EkspresiContext::generate(ptchildRule->getChildren())
          );
          kumpulanEkspresiContext->push_back(std::move(context));
        } else if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(child.get())) {
          if(nstd::kosong(kumpulanToken)) {
            kumpulanToken = nstd::daftar<Token>();
          }
          kumpulanToken->push_back(ptchildToken->getToken());
        }
      }
      return {std::move(kumpulanToken), std::move(kumpulanEkspresiContext)};
    }

    [[nodiscard]] const nstd::bisa_kosong<nstd::daftar<Token>>&
    getKumpulanToken() const {
      return this->kumpulanToken;
    }

    [[nodiscard]] const nstd::bisa_kosong<
        nstd::daftar<std::unique_ptr<Context>>>&
    getkumpulanEkspresiContext() const {
      return this->kumpulanEkspresiContext;
    }

  private:
    nstd::bisa_kosong<nstd::daftar<Token>> kumpulanToken;
    nstd::bisa_kosong<nstd::daftar<std::unique_ptr<Context>>>
        kumpulanEkspresiContext;
};

class NilaiContext: public Context {
  public:
    NilaiContext(
        nstd::bisa_kosong<Token> nilai, nstd::bisa_kosong<Token> kurungBuka,
        nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext,
        nstd::bisa_kosong<Token> kurungTutup,
        nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext
    ):
        nilai(std::move(nilai)),
        kurungBuka(std::move(kurungBuka)),
        ekspresiContext(std::move(ekspresiContext)),
        kurungTutup(std::move(kurungTutup)),
        nilaiKalimatContext(std::move(nilaiKalimatContext)){};

    static NilaiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      if(auto* ptchildToken =
             dynamic_cast<ParserTokenTree*>(children[0].get())) {
        const Token token = ptchildToken->getToken();
        const TokenType type = token.getType();
        const nstd::daftar<TokenType> nilaiTokenType = {
            TokenType::BILANGAN, TokenType::BENAR, TokenType::SALAH
        };
        if(nstd::contains<TokenType>(nilaiTokenType, type)) {
          nstd::bisa_kosong<Token> nilai = token;
          return NilaiContext(std::move(nilai), {}, {}, {}, {});
        } else if(type == TokenType::KURUNG_BUKA) {
          nstd::bisa_kosong<Token> kurungBuka = token;
          nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
          nstd::bisa_kosong<Token> kurungTutup;
          auto* ptchild1 = dynamic_cast<ParserRuleTree*>(children[1].get());
          if(nstd::kosong(ekspresiContext)) {
            ekspresiContext = std::make_unique<EkspresiContext>(
                EkspresiContext::generate(ptchild1->getChildren())
            );
          }
          auto* ptchild2 = dynamic_cast<ParserTokenTree*>(children[2].get());
          if(ptchild2 != nullptr) { kurungTutup = ptchild2->getToken(); }
          return NilaiContext(
              {}, std::move(kurungBuka), std::move(ekspresiContext),
              std::move(kurungTutup), {}
          );
        }
      } else if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(children[0].get())) {
        if(ptchildRule->getRule() == ParserRule::nilai_kalimat) {
          nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext =
              std::make_unique<NilaiKalimatContext>(
                  NilaiKalimatContext::generate(ptchildRule->getChildren())
              );
          return NilaiContext({}, {}, {}, {}, std::move(nilaiKalimatContext));
        }
      }
      throw std::runtime_error("Nilai Context Tidak Valid");
    }

    [[nodiscard]] const nstd::bisa_kosong<Token>& getNilai() const {
      return this->nilai;
    }

    [[nodiscard]] const nstd::bisa_kosong<Token>& getKurungBuka() const {
      return this->kurungBuka;
    }

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getEkspresiContext() const {
      return this->ekspresiContext;
    }

    [[nodiscard]] nstd::bisa_kosong<Token> getKurungTutup() const {
      return this->kurungTutup;
    }

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getNilaiKalimatContext() const {
      return this->nilaiKalimatContext;
    }

  private:
    nstd::bisa_kosong<Token> nilai;
    nstd::bisa_kosong<Token> kurungBuka;
    nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
    nstd::bisa_kosong<Token> kurungTutup;
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext;
};

class OperasiTambahSatuContext: public Context {
  public:
    static OperasiTambahSatuContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

template<typename T>
class Visitor {
  public:
    Visitor() = default;  // constructor
    virtual ~Visitor() =
        default;  // destructor (virtual if X is meant to be a base class)
    Visitor(const Visitor&) = default;                 // copy constructor
    Visitor& operator=(const Visitor&) = default;      // copy assignment
    Visitor(Visitor&&) noexcept = default;             // move constructor
    Visitor& operator=(Visitor&&) noexcept = default;  // move assignment

    T visit(const std::unique_ptr<ParserTree>& tree) {
      if(auto* rule = dynamic_cast<ParserRuleTree*>(tree.get())) {
        switch(rule->getRule()) {
          case ParserRule::nusantara:
            return this->visitNusantara(
                NusantaraContext::generate(rule->getChildren())
            );
          case ParserRule::ekspresi:
            return this->visitEkspresi(
                EkspresiContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit_sama_dengan:
            return this->visitOperasiGeserKananBitSamaDengan(
                OperasiGeserKananBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_geser_kiri_bit_sama_dengan:
            return this->visitOperasiGeserKiriBitSamaDengan(
                OperasiGeserKiriBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_xor_bit_sama_dengan:
            return this->visitOperasiXorBitSamaDengan(
                OperasiXorBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit_sama_dengan:
            return this->visitOperasiOrBitSamaDengan(
                OperasiOrBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit_sama_dengan:
            return this->visitOperasiAndBitSamaDengan(
                OperasiAndBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_sama_dengan:
            return this->visitOperasiKurangSamaDengan(
                OperasiKurangSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_sama_dengan:
            return this->visitOperasiTambahSamaDengan(
                OperasiTambahSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_bagi_sama_dengan:
            return this->visitOperasiSisaBagiSamaDengan(
                OperasiSisaBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_bagi_sama_dengan:
            return this->visitOperasiBagiSamaDengan(
                OperasiBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kali_sama_dengan:
            return this->visitOperasiKaliSamaDengan(
                OperasiKaliSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama_dengan:
            return this->visitOperasiSamaDengan(
                OperasiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_atau:
            return this->visitOperasiAtau(
                OperasiAtauContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_dan:
            return this->visitOperasiDan(
                OperasiDanContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit:
            return this->visitOperasiOrBit(
                OperasiOrBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_xor_bit:
            return this->visitOperasiXorBit(
                OperasiXorBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit:
            return this->visitOperasiAndBit(
                OperasiAndBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak_sama:
            return this->visitOperasiTidakSama(
                OperasiTidakSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama:
            return this->visitOperasiSama(
                OperasiSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_besar_sama_dengan:
            return this->visitOperasiLebihBesarSamaDengan(
                OperasiLebihBesarSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_besar:
            return this->visitOperasiLebihBesar(
                OperasiLebihBesarContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_kecil_sama_dengan:
            return this->visitOperasiLebihKecilSamaDengan(
                OperasiLebihKecilSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_kecil:
            return this->visitOperasiLebihKecil(
                OperasiLebihKecilContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit:
            return this->visitOperasiGeserKananBit(
                OperasiGeserKananBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kiri_bit:
            return this->visitOperasiGeserKiriBit(
                OperasiGeserKiriBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang:
            return this->visitOperasiKurang(
                OperasiKurangContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah:
            return this->visitOperasiTambah(
                OperasiTambahContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_pembagian:
            return this->visitOperasiSisaPembagian(
                OperasiSisaPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_pembagian:
            return this->visitOperasiPembagian(
                OperasiPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_perkalian:
            return this->visitOperasiPerkalian(
                OperasiPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak:
            return this->visitOperasiTidak(
                OperasiTidakContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_not_bit:
            return this->visitOperasiNotBit(
                OperasiNotBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_satu:
            return this->visitOperasiKurangSatu(
                OperasiKurangSatuContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_satu:
            return this->visitOperasiTambahSatu(
                OperasiTambahSatuContext::generate(rule->getChildren())
            );
          case ParserRule::nilai:
            return this->visitNilai(NilaiContext::generate(rule->getChildren())
            );
          case ParserRule::nilai_kalimat:
            return this->visitNilaiKalimat(
                NilaiKalimatContext::generate(rule->getChildren())
            );
        }
      }
      throw std::runtime_error("Aturan tidak valid.");
    }

    virtual T visitNusantara(const NusantaraContext& ctx) = 0;
    virtual T visitEkspresi(const EkspresiContext& ctx) = 0;
    virtual T visitOperasiGeserKananBitSamaDengan(
        const OperasiGeserKananBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBitSamaDengan(
        const OperasiGeserKiriBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiXorBitSamaDengan(
        const OperasiXorBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiOrBitSamaDengan(
        const OperasiOrBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiAndBitSamaDengan(
        const OperasiAndBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKurangSamaDengan(
        const OperasiKurangSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiTambahSamaDengan(
        const OperasiTambahSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSisaBagiSamaDengan(
        const OperasiSisaBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiBagiSamaDengan(const OperasiBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKaliSamaDengan(const OperasiKaliSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSamaDengan(const OperasiSamaDenganContext& ctx) = 0;
    virtual T visitOperasiAtau(const OperasiAtauContext& ctx) = 0;
    virtual T visitOperasiDan(const OperasiDanContext& ctx) = 0;
    virtual T visitOperasiOrBit(const OperasiOrBitContext& ctx) = 0;
    virtual T visitOperasiXorBit(const OperasiXorBitContext& ctx) = 0;
    virtual T visitOperasiAndBit(const OperasiAndBitContext& ctx) = 0;
    virtual T visitOperasiTidakSama(const OperasiTidakSamaContext& ctx) = 0;
    virtual T visitOperasiSama(const OperasiSamaContext& ctx) = 0;
    virtual T visitOperasiLebihBesarSamaDengan(
        const OperasiLebihBesarSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihBesar(const OperasiLebihBesarContext& ctx) = 0;
    virtual T visitOperasiLebihKecilSamaDengan(
        const OperasiLebihKecilSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihKecil(const OperasiLebihKecilContext& ctx) = 0;
    virtual T visitOperasiGeserKananBit(const OperasiGeserKananBitContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBit(const OperasiGeserKiriBitContext& ctx
    ) = 0;
    virtual T visitOperasiKurang(const OperasiKurangContext& ctx) = 0;
    virtual T visitOperasiTambah(const OperasiTambahContext& ctx) = 0;
    virtual T visitOperasiSisaPembagian(const OperasiSisaPembagianContext& ctx
    ) = 0;
    virtual T visitOperasiPembagian(const OperasiPembagianContext& ctx) = 0;
    virtual T visitOperasiPerkalian(const OperasiPerkalianContext& ctx) = 0;
    virtual T visitOperasiTidak(const OperasiTidakContext& ctx) = 0;
    virtual T visitOperasiNotBit(const OperasiNotBitContext& ctx) = 0;
    virtual T visitOperasiKurangSatu(const OperasiKurangSatuContext& ctx) = 0;
    virtual T visitOperasiTambahSatu(const OperasiTambahSatuContext& ctx) = 0;
    virtual T visitNilai(const NilaiContext& ctx) = 0;
    virtual T visitNilaiKalimat(const NilaiKalimatContext& ctx) = 0;

  private:
};
