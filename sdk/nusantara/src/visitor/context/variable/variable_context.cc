#include "visitor/context/variable/variable_context.h"

#include <memory>
#include <optional>

#include "lexer/token_type.h"
#include "parser/parser_rule.h"
#include "parser/parser_tree.h"
#include "visitor/context/ekspresi/ekspresi_context.h"

VariableContext::VariableContext(
    Token tipe, Token nama, std::optional<Token> samaDengan,
    std::optional<std::unique_ptr<Context>> ekspresiContext
):
    tipe(std::move(tipe)),
    nama(std::move(nama)),
    samaDengan(std::move(samaDengan)),
    ekspresiContext(std::move(ekspresiContext)) {}

VariableContext VariableContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  auto* tipePtr = dynamic_cast<ParserTokenTree*>(children[0].get());
  auto* namaPtr = dynamic_cast<ParserTokenTree*>(children[1].get());
  Token tipe = tipePtr->getToken();
  Token nama = namaPtr->getToken();
  std::optional<Token> samaDengan;
  std::optional<std::unique_ptr<Context>> ekspresiContext;
  if(children.size() > 2) {
    for(size_t index = 2; index < children.size(); ++index) {
      if(auto* ptt = dynamic_cast<ParserTokenTree*>(children[index].get())) {
        const Token& token = ptt->getToken();
        if(token.getType() == TokenType::SAMA_DENGAN) { samaDengan = token; }
      } else if(auto* prt = dynamic_cast<ParserRuleTree*>(children[index].get())) {
        if(prt->getRule() == ParserRule::ekspresi) {
          ekspresiContext = std::make_unique<EkspresiContext>(
              EkspresiContext::generate(prt->getChildren())
          );
        }
      }
    }
  }
  return VariableContext(
      std::move(tipe), std::move(nama), std::move(samaDengan),
      std::move(ekspresiContext)
  );
}

const Token& VariableContext::getTipe() const { return this->tipe; }

const Token& VariableContext::getNama() const { return this->nama; }

const std::optional<Token>& VariableContext::getSamaDengan() const {
  return this->samaDengan;
}

const std::optional<std::unique_ptr<Context>>&
VariableContext::getEkspresiContext() const {
  return this->ekspresiContext;
}
