#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace ncpp {

	class konsol {
		public:
			explicit konsol(const bool cout = false): cout(cout) {}
			template<typename Tipe>
			void cetak(const Tipe& tipe) {
				this->stream << tipe;
				if(cout) {std::cout << tipe;}
			}	
			template<typename Tipe>
			void cetak_baris_baru(const Tipe& tipe) {
				this->stream << tipe << "\n";
				if(cout) {std::cout << tipe << "\n";}
			}	
			void bersihkan() {
				this->stream.str("");
			}
			std::string isi() {
				return this->stream.str();
			}	
		private:
			bool cout;
			std::ostringstream stream;	
	};
}
