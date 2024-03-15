#pragma once

#include <gmp.h>
#include <mpfr.h>
#include <string>

namespace ncpp {
	
	std::string ubah_ke_string(const mpz_t& nilai, const int& basis);

	std::string ubah_ke_string(const mpfr_t& nilai, const std::string& pattern, const bool& pemisah_koma = false);

	std::string ubah_ke_string_tetap(const mpfr_t& nilai, const int& presisi, const bool& pemisah_koma = false);

	std::string ubah_ke_string_presisi(const mpfr_t& nilai, const int& presisi, const bool& pemisah_koma = false);

}
