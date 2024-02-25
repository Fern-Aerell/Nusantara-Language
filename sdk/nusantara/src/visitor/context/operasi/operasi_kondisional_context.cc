#include "visitor/context/operasi/operasi_kondisional_context.h"

#include <memory>
#include <optional>

#include "lexer/token_type.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/operasi/operasi_atau_context.h"

OperasiKondisionalContext::OperasiKondisionalContext(
    std::unique_ptr<Context> kondisiOperasiAtauContext,
    std::optional<Token> tandaTanya,
    std::optional<std::unique_ptr<Context>> nilaiBenarEkspresiContext,
    std::optional<Token> titikDua,
    std::optional<std::unique_ptr<Context>> nilaiSalahEkspresiContext
):
    kondisiOperasiAtauContext(std::move(kondisiOperasiAtauContext)),
    tandaTanya(std::move(tandaTanya)),
    nilaiBenarEkspresiContext(std::move(nilaiBenarEkspresiContext)),
    titikDua(std::move(titikDua)),
    nilaiSalahEkspresiContext(std::move(nilaiSalahEkspresiContext)) {}

OperasiKondisionalContext OperasiKondisionalContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> kondisiOperasiAtauContext;
  std::optional<Token> tandaTanya;
  std::optional<std::unique_ptr<Context>> nilaiBenarEkspresiContext;
  std::optional<Token> titikDua;
  std::optional<std::unique_ptr<Context>> nilaiSalahEkspresiContext;
  size_t index = 0;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      if(prt->getRule() == ParserRule::operasi_atau) {
        kondisiOperasiAtauContext = std::make_unique<OperasiAtauContext>(
            OperasiAtauContext::generate(prt->getChildren())
        );
      } else if(prt->getRule() == ParserRule::ekspresi) {
        if(!nilaiBenarEkspresiContext.has_value()) {
          nilaiBenarEkspresiContext = std::make_unique<EkspresiContext>(
              EkspresiContext::generate(prt->getChildren())
          );
        } else if(!nilaiSalahEkspresiContext.has_value()) {
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

const std::optional<Token>& OperasiKondisionalContext::getTandaTanya(
) const {
  return this->tandaTanya;
}

const std::optional<std::unique_ptr<Context>>&
OperasiKondisionalContext::getNilaiBenarEkspresiContext() const {
  return this->nilaiBenarEkspresiContext;
}

const std::optional<Token>& OperasiKondisionalContext::getTitikDua() const {
  return this->titikDua;
}

const std::optional<std::unique_ptr<Context>>&
OperasiKondisionalContext::getNilaiSalahEkspresiContext() const {
  return this->nilaiSalahEkspresiContext;
}
