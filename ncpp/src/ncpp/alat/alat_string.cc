#include "ncpp/alat/alat_string.h"
#include <mpfr.h>
#include <format>
#include <string>

std::string ncpp::ubah_ke_string(const mpz_t& nilai, const int& basis) {
	size_t bufferSize = mpz_sizeinbase(nilai, basis) + 2;
	char* buffer = new char[bufferSize];      
	mpz_get_str(buffer, basis, nilai);
	std::string result(buffer);
	delete[] buffer;
	return result;
}
std::string ncpp::ubah_ke_string(const mpfr_t& nilai, const std::string& pattern, const bool& pemisah_koma) {
	int buffer_size = mpfr_snprintf(nullptr, 0, pattern.c_str(), nilai);
	std::string result(buffer_size, '\0');
	mpfr_snprintf(&result[0], buffer_size + 1, pattern.c_str(), nilai);
	if(pemisah_koma) {
		size_t pos = result.find('.');
		if (pos != std::string::npos) {
			result[pos] = ',';
		}
	}
	return result;
}
std::string ncpp::ubah_ke_string_tetap(const mpfr_t& nilai, const int& presisi, const bool& pemisah_koma) {
	return ubah_ke_string(nilai, std::format("%.{}Rf", presisi), pemisah_koma);
}
std::string ncpp::ubah_ke_string_presisi(const mpfr_t& nilai, const int& presisi, const bool& pemisah_koma) {
	return ubah_ke_string(nilai, std::format("%.{}Rg", presisi), pemisah_koma);
}
