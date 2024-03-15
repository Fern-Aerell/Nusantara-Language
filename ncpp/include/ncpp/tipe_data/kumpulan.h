#pragma once

#include <deque>
#include <list>
#include <map>
#include <optional>
#include <set>
#include <unordered_map>
#include <variant>
#include <vector>
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"

namespace ncpp {

	struct kumpulan_configurasi {
		kumpulan_configurasi(
				const std::optional<bilangan_bulat>& min,
				const std::optional<bilangan_bulat>& maks,
				const bool& berurutan,
				const bool& duplikasi
		):
			min(min),
			maks(maks),
			berurutan(berurutan),
			duplikasi(duplikasi)
		{}
		std::optional<bilangan_bulat> min;
		std::optional<bilangan_bulat> maks;
		bool berurutan = true;
		bool duplikasi = false;
	};

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
			kumpulan_configurasi config;
			
	};	

}
