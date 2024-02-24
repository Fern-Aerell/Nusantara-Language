#pragma once

#include "lexer/token_type.h"
#include "nstd/dinamis.h"

class Variable {
    public:
        Variable() = default;
        Variable(
            const TokenType& tipe,
            nstd::dinamis nilai
        );
        [[nodiscard]] const nstd::dinamis& getNilai() const;
        void setNilai(const nstd::dinamis& nilai);
    private:
        TokenType tipe;
        nstd::dinamis nilai;
};