#include <map>
#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/variable/variable.h"

NSTD variable_manager::variable_manager(): data({}) {}
NSTD variable_manager::variable_manager(const std::map<kalimat, variable>& data): data(data) {}
void NSTD variable_manager::declare(const kalimat& name) {
    this->data[name] = variable();
}
void NSTD variable_manager::define(const kalimat& name, const variable& var) {
    if(!this->data.contains(name)) {
        throw RTERROR(FMT("Variable '{}' belum dibuat.", name.ubahKeString()));
    }
    this->data[name] = var;
}
const NSTD variable& NSTD variable_manager::get(const kalimat& name) {
    if(!this->data.contains(name)) {
        throw RTERROR(FMT("Variable '{}' belum dibuat.", name.ubahKeString()));
    }
    return this->data[name];
}