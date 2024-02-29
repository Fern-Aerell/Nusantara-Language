#include "visitor/context/nilai/nilai_context.h"

#include <optional>
#include <stdexcept>

#include "lexer/token_type.h"
#include "utils/utils.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/nilai/nilai_kalimat_context.h"

NilaiContext::NilaiContext(
    std::optional<Token> nilai,
    std::optional<std::unique_ptr<Context>> ekspresiContext,
    std::optional<std::unique_ptr<Context>> nilaiKalimatContext
):
    nilai(std::move(nilai)),
    ekspresiContext(std::move(ekspresiContext)),
    nilaiKalimatContext(std::move(nilaiKalimatContext)){};

NilaiContext NilaiContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(children[0].get())) {
    const Token token = ptchildToken->getToken();
    const TokenType type = token.getType();
    const std::vector<TokenType> nilaiTokenType = {
        TokenType::BILANGAN, TokenType::NILAI_BENAR, TokenType::NILAI_SALAH,
        TokenType::IDENTIFIKASI
    };
    if(utils::contains(nilaiTokenType, type)) {
      std::optional<Token> nilai = token;
      return NilaiContext(std::move(nilai), {}, {});
    } else if(type == TokenType::KURUNG_BUKA) {
      std::optional<std::unique_ptr<Context>> ekspresiContext;
      auto* ptchild1 = dynamic_cast<ParserRuleTree*>(children[1].get());
      if(!ekspresiContext.has_value()) {
        ekspresiContext = std::make_unique<EkspresiContext>(
            EkspresiContext::generate(ptchild1->getChildren())
        );
      }
      return NilaiContext({}, std::move(ekspresiContext), {});
    }
  } else if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(children[0].get())) {
    if(ptchildRule->getRule() == ParserRule::nilai_kalimat) {
      std::optional<std::unique_ptr<Context>> nilaiKalimatContext =
          std::make_unique<NilaiKalimatContext>(
              NilaiKalimatContext::generate(ptchildRule->getChildren())
          );
      return NilaiContext({}, {}, std::move(nilaiKalimatContext));
    }
  }
  throw std::runtime_error("Nilai Context Tidak Valid");
}

const std::optional<Token>& NilaiContext::getNilai() const {
  return this->nilai;
}

const std::optional<std::unique_ptr<Context>>& NilaiContext::getEkspresiContext(
) const {
  return this->ekspresiContext;
}

const std::optional<std::unique_ptr<Context>>&
NilaiContext::getNilaiKalimatContext() const {
  return this->nilaiKalimatContext;
}
