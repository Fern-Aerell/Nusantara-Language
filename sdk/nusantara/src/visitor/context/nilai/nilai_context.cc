#include "visitor/context/nilai/nilai_context.h"

#include "lexer/token_type.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/nilai/nilai_kalimat_context.h"

NilaiContext::NilaiContext(
    nstd::bisa_kosong<Token> nilai,
    nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext,
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext
):
    nilai(std::move(nilai)),
    ekspresiContext(std::move(ekspresiContext)),
    nilaiKalimatContext(std::move(nilaiKalimatContext)){};

NilaiContext NilaiContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(children[0].get())) {
    const Token token = ptchildToken->getToken();
    const TokenType type = token.getType();
    const nstd::daftar<TokenType> nilaiTokenType = {
        TokenType::BILANGAN, TokenType::BENAR, TokenType::SALAH,
        TokenType::IDENTIFIKASI
    };
    if(nstd::contains<TokenType>(nilaiTokenType, type)) {
      nstd::bisa_kosong<Token> nilai = token;
      return NilaiContext(std::move(nilai), {}, {});
    } else if(type == TokenType::KURUNG_BUKA) {
      nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
      auto* ptchild1 = dynamic_cast<ParserRuleTree*>(children[1].get());
      if(nstd::kosong(ekspresiContext)) {
        ekspresiContext = std::make_unique<EkspresiContext>(
            EkspresiContext::generate(ptchild1->getChildren())
        );
      }
      return NilaiContext({}, std::move(ekspresiContext), {});
    }
  } else if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(children[0].get())) {
    if(ptchildRule->getRule() == ParserRule::nilai_kalimat) {
      nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext =
          std::make_unique<NilaiKalimatContext>(
              NilaiKalimatContext::generate(ptchildRule->getChildren())
          );
      return NilaiContext({}, {}, std::move(nilaiKalimatContext));
    }
  }
  throw std::runtime_error("Nilai Context Tidak Valid");
}

const nstd::bisa_kosong<Token>& NilaiContext::getNilai() const {
  return this->nilai;
}

const nstd::bisa_kosong<std::unique_ptr<Context>>&
NilaiContext::getEkspresiContext() const {
  return this->ekspresiContext;
}

const nstd::bisa_kosong<std::unique_ptr<Context>>&
NilaiContext::getNilaiKalimatContext() const {
  return this->nilaiKalimatContext;
}
