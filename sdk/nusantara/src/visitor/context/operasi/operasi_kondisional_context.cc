#include "visitor/context/operasi/operasi_kondisional_context.h"

#include <memory>

#include "lexer/token_type.h"
#include "nstd/kosong.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/operasi/operasi_atau_context.h"

OperasiKondisionalContext::OperasiKondisionalContext(
    std::unique_ptr<Context> kondisiOperasiAtauContext,
    nstd::bisa_kosong<Token> tandaTanya,
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiBenarEkspresiContext,
    nstd::bisa_kosong<Token> titikDua,
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiSalahEkspresiContext
):
    kondisiOperasiAtauContext(std::move(kondisiOperasiAtauContext)),
    tandaTanya(std::move(tandaTanya)),
    nilaiBenarEkspresiContext(std::move(nilaiBenarEkspresiContext)),
    titikDua(std::move(titikDua)),
    nilaiSalahEkspresiContext(std::move(nilaiSalahEkspresiContext)) {}

OperasiKondisionalContext OperasiKondisionalContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> kondisiOperasiAtauContext;
  nstd::bisa_kosong<Token> tandaTanya;
  nstd::bisa_kosong<std::unique_ptr<Context>> nilaiBenarEkspresiContext;
  nstd::bisa_kosong<Token> titikDua;
  nstd::bisa_kosong<std::unique_ptr<Context>> nilaiSalahEkspresiContext;
  size_t index = 0;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_atau) {
        kondisiOperasiAtauContext = std::make_unique<OperasiAtauContext>(
            OperasiAtauContext::generate(prt->getChildren())
        );
      } else if(prt->getRule() == ParserRule::ekspresi) {
        if(nstd::kosong(nilaiBenarEkspresiContext)) {
          nilaiBenarEkspresiContext = std::make_unique<EkspresiContext>(
              EkspresiContext::generate(prt->getChildren())
          );
        } else if(nstd::kosong(nilaiSalahEkspresiContext)) {
          nilaiSalahEkspresiContext = std::make_unique<EkspresiContext>(
              EkspresiContext::generate(prt->getChildren())
          );
        }
      }
    } else if(auto* ptt = dynamic_cast<ParserTokenTree*>(child.get())) {
      const Token& token = ptt->getToken();
      const TokenType& type = token.getType();
      if(type == TokenType::TANDA_TANYA) {
        tandaTanya = token;
      } else if(type == TokenType::TITIK_DUA) {
        titikDua = token;
      }
    }
    ++index;
  }
  return OperasiKondisionalContext(
      std::move(kondisiOperasiAtauContext), std::move(tandaTanya),
      std::move(nilaiBenarEkspresiContext), std::move(titikDua),
      std::move(nilaiSalahEkspresiContext)
  );
}

const std::unique_ptr<Context>&
OperasiKondisionalContext::getKondisiOperasiAtauContext() const {
  return this->kondisiOperasiAtauContext;
}

const nstd::bisa_kosong<Token>& OperasiKondisionalContext::getTandaTanya(
) const {
  return this->tandaTanya;
}

const nstd::bisa_kosong<std::unique_ptr<Context>>&
OperasiKondisionalContext::getNilaiBenarEkspresiContext() const {
  return this->nilaiBenarEkspresiContext;
}

const nstd::bisa_kosong<Token>& OperasiKondisionalContext::getTitikDua() const {
  return this->titikDua;
}

const nstd::bisa_kosong<std::unique_ptr<Context>>&
OperasiKondisionalContext::getNilaiSalahEkspresiContext() const {
  return this->nilaiSalahEkspresiContext;
}
