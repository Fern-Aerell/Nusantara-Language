#include "nstd/manager/variable_manager.h"
#include "core/core.h"
#include "core/error.h"
#include "core/format.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/variable/variable.h"

#define _VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(tipe_data) void NSTD variable_manager::define(const STR& nama, const tipe_data& nilai) {\
    if(!this->data.contains(nama)) {\
        throw RTERROR(FMT("Variable '{}' belum dibuat.", nama));\
    }\
    this->data[nama] = nilai;\
}

NSTD variable_manager::variable_manager(): data({}) {}

NSTD variable_manager::variable_manager(STD map<STR, variable> data): data(STD move(data)) {}

void NSTD variable_manager::declare(const variable_data_type& tipe, const STR& nama) {
    if(this->data.contains(nama)) {
        throw RTERROR(FMT("Variable '{}' sudah dibuat.", nama));
    }
    this->data[nama] = variable(tipe);
}

void NSTD variable_manager::define(const std ::string& nama) {
    if(!this->data.contains(nama)) {
        throw RTERROR(FMT("Variable '{}' belum dibuat.", nama));
    }
    this->data[nama] = variable(this->data[nama].getTipe());
}
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(bilangan)
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(kalimat)
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(benarsalah)
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(daftar)
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(peta)
_VARIABLE_MANAGER_DEFINE_DEFINE_FUNCTION(dinamis)

const NSTD variable& NSTD variable_manager::get(const STR& nama) {
    if(!this->data.contains(nama)) {
        throw RTERROR(FMT("Variable '{}' belum dibuat.", nama));
    }
    return this->data[nama];
}