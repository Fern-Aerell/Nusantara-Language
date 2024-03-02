#include "core/core.h"
#include "core/pointer.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/variable/variable.h"
#include "nstd/tipe_data/identifikasi.h"

NSTD identifikasi::identifikasi(kalimat identifier, const variable_manager& var_manager): identifier(STD move(identifier)), var_manager(MSPTR(variable_manager, var_manager)) {}

const NSTD dinamis& NSTD identifikasi::get() const {
  return this->var_manager->get(this->identifier).get();
}

void NSTD identifikasi::set(const dinamis& nilai) {
  return this->var_manager->define(this->identifier, variable(nilai));
}