#pragma once

#include <nusantara/parser/parser_rule.h>
#include <nusantara/lexer/token.h>
#include <memory>
#include <string>
#include <vector>

class ParserTree
{
public:
  ParserTree() = default;
  virtual ~ParserTree()
    = default; // destructor (virtual if X is meant to be a base class)
  ParserTree(const ParserTree &) = default;                // copy constructor
  ParserTree &operator=(const ParserTree &) = default;     // copy assignment
  ParserTree(ParserTree &&) noexcept = default;            // move constructor
  ParserTree &operator=(ParserTree &&) noexcept = default; // move assignment
  [[nodiscard]] virtual std::string toString() const = 0;
  void printTree(const int &indent) const;
  void addChild(std::unique_ptr<ParserTree> child);
  [[nodiscard]] const std::vector<std::unique_ptr<ParserTree>> &
  getChildren() const;

private:
  std::vector<std::unique_ptr<ParserTree>> children;
};

class ParserRuleTree : public ParserTree
{
public:
  explicit ParserRuleTree(const ParserRule &rule);
  [[nodiscard]] std::string toString() const override;
  [[nodiscard]] ParserRule getRule() const;

private:
  ParserRule rule;
};

class ParserTokenTree : public ParserTree
{
public:
  explicit ParserTokenTree(Token token);
  [[nodiscard]] std::string toString() const override;
  [[nodiscard]] Token getToken() const;

private:
  Token token;
};