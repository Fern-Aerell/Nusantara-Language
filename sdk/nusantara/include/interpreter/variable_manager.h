#pragma once

#include <string>
#include "interpreter/variable.h"
#include "nstd/dinamis.h"
#include "nstd/peta.h"

class VariableManager {
    public:
        explicit VariableManager(
            nstd::peta<std::string, Variable> storage
        );
        [[nodiscard]] const nstd::dinamis& get(const std::string& nama) const;
        void set(const std::string& nama, const nstd::dinamis& nilai);
        [[nodiscard]] bool containsVariable(const std::string& nama) const;
    private:
        nstd::peta<std::string, Variable> storage;
};