#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace nstd {

  template<typename Tipe>
  using daftar = std::vector<Tipe>;

  template<typename Tipe>
  inline bool contains(const daftar<Tipe>& daftar, const Tipe& nilai) {
    return std::find(daftar.begin(), daftar.end(), nilai) != daftar.end();
  }

  template<typename Tipe>
  inline bool kosong(const daftar<Tipe>& daftar) {
    return daftar.size() == 0;
  }

  template<typename Tipe>
  inline bool tidakKosong(const daftar<Tipe>& daftar) {
    return daftar.size() != 0;
  }

  template<typename Tipe>
  inline std::string toString(const daftar<Tipe>& daftar) {
    std::ostringstream stream;
    int index = 0;
    for(const Tipe& child : daftar) {
      if(index == 0) {
        stream << "["
               << "\n";
      }
      stream << " [" << index << "]=" << child;
      if(index < (daftar.size() - 1)) {
        stream << ","
               << "\n";
      } else {
        stream << "\n"
               << "]";
      }
      ++index;
    }
    return stream.str();
  }
}  // namespace nstd
