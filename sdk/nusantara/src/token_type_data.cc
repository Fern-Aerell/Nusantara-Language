#include "token_type.h"
#include <string>
#include <token_type_data.h>

TokenTypeData::TokenTypeData(std::string name, const TokenType &type,
                             std::string pattern)
    : name(std::move(name)), type(type), pattern(std::move(pattern))
{}

const std::string &TokenTypeData::getName() { return this->name; }

const TokenType &TokenTypeData::getType() { return this->type; }

const std::string &TokenTypeData::getPattern() { return this->pattern; }
