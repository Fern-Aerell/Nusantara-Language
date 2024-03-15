#include "ncpp/alat/alat_string.h"
#include <gmp.h>
#include <gtest/gtest.h>
#include <mpfr.h>
#include <ncpp/ncpp.h>
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"

TEST(ALAT_STRING_TEST, Mpt_Z_Ubah_Ke_String) {
	ncpp::konsol myKonsol;
	mpz_t var;
	mpz_init_set_str(var, "15", 10);
	myKonsol.cetak(ncpp::ubah_ke_string(var, 10));
	EXPECT_EQ(myKonsol.isi(), "15");
	mpz_clear(var);
}

TEST(ALAT_STRING_TEST, Mpfr_Z_Ubah_Ke_String) {
	ncpp::konsol myKonsol;
	mpfr_t var;
	mpfr_init_set_str(var, "5.4", 10, ncpp::_bilangan_desimal_::pembulatan);
	myKonsol.cetak(ncpp::ubah_ke_string(var, "%.15Rg"));
	EXPECT_EQ(myKonsol.isi(), "5.4");
	mpfr_clear(var);
}

TEST(ALAT_STRING_TEST, Mpfr_Z_Ubah_Ke_String_Tetap) {
	ncpp::konsol myKonsol;
	mpfr_t var;
	mpfr_init_set_str(var, "5.43", 10, ncpp::_bilangan_desimal_::pembulatan);
	myKonsol.cetak(ncpp::ubah_ke_string_tetap(var, 1));
	EXPECT_EQ(myKonsol.isi(), "5.4");
	mpfr_clear(var);
}

TEST(ALAT_STRING_TEST, Mpfr_Z_Ubah_Ke_String_Presisi) {
	ncpp::konsol myKonsol;
	mpfr_t var;
	mpfr_init_set_str(var, "5.43", 10, ncpp::_bilangan_desimal_::pembulatan);
	myKonsol.cetak(ncpp::ubah_ke_string_presisi(var, 1));
	EXPECT_EQ(myKonsol.isi(), "5");
	mpfr_clear(var);
}
