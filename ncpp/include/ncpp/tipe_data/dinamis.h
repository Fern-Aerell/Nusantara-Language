#pragma once

#include <any>

namespace ncpp {
	class dinamis {
		public:
			// Constructors
			dinamis();
			explicit dinamis(std::any nilai);
			// Destructor
      ~dinamis();
      // Copy constructor
      dinamis(const dinamis& other);
      // Copy assignment operator
      dinamis& operator=(const dinamis& other);
      // Move constructor
      dinamis(dinamis&& other) noexcept;
      // Move assignment operator
      dinamis& operator=(dinamis&& other) noexcept;
		private:
			std::any nilai;
	};
}
