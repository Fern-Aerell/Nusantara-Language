#pragma once

#include <format>
#include <memory>

#include "nstd/tipe_data/peta.h"
#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/daftar.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define __DINAMIS_VALUE this->nilai

#define __DEFINE_DINAMIS_IS_FUNCTION(value)                \
  [[nodiscard]] benarsalah is_##value() const {     \
    if(PTR_CAST(__DINAMIS_VALUE, value)) { return BENAR; } \
    return SALAH;                                          \
  }

namespace nstd {
  class nilai_dinamis_tidak_valid_exception: public std::exception {
    public:
      [[nodiscard]] const char* what() const noexcept override {
        return "nilai dinamis tidak valid.";
      }
  };

  template<typename T>
  class nilai_dinamis_bukan_sebuah_exception: public std::exception {
    public:
      nilai_dinamis_bukan_sebuah_exception() {
        this->msg =
            std::format("dinamis bukan sebuah '{}'.", typeid(T).name()).c_str();
      }

      [[nodiscard]] const char* what() const noexcept override { return msg; }

    private:
      const char* msg{};
  };

  class dinamis {
    public:
      dinamis(): nilai(nullptr) {}

      explicit dinamis(std::unique_ptr<tipe_data> nilai):
          nilai(std::move(nilai)) {}

      [[nodiscard]] bool kosong() const { return this->nilai == nullptr; }

      [[nodiscard]] bool tidakKosong() const { return !this->kosong(); }

      [[nodiscard]] kalimat ubahKeKalimat() const {
        if(PTR_CAST(this->nilai, bilangan)) {
          return cast_result_ptr->ubahKeKalimat();
        } else if(PTR_CAST(this->nilai, kalimat)) {
          return *cast_result_ptr;
        } else if(PTR_CAST(this->nilai, benarsalah)) {
          return cast_result_ptr->ubahKeKalimat();
        } else if(PTR_CAST(this->nilai, daftar)) {
          return cast_result_ptr->ubahKeKalimat();
        } else if(PTR_CAST(this->nilai, peta)) {
          return cast_result_ptr->ubahKeKalimat();
        }
        throw nilai_dinamis_tidak_valid_exception();
      }

      __DEFINE_DINAMIS_IS_FUNCTION(bilangan);
      __DEFINE_DINAMIS_IS_FUNCTION(kalimat);
      __DEFINE_DINAMIS_IS_FUNCTION(benarsalah);
      __DEFINE_DINAMIS_IS_FUNCTION(daftar);
      __DEFINE_DINAMIS_IS_FUNCTION(peta);

    private:
      std::unique_ptr<tipe_data> nilai;

      template<class T>
      [[nodiscard]] benarsalah is() const {
        if(const auto* ptr = dynamic_cast<T*>(this->nilai.get())) {
          return BENAR;
        }
        return SALAH;
      }

      template<class T>
      [[nodiscard]] T ambilNilai() const {
        if(const auto* ptr = dynamic_cast<T*>(this->nilai.get())) {
          return ptr;
        }
        throw nilai_dinamis_bukan_sebuah_exception<T>();
      }

      friend std::ostream& operator<<(std::ostream& ost, const dinamis& obj) {
        return ost << obj.ubahKeKalimat();
      }
  };
}  // namespace nstd
