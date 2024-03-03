#pragma once

#include "core/core.h"
#include "core/pointer.h"
#include "core/string.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/dinamis.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"
#include "nstd/variable/variable.h"

#define __IDENTIFIKASI_DECLARE_SET_FUNCTION(tipe_data) void set(const tipe_data& nilai) const

namespace nstd {

    class identifikasi: public tipe_data {
        public:
            identifikasi(const SPTR(variable_manager)& vars, STR identifier);
            identifikasi(const SPTR(variable_manager)& vars, const kalimat& identifier);
            ND const variable& get() const;
            ND kalimat ubahKeKalimat() const;
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(bilangan);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(kalimat);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(benarsalah);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(daftar);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(peta);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(dinamis);
            __IDENTIFIKASI_DECLARE_SET_FUNCTION(identifikasi);
            bilangan operator+(const bilangan& nilaiX) const;
        private:
            SPTR(variable_manager) vars;
            STR identifier;

            friend std::ostream& operator<<(std::ostream& ost, const identifikasi& obj) {
                return ost << obj.get();
            }
    };

}