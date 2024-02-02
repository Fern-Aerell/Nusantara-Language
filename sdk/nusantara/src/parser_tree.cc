#include "token.h"
#include "token_type.h"
#include <format>
#include <iostream>
#include <memory>
#include <parser_tree.h>
#include <string>

void ParserTree::addChild(std::unique_ptr<ParserTree> child) {
    this->children.push_back(std::move(child));
}

void ParserTree::printTree(const int& indent) {
    for(int i = 0;i<indent;++i) {
        std::cout << " ";
    }
    std::cout << this->toString() << "\n";
    for(const std::unique_ptr<ParserTree>& child : this->children) {
        child->printTree(indent + 1);
    }
}

ParserRuleTree::ParserRuleTree(std::string name): name(std::move(name)) {}

std::string ParserRuleTree::toString() {
    return this->name;
}

ParserTokenTree::ParserTokenTree(Token token): token(std::move(token)) {}

std::string ParserTokenTree::toString() {
    return std::format("{}: {}", ::toString(this->token.getType()), this->token.getValue());
}