#pragma once

#include "core/core.h"
#include "core/string.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/variable/variable.h"
#include <map>

#define __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(tipe_data) void define(const STR& nama, const tipe_data& nilai)

namespace nstd {

    class variable_manager {
        public:
            variable_manager();
            explicit variable_manager(STD map<STR, variable> data);
            void declare(const variable_data_type& tipe, const STR& nama);
            void define(const std ::string& nama);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(bilangan);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(kalimat);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(benarsalah);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(daftar);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(peta);
            __VARIABLE_MANAGER_DECLARE_DEFINE_FUNCTION(dinamis);
            const variable& get(const STR& nama);
        private:
            STD map<STR, variable> data;
    };

}