#include <nusantara/lexer/token_type.h>
#include <nusantara/lexer/token_type_data.h>

#include <string>

TokenTypeData::TokenTypeData(std::string name, const TokenType &type,
                             std::string pattern)
    : name(std::move(name)), type(type), pattern(std::move(pattern)) {}

std::string TokenTypeData::getName() const { return this->name; }

TokenType TokenTypeData::getType() const { return this->type; }

std::string TokenTypeData::getPattern() const { return this->pattern; }
