#include <gmp.h>
#include <gtest/gtest.h>
#include <mpfr.h>
#include <ncpp/ncpp.h>
#include <regex>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/teks.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"

TEST(BILANGAN_DESIMAL_TEST, Constructors) {
    ncpp::konsol myKonsol;
    {
        ncpp::bilangan_desimal var1;
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "0");
        myKonsol.bersihkan();
    }
    {
        ncpp::bilangan_desimal var1("-50,5");
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "-50,5");
        myKonsol.bersihkan();
    }
}

TEST(BILANGAN_DESIMAL_TEST, Copy_constructor) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_desimal var1("23,2");
    ncpp::bilangan_desimal var2(var1);
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "23,2\n23,2\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_DESIMAL_TEST, Copy_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_desimal var1("25,23");
    ncpp::bilangan_desimal var2 = var1;
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "25,23\n25,23\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_DESIMAL_TEST, Move_Constructor) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_desimal var1("11,4");
    ncpp::bilangan_desimal var2(std::move(var1));
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "11,4\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_DESIMAL_TEST, Move_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_desimal var1("211,12");
    ncpp::bilangan_desimal var2 = std::move(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "211,12\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_DESIMAL_TEST, Static_Variable_Basis) {
    EXPECT_EQ(ncpp::bilangan_desimal::basis, 10);
}

TEST(BILANGAN_DESIMAL_TEST, Static_Variable_Presisi_Teks_Bawaan) {
    EXPECT_EQ(ncpp::bilangan_desimal::presisi_teks_bawaan, 15);
}

TEST(BILANGAN_DESIMAL_TEST, Static_Fungsi_Pattern) {
    EXPECT_TRUE(std::regex_match("10,2", ncpp::bilangan_desimal::pattern()));
    EXPECT_TRUE(std::regex_match("-10,4", ncpp::bilangan_desimal::pattern()));
    EXPECT_FALSE(std::regex_match("10", ncpp::bilangan_desimal::pattern()));
}

TEST(BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_Teks) {
    ncpp::bilangan_desimal var1("54,2");
    EXPECT_EQ(var1.ubah_ke_teks(), ncpp::teks("54,2"));
}

TEST(BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_Teks_Tetap) {
    ncpp::bilangan_desimal var1("54,22");
    EXPECT_EQ(var1.ubah_ke_teks_tetap(1), ncpp::teks("54,2"));
}

TEST(BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_Teks_Presisi) {
    ncpp::bilangan_desimal var1("10,5");
    EXPECT_EQ(var1.ubah_ke_teks_presisi(2), ncpp::teks("10"));
}

TEST(BILANGAN_DESIMAL_TEST, Fungsi_Ambil) {
    ncpp::bilangan_desimal var1("32,2");
    mpfr_t var2;
    mpfr_init_set_str(var2, "32.2", 10, ncpp::bilangan_desimal::pembulatan);
    EXPECT_TRUE(mpfr_equal_p(var1.ambil(), var2) != 0);
    mpfr_clear(var2);
}

