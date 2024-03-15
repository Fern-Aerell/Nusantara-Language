#pragma once

#include <deque>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <variant>
#include <vector>

namespace ncpp {

	template<typename Kata_Kunci, typename Nilai>
	class kumpulan {
		public:
			// Constructor
		private:
			// Daftar
			// vector : urutan & duplikasi
			// list : urutan & noduplikasi
			// deque : nourutan & duplikasi
			// set : nourutan & noduplikasi
			//
			// Peta
			// multimap : urutan & duplikasi
			// map : urutan & noduplikasi
			// unordered_multimap : nourutan & duplikasi
			// unordered_map : nourutan & noduplikasi
			std::variant<
				std::vector<Nilai>,
				std::list<Nilai>,
				std::deque<Nilai>,
				std::set<Nilai>,
				std::multimap<Kata_Kunci, Nilai>,
				std::map<Kata_Kunci, Nilai>,
				std::unordered_multimap<Kata_Kunci, Nilai>,
				std::unordered_map<Kata_Kunci, Nilai>
			> nilai;
			
	};	

}
