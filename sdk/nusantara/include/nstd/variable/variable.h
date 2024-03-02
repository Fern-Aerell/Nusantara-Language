#pragma once

#include "core/core.h"
#include "nstd/tipe_data/dinamis.h"

#define __VARIABLE_CONSTRUCTOR_WITH_TIPE(tipe) explicit variable(const tipe& nilai)

namespace nstd {
    class variable {
        public:
            variable();
            __VARIABLE_CONSTRUCTOR_WITH_TIPE(dinamis);
            ND const dinamis& get()const;
        private:
            dinamis nilai;
    };
}