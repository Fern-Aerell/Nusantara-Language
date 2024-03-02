#include "nstd/variable/variable.h"
#include "core/core.h"


#define _VARIABLE_CONSTRUCTOR_WITH_TIPE(tipe) NSTD variable::variable(const tipe& nilai): nilai(nilai) {}

NSTD variable::variable() = default;
NSTD variable::variable(const dinamis& nilai): nilai(nilai) {}
const NSTD dinamis& NSTD variable::get() const {
    return this->nilai;
}
