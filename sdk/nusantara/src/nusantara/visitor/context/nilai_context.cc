#include <nusantara/visitor/context/nilai_context.h>

#include <stdexcept>

#include "nstd/kosong.h"
#include "nusantara/visitor/context/operasi_penugasan_context.h"

NilaiContext::NilaiContext(
    nstd::bisa_kosong<Token> nilai, nstd::bisa_kosong<Token> kurungBuka,
    nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenugasanContext,
    nstd::bisa_kosong<Token> kurungTutup
):
    nilai(std::move(nilai)),
    kurungBuka(std::move(kurungBuka)),
    operasiPenugasanContext(std::move(operasiPenugasanContext)),
    kurungTutup(std::move(kurungTutup)) {}

NilaiContext NilaiContext::generate(
    const std::vector<std::unique_ptr<ParserTree>> &children
) {
  auto *ptchild0 = dynamic_cast<ParserTokenTree *>(children[0].get());
  if(ptchild0 != nullptr) {
    const Token token = ptchild0->getToken();
    const TokenType type = token.getType();
    const nstd::daftar<TokenType> nilaiTokenType = {
        TokenType::BILANGAN, TokenType::KALIMAT, TokenType::BENAR,
        TokenType::SALAH
    };
    if(nstd::contains<TokenType>(nilaiTokenType, type)) {
      nstd::bisa_kosong<Token> nilai = token;
      return NilaiContext(std::move(nilai), {}, {}, {});
    } else if(type == TokenType::KURUNG_BUKA) {
      nstd::bisa_kosong<Token> kurungBuka = token;
      nstd::bisa_kosong<std::unique_ptr<Context>> operasiPenugasanContext;
      nstd::bisa_kosong<Token> kurungTutup;
      auto *ptchild1 = dynamic_cast<ParserRuleTree *>(children[1].get());
      if(nstd::kosong(operasiPenugasanContext)) {
        operasiPenugasanContext = std::make_unique<OperasiPenugasanContext>(
            OperasiPenugasanContext::generate(ptchild1->getChildren())
        );
      }
      auto *ptchild2 = dynamic_cast<ParserTokenTree *>(children[2].get());
      if(ptchild2 != nullptr) { kurungTutup = ptchild2->getToken(); }
      return NilaiContext(
          {}, std::move(kurungBuka), std::move(operasiPenugasanContext),
          std::move(kurungTutup)
      );
    }
  }
  throw std::runtime_error("Nilai Context Tidak Valid");
}

nstd::bisa_kosong<Token> NilaiContext::getNilai() const { return this->nilai; }

nstd::bisa_kosong<Token> NilaiContext::getKurungBuka() const {
  return this->kurungBuka;
}

const nstd::bisa_kosong<std::unique_ptr<Context>> &
NilaiContext::getOperasiPenugasanContext() const {
  return this->operasiPenugasanContext;
}

nstd::bisa_kosong<Token> NilaiContext::getKurungTutup() const {
  return this->kurungTutup;
}
