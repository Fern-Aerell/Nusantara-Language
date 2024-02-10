#pragma once

#include <nusantara/core/core.h>
#include <nusantara/lexer/token.h>
#include <nusantara/parser/parser_tree.h>

#include <memory>

#include "nusantara/visitor/context/context.h"

class OperatorPerbandinganContext : public Context {
 public:
  explicit OperatorPerbandinganContext(nstd::bisa_kosong<Token> simbolOp);
  static OperatorPerbandinganContext generate(
      const std::vector<std::unique_ptr<ParserTree>> &children);
  [[nodiscard]] nstd::bisa_kosong<Token> getSimbolOp() const;

 private:
  nstd::bisa_kosong<Token> simbolOp;
};