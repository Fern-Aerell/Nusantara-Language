#include "lexer.h"
#include "token.h"
#include <string>

Lexer::Lexer(std::string content) : content(std::move(content))
{
  this->tokenizer();
}

void Lexer::tokenizer() {}
