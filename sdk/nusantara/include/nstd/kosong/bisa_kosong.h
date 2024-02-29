#pragma once

#include <memory>
#include <ostream>

#include "core/error.h"

#define __BISA_KOSONG_ERROR_KOSONG_VALUE \
  RTERROR("nilai kosong tidak dapat diambil.")

namespace nstd {

  template<typename tipe>
  class bisa_kosong {
    public:
      bisa_kosong(): nilai(nullptr) {}

      explicit bisa_kosong(const tipe& nilai):
          nilai(std::make_unique<tipe>(nilai)) {}

      [[nodiscard]] bool kosong() const { return this->nilai == nullptr; }

      [[nodiscard]] bool tidak_kosong() const { return this->nilai != nullptr; }

      tipe ambil_nilai() const {
        if(this->kosong()) { throw __BISA_KOSONG_ERROR_KOSONG_VALUE; }
        return *this->nilai.get();
      }

      void kosongkan() { this->nilai = nullptr; }

      friend std::ostream& operator<<(
          std::ostream& ost, const bisa_kosong<tipe>& obj
      ) {
        return ost << obj.ambil_nilai();
      }

      bisa_kosong<tipe>& operator=(const tipe& nilai) {
        this->nilai = nilai;
        return *this;
      }

    private:
      std::unique_ptr<tipe> nilai;
  };
}  // namespace nstd
