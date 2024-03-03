#include "nstd/tipe_data/identifikasi.h"
#include "core/core.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"

#define _IDENTIFIKASI_DEFINE_SET_FUNCTION(tipe_data) void NSTD identifikasi::set(const tipe_data& nilai) const {this->vars->define(this->identifier, nilai);}

NSTD identifikasi::identifikasi(const SPTR(variable_manager)& vars, STR identifier): vars(vars), identifier(STD move(identifier)) {}
NSTD identifikasi::identifikasi(const SPTR(variable_manager)& vars, const kalimat& identifier): vars(vars), identifier(identifier.ubahKeString()) {}

const NSTD variable& NSTD identifikasi::get() const {
    return this->vars->get(this->identifier);
}

ND NSTD kalimat NSTD identifikasi::ubahKeKalimat() const {
    return this->get().ubahKeKalimat();
}

_IDENTIFIKASI_DEFINE_SET_FUNCTION(bilangan)
_IDENTIFIKASI_DEFINE_SET_FUNCTION(kalimat)
_IDENTIFIKASI_DEFINE_SET_FUNCTION(benarsalah)
_IDENTIFIKASI_DEFINE_SET_FUNCTION(daftar)
_IDENTIFIKASI_DEFINE_SET_FUNCTION(peta)
_IDENTIFIKASI_DEFINE_SET_FUNCTION(dinamis)
void NSTD identifikasi::set(const identifikasi& nilai) const {
    if(nilai.get().is_bilangan()) {
        this->vars->define(this->identifier, nilai.get().get_bilangan());
    }else if(nilai.get().is_kalimat()) {
        this->vars->define(this->identifier, nilai.get().get_kalimat());
    }else if(nilai.get().is_benarsalah()) {
        this->vars->define(this->identifier, nilai.get().get_benarsalah());
    }else if(nilai.get().is_daftar()) {
        this->vars->define(this->identifier, nilai.get().get_daftar());
    }else if(nilai.get().is_peta()) {
        this->vars->define(this->identifier, nilai.get().get_peta());
    }else if(nilai.get().is_dinamis()) {
        this->vars->define(this->identifier, nilai.get().get_dinamis());
    }else{
        this->vars->define(this->identifier);
    }
}

NSTD bilangan NSTD identifikasi::operator+(const bilangan& nilaiX) const {
    return this->get() + nilaiX;
}
