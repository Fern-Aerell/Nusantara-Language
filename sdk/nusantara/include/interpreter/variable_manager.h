#pragma once

#include <string>
#include "interpreter/variable.h"
#include "lexer/token_type.h"
#include "nstd/dinamis.h"
#include "nstd/peta.h"

class VariableManager {
    public:
        explicit VariableManager(
            nstd::peta<std::string, Variable> storage
        );
        Variable& get(const std::string& nama);
        const nstd::dinamis& getNilai(const std::string& nama);
        void set(const std::string& nama, const nstd::dinamis& nilai);
        void create(const TokenType& tipe, const std::string& nama);
        bool containsVariableWithName(const std::string& nama);
    private:
        nstd::peta<std::string, Variable> storage;
};