TEST(BILANGAN_DESIMAL_TEST, Static_Fungsi_Ubah) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_bulat var1("10");
    ncpp::bilangan_desimal var2(ncpp::bilangan_desimal::ubah(var1));
    myKonsol.cetak(var2);
    EXPECT_EQ(myKonsol.isi(), "10");
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Penjumlahan) {
	{
        ncpp::bilangan_desimal var1("5,5");
	    ncpp::bilangan_desimal var2("10,5");
        EXPECT_EQ(var1 + var2, ncpp::bilangan_desimal("16"));
    }
    {
        ncpp::bilangan_desimal var1("2,5");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 + var2, ncpp::bilangan_desimal("4,5"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Pengurangan) {
	{
        ncpp::bilangan_desimal var1("5,5");
	    ncpp::bilangan_desimal var2("10,5");
        EXPECT_EQ(var1 - var2, ncpp::bilangan_desimal("-5"));
    }
    {
        ncpp::bilangan_desimal var1("2,5");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 - var2, ncpp::bilangan_desimal("0,5"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Perkalian) {
	{
        ncpp::bilangan_desimal var1("5,5");
	    ncpp::bilangan_desimal var2("10,5");
        EXPECT_EQ(var1 * var2, ncpp::bilangan_desimal("57,75"));
    }
    {
        ncpp::bilangan_desimal var1("2,5");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 * var2, ncpp::bilangan_desimal("5"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Pembagian) {
	{
        ncpp::bilangan_desimal var1("5,5");
	    ncpp::bilangan_desimal var2("10,5");
        EXPECT_EQ(var1 / var2, ncpp::bilangan_desimal("0,5238095238095238"));
    }
    {
        ncpp::bilangan_desimal var1("2,5");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 / var2, ncpp::bilangan_desimal("1,25"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Sisa_Pembagian) {
	{
        ncpp::bilangan_desimal var1("5,5");
	    ncpp::bilangan_desimal var2("10,5");
        EXPECT_EQ(var1 % var2, ncpp::bilangan_desimal("5,5"));
    }
    {
        ncpp::bilangan_desimal var1("2,5");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 % var2, ncpp::bilangan_desimal("0,5"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Pre_Increment) {
	{
        ncpp::bilangan_desimal var1("5,2");
        EXPECT_EQ(++var1, ncpp::bilangan_desimal("6,2"));
    }
    {
        ncpp::bilangan_desimal var1("-10,10");
        EXPECT_EQ(++var1, ncpp::bilangan_desimal("-9,1"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Post_Increment) {
	{
        ncpp::bilangan_desimal var1("2,4");
        EXPECT_EQ(var1++, ncpp::bilangan_desimal("2,4"));
        EXPECT_EQ(var1, ncpp::bilangan_desimal("3,4"));
    }
    {
        ncpp::bilangan_desimal var1("-18,3");
        EXPECT_EQ(var1++, ncpp::bilangan_desimal("-18,3"));
        EXPECT_EQ(var1, ncpp::bilangan_desimal("-17,3"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Pre_Decrement) {
	{
        ncpp::bilangan_desimal var1("21,2");
        EXPECT_EQ(--var1, ncpp::bilangan_desimal("20,2"));
    }
    {
        ncpp::bilangan_desimal var1("-1,5");
        EXPECT_EQ(--var1, ncpp::bilangan_desimal("-2,5"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Post_Decrement) {
	{
        ncpp::bilangan_desimal var1("5,15");
        EXPECT_EQ(var1--, ncpp::bilangan_desimal("5,15"));
        EXPECT_EQ(var1, ncpp::bilangan_desimal("4,15"));
    }
    {
        ncpp::bilangan_desimal var1("-12,3");
        EXPECT_EQ(var1--, ncpp::bilangan_desimal("-12,3"));
        EXPECT_EQ(var1, ncpp::bilangan_desimal("-13,3"));
    }
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Lebih_Kecil) {
    EXPECT_TRUE(ncpp::bilangan_desimal("5,5") < ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_desimal("2,45") < ncpp::bilangan_desimal("2,5"));
    EXPECT_FALSE(ncpp::bilangan_desimal("11,0") < ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_desimal("2,0") < ncpp::bilangan_desimal("1,9"));
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Lebih_Kecil_Sama_Dengan) {
    EXPECT_TRUE(ncpp::bilangan_desimal("25,0") <= ncpp::bilangan_bulat("25"));
    EXPECT_TRUE(ncpp::bilangan_desimal("1,9") <= ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_desimal("1,1") <= ncpp::bilangan_bulat("-2"));
    EXPECT_FALSE(ncpp::bilangan_desimal("5,3") <= ncpp::bilangan_desimal("3,2"));
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Lebih_Besar) {
    EXPECT_TRUE(ncpp::bilangan_desimal("10,1") > ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_desimal("2,0") > ncpp::bilangan_desimal("1,9"));
    EXPECT_FALSE(ncpp::bilangan_desimal("10,9") > ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_desimal("1,9") > ncpp::bilangan_desimal("2,0"));
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Lebih_Besar_Sama_Dengan) {
    EXPECT_TRUE(ncpp::bilangan_desimal("23,1") >= ncpp::bilangan_bulat("23"));
    EXPECT_TRUE(ncpp::bilangan_desimal("2,0") >= ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_desimal("-2,0") >= ncpp::bilangan_bulat("-2,1"));
    EXPECT_FALSE(ncpp::bilangan_desimal("5,4") >= ncpp::bilangan_desimal("5,5"));
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Persamaan) {
    EXPECT_TRUE(ncpp::bilangan_desimal("10,0") == ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_desimal("2,0") == ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_desimal("10,0") == ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_desimal("2,0") == ncpp::bilangan_desimal("2,1"));
}

TEST(BILANGAN_DESIMAL_TEST, Operasi_Pertidaksamaan) {
    EXPECT_TRUE(ncpp::bilangan_desimal("11,1") != ncpp::bilangan_bulat("11"));
    EXPECT_TRUE(ncpp::bilangan_desimal("2,0") != ncpp::bilangan_desimal("2,1"));
    EXPECT_FALSE(ncpp::bilangan_desimal("10,0") != ncpp::bilangan_bulat("10"));
    EXPECT_FALSE(ncpp::bilangan_desimal("2,0") != ncpp::bilangan_desimal("2,0"));
}

TEST(BILANGAN_DESIMAL_TEST, Addition_Assignment_Operator) {
    ncpp::bilangan_desimal var("1,2");
    var += ncpp::bilangan_desimal("2,4");
    EXPECT_EQ(var, ncpp::bilangan_desimal("3,6"));
}

TEST(BILANGAN_DESIMAL_TEST, Subtraction_Assignment_Operator) {
    ncpp::bilangan_desimal var("1,4");
    var -= ncpp::bilangan_desimal("2,6");
    EXPECT_EQ(var, ncpp::bilangan_desimal("-1,2"));
}

TEST(BILANGAN_DESIMAL_TEST, Multiplication_Assignment_Operator) {
    ncpp::bilangan_desimal var("2,7");
    var *= ncpp::bilangan_desimal("2,5");
    EXPECT_EQ(var, ncpp::bilangan_desimal("6,75"));
}

TEST(BILANGAN_DESIMAL_TEST, Division_Assignment_Operator) {
    ncpp::bilangan_desimal var("5,5");
    var /= ncpp::bilangan_desimal("2,1");
    EXPECT_EQ(var, ncpp::bilangan_desimal("2,619047619047619"));
}

TEST(BILANGAN_DESIMAL_TEST, Modulus_Assignment_Operator) {
    ncpp::bilangan_desimal var("5,1");
    var %= ncpp::bilangan_desimal("2,6");
    EXPECT_EQ(var, ncpp::bilangan_desimal("2.4999999999999996"));
}