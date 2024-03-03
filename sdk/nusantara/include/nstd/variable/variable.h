#pragma once

#include "core/core.h"
#include "core/pointer.h"
#include "core/string.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/dinamis.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/peta.h"
#include "nstd/tipe_data/tipe_data.h"

#define __VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(tipe_data) variable& operator=(const tipe_data& other)

#define __VARIABLE_DECLARE_IS_FUNCTION(tipe_data) bool is_##tipe_data() const

#define __VARIABLE_DECLARE_GET_FUNCTION(tipe_data) const tipe_data& get_##tipe_data() const

namespace nstd {

	enum class variable_data_type {
		bilangan,
		kalimat,
		benarsalah,
		daftar,
		peta,
		dinamis
	};

	STR toString(const variable_data_type& tipe);

	class variable {
		public:
			// Constructors
			variable();
			explicit variable(const variable_data_type& tipe);
			// Copy constructor
			variable(const variable& other);
			// Copy assignment operator
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(variable);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(bilangan);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(kalimat);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(benarsalah);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(daftar);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(peta);
    		__VARIABLE_DECLARE_COPY_ASSIGMENT_OPERATOR(dinamis);

			__VARIABLE_DECLARE_IS_FUNCTION(bilangan);
			__VARIABLE_DECLARE_IS_FUNCTION(kalimat);
			__VARIABLE_DECLARE_IS_FUNCTION(benarsalah);
			__VARIABLE_DECLARE_IS_FUNCTION(daftar);
			__VARIABLE_DECLARE_IS_FUNCTION(peta);
			__VARIABLE_DECLARE_IS_FUNCTION(dinamis);

			__VARIABLE_DECLARE_GET_FUNCTION(bilangan);
			__VARIABLE_DECLARE_GET_FUNCTION(kalimat);
			__VARIABLE_DECLARE_GET_FUNCTION(benarsalah);
			__VARIABLE_DECLARE_GET_FUNCTION(daftar);
			__VARIABLE_DECLARE_GET_FUNCTION(peta);
			__VARIABLE_DECLARE_GET_FUNCTION(dinamis);

			ND const variable_data_type& getTipe() const;

			ND kalimat ubahKeKalimat() const;

			bilangan operator+(const bilangan& nilaiX) const;

		private:
			variable_data_type tipe;
			PTR(tipe_data) nilai;

			friend STD ostream& operator<<(STD ostream& ost, const variable& obj) {
				if(obj.is_bilangan()) {
					ost << obj.get_bilangan();
				}else if(obj.is_kalimat()) {
					ost << obj.get_kalimat();
				}else if(obj.is_benarsalah()) {
					ost << obj.get_benarsalah();
				}else if(obj.is_daftar()) {
					ost << obj.get_daftar();
				}else if(obj.is_peta()) {
					ost << obj.get_peta();
				}else if(obj.is_dinamis()) {
					ost << obj.get_dinamis();
				}else{
					ost << "kosong";
				}
				return ost;
			}
	};

}
