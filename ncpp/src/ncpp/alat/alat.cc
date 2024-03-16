#include "ncpp/alat/alat.h"

ncpp::negatif::negatif(const bool& status): status(status) {}

bool ini_negatif(const std::string& nilai) {
	return nilai.contains('-');
}
