#include "parser/parser_tree.h"

#include <format>
#include <iostream>
#include <memory>
#include <string>

#include "lexer/token.h"
#include "lexer/token_type.h"
#include "parser/parser_rule.h"

void ParserTree::addChild(std::unique_ptr<ParserTree> child) {
  this->children.emplace_back(std::move(child));
}

void ParserTree::printTree(const int &indent) const {
  for(int i = 0; i < indent; ++i) { std::cout << " "; }
  std::cout << this->toString() << "\n";
  for(const std::unique_ptr<ParserTree> &child : this->children) {
    child->printTree(indent + 1);
  }
}

const std::vector<std::unique_ptr<ParserTree>> &ParserTree::getChildren(
) const {
  return this->children;
}

ParserRuleTree::ParserRuleTree(const ParserRule &rule): rule(rule) {}

std::string ParserRuleTree::toString() const {
  return std::format("RULE: {}", ::toString(this->rule));
}

ParserRule ParserRuleTree::getRule() const { return this->rule; }

ParserTokenTree::ParserTokenTree(Token token): token(std::move(token)) {}

std::string ParserTokenTree::toString() const {
  return std::format(
      "{}: {}", ::toString(this->token.getType()), this->token.getValue()
  );
}

Token ParserTokenTree::getToken() const { return this->token; }
