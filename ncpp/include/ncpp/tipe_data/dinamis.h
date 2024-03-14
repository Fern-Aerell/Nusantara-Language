#pragma once

#include <any>
#include <memory>
#include <stdexcept>
#include <string>
#include "ncpp/tipe_data/teks.h"

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

      template<typename Tipe>
      static bool ini(const dinamis& nilai) {
        if(auto* ptr = std::any_cast<Tipe>(&nilai.nilai)) {
          return true;
        }
        return false;
      }

      template<typename Tipe>
      bool ini() {
        return dinamis::ini<Tipe>(*this);
      }

      template<typename Tipe>
      static Tipe& sebagai(dinamis& nilai) {
        if(auto* ptr = std::any_cast<Tipe>(&nilai.nilai)) {
          return *ptr;
        }
        throw std::runtime_error(teks("Nilai dinamis bukanlah sebuah '{}'.", typeid(Tipe).name()).ubah_ke_string());
      }

      template<typename Tipe>
      Tipe& sebagai() {
        return dinamis::sebagai<Tipe>(*this);
      }

      template<typename Tipe>
      static Tipe sebagai(const dinamis& nilai) {
        if(auto* ptr = std::any_cast<Tipe>(&nilai.nilai)) {
          return *ptr;
        }
        throw std::runtime_error(teks("Nilai dinamis bukanlah sebuah '{}'.", typeid(Tipe).name()).ubah_ke_string());
      }

      template<typename Tipe>
      [[nodiscard]] static std::unique_ptr<std::string> ubah_ke_string(const dinamis& nilai) {
        if(dinamis::ini<Tipe>(nilai)) {
          std::ostringstream stream;
          stream << dinamis::sebagai<Tipe>(nilai);
          return std::make_unique<std::string>(stream.str());
        }
        return nullptr;
      }

      template<typename Tipe>
      [[nodiscard]] std::unique_ptr<std::string> ubah_ke_string() const {
        return dinamis::ubah_ke_string<Tipe>(*this);
      }

      [[nodiscard]] std::string ubah_ke_string() const;

		private:
			std::any nilai;

      friend std::ostream& operator<<(std::ostream& ost, const dinamis& data) {
        ost << data.ubah_ke_string();
        return ost;
      }

    protected:
	};
}
