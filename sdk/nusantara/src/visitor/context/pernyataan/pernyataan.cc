#include <memory>
#include <optional>

#include "parser/parser_rule.h"
#include "visitor/context/ekspresi/ekspresi_context.h"
#include "visitor/context/pernyataan/pernyataan_context.h"
#include "visitor/context/variable/variable_context.h"

PernyataanContext::PernyataanContext(
    std::optional<std::unique_ptr<Context>> variableContext,
    std::optional<std::unique_ptr<Context>> ekspresiContext
):
    variableContext(std::move(variableContext)),
    ekspresiContext(std::move(ekspresiContext)) {}

PernyataanContext PernyataanContext::generate(
    const std::vector<std::unique_ptr<ParserTree>>& children
) {
  std::optional<std::unique_ptr<Context>> variableContext;
  std::optional<std::unique_ptr<Context>> ekspresiContext;
  for(const std::unique_ptr<ParserTree>& child : children) {
    if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
      const ParserRule& rule = prt->getRule();
      if(rule == ParserRule::variable) {
        variableContext = std::make_unique<VariableContext>(
            VariableContext::generate(prt->getChildren())
        );
      } else if(rule == ParserRule::ekspresi) {
        ekspresiContext = std::make_unique<EkspresiContext>(
            EkspresiContext::generate(prt->getChildren())
        );
      }
    }
  }
  return PernyataanContext(
      std::move(variableContext), std::move(ekspresiContext)
  );
}

const std::optional<std::unique_ptr<Context>>&
PernyataanContext::getVariableContext() const {
  return this->variableContext;
}

const std::optional<std::unique_ptr<Context>>&
PernyataanContext::getEkspresiContext() const {
  return this->ekspresiContext;
}
