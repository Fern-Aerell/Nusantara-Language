#pragma once

#include "core/core.h"
#include "core/pointer.h"
#include "nstd/tipe_data/benarsalah.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/tipe_data/tipe_data.h"

#define TIPE_DATA_BILANGAN_BULAT long long int
#define TIPE_DATA_BILANGAN_DESIMAL long double

// BILANGAN BULAT MACRO
#define __BILANGAN_BULAT _bilangan_bulat
#define __BILANGAN_BULAT_CONSTRUCTOR(type) \
  explicit _bilangan_bulat(const type& nilai)

// BILANGAN DESIMAL MACRO
#define __BILANGAN_DESIMAL _bilangan_desimal
#define __BILANGAN_DESIMAL_CONSTRUCTOR(type) \
  explicit _bilangan_desimal(const type& nilai)

// BILANGAN MACRO
#define __BILANGAN bilangan
#define __BILANGAN_CONSTRUCTOR(type) bilangan(const type& nilai)
#define __BILANGAN_CONSTRUCTOR_EXPLICIT(type) explicit __BILANGAN_CONSTRUCTOR(type)

#define __DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, nilai_bilangan) \
  __BILANGAN& operator=(const tipe& nilaiX);

#define __DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(tipe) \
  __DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, __BILANGAN_BULAT)
#define __DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(tipe) \
  __DEFINE_BILANGAN_BILANGAN_ASSIGN_OPERATOR(tipe, __BILANGAN_DESIMAL)

namespace nstd {


  class _nilai_bilangan {
    public:
      _nilai_bilangan() = default;
      virtual ~_nilai_bilangan() = default;
      _nilai_bilangan(const _nilai_bilangan&) = default;
      _nilai_bilangan& operator=(const _nilai_bilangan&) = default;
      _nilai_bilangan(_nilai_bilangan&&) noexcept = default;
      _nilai_bilangan& operator=(_nilai_bilangan&&) noexcept = default;
      ND virtual kalimat ubahKeKalimat() const = 0;
  };

  class _bilangan_desimal;

  class _bilangan_bulat: public _nilai_bilangan {
    public:
      __BILANGAN_BULAT_CONSTRUCTOR(int);
      __BILANGAN_BULAT_CONSTRUCTOR(TIPE_DATA_BILANGAN_BULAT);
      ND const TIPE_DATA_BILANGAN_BULAT& ambilNilai() const;
      ND kalimat ubahKeKalimat() const override;
      ND benarsalah isNegatif() const;
      _bilangan_bulat operator~() const;	
	    CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, +, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, +, _bilangan_desimal);
			CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, -, int);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, -, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, -, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, *, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, *, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, /, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, /, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, %, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, %, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, ==, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, ==, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, !=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, !=, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >=, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <=, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, &, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, |, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, ^, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, <<, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_bulat, >>, _bilangan_bulat);

    private:
      TIPE_DATA_BILANGAN_BULAT nilai;

      friend STD ostream& operator<<(
          STD ostream& ost, const _bilangan_bulat& obj
      ) {
        return ost << obj.ubahKeKalimat();
      }
  };

  class _bilangan_desimal: public _nilai_bilangan {
    public:
      __BILANGAN_DESIMAL_CONSTRUCTOR(float);
      __BILANGAN_DESIMAL_CONSTRUCTOR(double);
      __BILANGAN_DESIMAL_CONSTRUCTOR(TIPE_DATA_BILANGAN_DESIMAL);
      ND const TIPE_DATA_BILANGAN_DESIMAL& ambilNilai() const;
      ND kalimat ubahKeKalimat() const override;
      ND benarsalah isNegatif() const; 
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, +, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, +, _bilangan_desimal);
			CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, -, int);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, -, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, -, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, *, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, *, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, /, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, /, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, %, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(_bilangan_desimal, %, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, ==, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, ==, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, !=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, !=, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >=, _bilangan_desimal);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <=, _bilangan_bulat);
    	CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <=, _bilangan_desimal);
    private:
      TIPE_DATA_BILANGAN_DESIMAL nilai;

      friend STD ostream& operator<<(
          STD ostream& ost, const _bilangan_desimal& obj
      ) {
        return ost << obj.ubahKeKalimat();
      }
  };

  class bilangan: public tipe_data {
    public:
      // Constructors
      __BILANGAN_CONSTRUCTOR_EXPLICIT(int);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(TIPE_DATA_BILANGAN_BULAT);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(_bilangan_bulat);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(float);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(double);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(TIPE_DATA_BILANGAN_DESIMAL);
      __BILANGAN_CONSTRUCTOR_EXPLICIT(_bilangan_desimal);
      // Copy constructors
      __BILANGAN_CONSTRUCTOR(bilangan);
      // Move constructor
      bilangan(bilangan&& other) noexcept;

      ND const _bilangan_bulat& ambilNilaiBulat() const;

      ND const _bilangan_desimal& ambilNilaiDesimal() const;

      ND benarsalah isBulat() const;

      ND benarsalah isDesimal() const;

      ND kalimat ubahKeKalimat() const;

      static bilangan ubah(const kalimat& nilai);

      __DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(int);
      __DEFINE_BILANGAN_BILANGAN_BULAT_ASSIGN_OPERATOR(TIPE_DATA_BILANGAN_BULAT
      );
      __DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(float);
      __DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(double);
      __DEFINE_BILANGAN_BILANGAN_DESIMAL_ASSIGN_OPERATOR(
          TIPE_DATA_BILANGAN_DESIMAL
      );
      ND benarsalah isNegatif() const; 
      
      bilangan operator~() const;

      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, -, int);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, +, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, -, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, *, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, /, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, %, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, ==, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, !=, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, >=, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(benarsalah, <=, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, &, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, |, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, ^, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, <<, bilangan);
      CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(bilangan, >>, bilangan);

    private:
      PTR(_nilai_bilangan) nilai;

      friend STD ostream& operator<<(STD ostream& ost, const bilangan& obj) {
        return ost << obj.ubahKeKalimat();
      }
  };
}  // namespace nstd
