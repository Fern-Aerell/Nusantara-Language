#pragma once

#include <string>
namespace ncpp {	

	struct negatif {
		explicit negatif(const bool& status);
		bool status;
	};

	bool ini_negatif(const std::string& nilai);

}
