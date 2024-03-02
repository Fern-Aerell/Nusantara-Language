#pragma once

#include <map>
#include "nstd/tipe_data/kalimat.h"

namespace nstd {

    class variable;

    class variable_manager {
        public:
            variable_manager();
            explicit variable_manager(const std::map<kalimat, variable>& data);
            void declare(const kalimat& name);
            void define(const kalimat& name, const variable& var);
            const variable& get(const kalimat& name);
        private:
            std::map<kalimat, variable> data;
    };

}