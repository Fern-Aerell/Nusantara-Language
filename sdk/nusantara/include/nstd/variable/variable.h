#pragma once

#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/dinamis.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"

#define __VARIABLE_CONSTRUCTOR(tipe_data) explicit variable(tipe_data nilai)

namespace nstd {

	class variable {
		public:
			__VARIABLE_CONSTRUCTOR(bilangan);
			__VARIABLE_CONSTRUCTOR(kalimat);
			__VARIABLE_CONSTRUCTOR(benarsalah);
			__VARIABLE_CONSTRUCTOR(daftar);
			__VARIABLE_CONSTRUCTOR(peta);
			__VARIABLE_CONSTRUCTOR(dinamis);

		private:
			PTR(tipe_data) nilai;
	};

}
