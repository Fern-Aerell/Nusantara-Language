#include "ncpp/alat/alat_mpfr.h"
#include <gtest/gtest.h>
#include <mpfr.h>

TEST(ALAT_MPFR_TEST, Fungsi_Mpfr_Cmp_Dengan_Toleransi) {
	{
		mpfr_t val1, val2;
		mpfr_init_set_d(val1, 1.23456789012345, MPFR_RNDN);
		mpfr_init_set_d(val2, 1.23456789012346, MPFR_RNDN);
		double tolerance = 1e-6;
		EXPECT_EQ(ncpp::mpfr_cmp_with_tolerance(val1, val2, tolerance), 0);
		mpfr_clear(val1);
		mpfr_clear(val2);
	}
	{
		mpfr_t val1, val2;
		mpfr_init_set_d(val1, 2.1, MPFR_RNDN);
		mpfr_init_set_d(val2, 2.0, MPFR_RNDN);
		double tolerance = 1e-6;
		EXPECT_EQ(ncpp::mpfr_cmp_with_tolerance(val1, val2, tolerance), 1);
		mpfr_clear(val1);
		mpfr_clear(val2);
	}
	{
		mpfr_t val1, val2;
		mpfr_init_set_d(val1, 1.0, MPFR_RNDN);
		mpfr_init_set_d(val2, 2.0, MPFR_RNDN);
		double tolerance = 1e-6;
		EXPECT_EQ(ncpp::mpfr_cmp_with_tolerance(val1, val2, tolerance), -1);
		mpfr_clear(val1);
		mpfr_clear(val2);
	}
}