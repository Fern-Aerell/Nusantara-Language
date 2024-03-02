#pragma once

#include "core/core.h"
#include "core/pointer.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"
#include "nstd/tipe_data/dinamis.h"

namespace nstd {

    class identifikasi: public tipe_data {
      public:
        explicit identifikasi(kalimat identifier, const variable_manager& var_manager);
        identifikasi& operator=(const int& nilaiX);
        ND const dinamis& get() const;
        void set(const dinamis& nilai);
      private:
        SPTR(variable_manager) var_manager;
        kalimat identifier;
        friend STD ostream& operator<<(STD ostream& ost, const identifikasi& obj) {
            ost << obj.get();
            return ost;
        }
    };

}