#pragma once

#include "lexer/token_type.h"
#include "nstd/dinamis.h"

class Variable {
    public:
        Variable(
            const TokenType& tipe,
            nstd::dinamis nilai
        );
        [[nodiscard]] const nstd::dinamis& get() const;
        void set(const nstd::dinamis& nilai);
    private:
        TokenType tipe;
        nstd::dinamis nilai;
};