#include <gmp.h>
#include <gtest/gtest.h>
#include <regex>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"
#include "ncpp/tipe_data/bilangan/bilangan_desimal.h"

TEST(BILANGAN_BULAT_TEST, Constructors) {
    ncpp::konsol myKonsol;
    {
        ncpp::bilangan_bulat var1;
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "0");
        myKonsol.bersihkan();
    }
    {
        ncpp::bilangan_bulat var1("-50");
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "-50");
        myKonsol.bersihkan();
    }
}

TEST(BILANGAN_BULAT_TEST, Copy_constructor) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_bulat var1("23");
    ncpp::bilangan_bulat var2(var1);
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "23\n23\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_BULAT_TEST, Copy_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_bulat var1("25");
    ncpp::bilangan_bulat var2 = var1;
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "25\n25\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_BULAT_TEST, Move_Constructor) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_bulat var1("114");
    ncpp::bilangan_bulat var2(std::move(var1));
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "114\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_BULAT_TEST, Move_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_bulat var1("211");
    ncpp::bilangan_bulat var2 = std::move(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "211\n");
    myKonsol.bersihkan();
}

TEST(BILANGAN_BULAT_TEST, Static_Variable_Basis) {
    EXPECT_EQ(ncpp::bilangan_bulat::basis, 10);
}

TEST(BILANGAN_BULAT_TEST, Static_Fungsi_Pattern) {
    EXPECT_TRUE(std::regex_match("10", ncpp::bilangan_bulat::pattern()));
    EXPECT_TRUE(std::regex_match("-10", ncpp::bilangan_bulat::pattern()));
    EXPECT_FALSE(std::regex_match("10,0", ncpp::bilangan_bulat::pattern()));
}

TEST(BILANGAN_BULAT_TEST, Fungsi_Ubah_Ke_String) {
    ncpp::bilangan_bulat var1("54");
    EXPECT_EQ(var1.ubah_ke_string(), "54");
}

TEST(BILANGAN_BULAT_TEST, Fungsi_Ambil) {
    ncpp::bilangan_bulat var1("32");
    mpz_t var2;
    mpz_init_set_str(var2, "32", 10);
    EXPECT_TRUE(mpz_cmp(var1.ambil(), var2) == 0);
    mpz_clear(var2);
}

TEST(BILANGAN_BULAT_TEST, Static_Fungsi_Ubah) {
    ncpp::konsol myKonsol;
    ncpp::bilangan_desimal var1("10,5");
    ncpp::bilangan_bulat var2(ncpp::bilangan_bulat::ubah(var1));
    myKonsol.cetak(var2);
    EXPECT_EQ(myKonsol.isi(), "10");
}

TEST(BILANGAN_BULAT_TEST, Operasi_Penjumlahan) {
	{
        ncpp::bilangan_bulat var1("5");
	    ncpp::bilangan_bulat var2("10");
        EXPECT_EQ(var1 + var2, ncpp::bilangan_bulat("15"));
    }
    {
        ncpp::bilangan_bulat var1("2");
        ncpp::bilangan_desimal var2("2,2");
        EXPECT_EQ(var1 + var2, ncpp::bilangan_desimal("4,2"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Pengurangan) {
	{
        ncpp::bilangan_bulat var1("5");
	    ncpp::bilangan_bulat var2("10");
        EXPECT_EQ(var1 - var2, ncpp::bilangan_bulat("-5"));
    }
    {
        ncpp::bilangan_bulat var1("2");
        ncpp::bilangan_desimal var2("2,2");
        EXPECT_EQ(var1 - var2, ncpp::bilangan_desimal("-0,2"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Perkalian) {
	{
        ncpp::bilangan_bulat var1("5");
	    ncpp::bilangan_bulat var2("10");
        EXPECT_EQ(var1 * var2, ncpp::bilangan_bulat("50"));
    }
    {
        ncpp::bilangan_bulat var1("2");
        ncpp::bilangan_desimal var2("2,2");
        EXPECT_EQ(var1 * var2, ncpp::bilangan_desimal("4,4"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Pembagian) {
	{
        ncpp::bilangan_bulat var1("5");
	    ncpp::bilangan_bulat var2("10");
        EXPECT_EQ(var1 / var2, ncpp::bilangan_desimal("0,5"));
    }
    {
        ncpp::bilangan_bulat var1("2");
        ncpp::bilangan_desimal var2("2,2");
        EXPECT_EQ(var1 / var2, ncpp::bilangan_desimal("0,9090909090909091"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Sisa_Pembagian) {
	{
        ncpp::bilangan_bulat var1("5");
	    ncpp::bilangan_bulat var2("10");
        EXPECT_EQ(var1 % var2, ncpp::bilangan_desimal("5"));
    }
    {
        ncpp::bilangan_bulat var1("2");
        ncpp::bilangan_desimal var2("2,2");
        EXPECT_EQ(var1 % var2, ncpp::bilangan_desimal("2"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Bitwise_Not) {
	{
        ncpp::bilangan_bulat var1("5");
        EXPECT_EQ(~var1, ncpp::bilangan_bulat("-6"));
    }
    {
        ncpp::bilangan_bulat var1("-10");
        EXPECT_EQ(~var1, ncpp::bilangan_desimal("9"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Pre_Increment) {
	{
        ncpp::bilangan_bulat var1("5");
        EXPECT_EQ(++var1, ncpp::bilangan_bulat("6"));
    }
    {
        ncpp::bilangan_bulat var1("-10");
        EXPECT_EQ(++var1, ncpp::bilangan_bulat("-9"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Post_Increment) {
	{
        ncpp::bilangan_bulat var1("5");
        EXPECT_EQ(var1++, ncpp::bilangan_bulat("5"));
        EXPECT_EQ(var1, ncpp::bilangan_bulat("6"));
    }
    {
        ncpp::bilangan_bulat var1("-10");
        EXPECT_EQ(var1++, ncpp::bilangan_bulat("-10"));
        EXPECT_EQ(var1, ncpp::bilangan_bulat("-9"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Pre_Decrement) {
	{
        ncpp::bilangan_bulat var1("5");
        EXPECT_EQ(--var1, ncpp::bilangan_bulat("4"));
    }
    {
        ncpp::bilangan_bulat var1("-10");
        EXPECT_EQ(--var1, ncpp::bilangan_bulat("-11"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Post_Decrement) {
	{
        ncpp::bilangan_bulat var1("5");
        EXPECT_EQ(var1--, ncpp::bilangan_bulat("5"));
        EXPECT_EQ(var1, ncpp::bilangan_bulat("4"));
    }
    {
        ncpp::bilangan_bulat var1("-10");
        EXPECT_EQ(var1--, ncpp::bilangan_bulat("-10"));
        EXPECT_EQ(var1, ncpp::bilangan_bulat("-11"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Bitwise_And) {
	{
        ncpp::bilangan_bulat var1("10");
        ncpp::bilangan_bulat var2("12");
        EXPECT_EQ(var1 & var2, ncpp::bilangan_bulat("8"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Bitwise_Or) {
	{
        ncpp::bilangan_bulat var1("10");
        ncpp::bilangan_bulat var2("12");
        EXPECT_EQ(var1 | var2, ncpp::bilangan_bulat("14"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Bitwise_Left_Shift) {
	{
        ncpp::bilangan_bulat var1("10");
        ncpp::bilangan_bulat var2("12");
        EXPECT_EQ(var1 << var2, ncpp::bilangan_bulat("40960"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Bitwise_Right_Shift) {
	{
        ncpp::bilangan_bulat var1("35");
        ncpp::bilangan_bulat var2("2");
        EXPECT_EQ(var1 >> var2, ncpp::bilangan_bulat("8"));
    }
}

TEST(BILANGAN_BULAT_TEST, Operasi_Lebih_Kecil) {
    EXPECT_TRUE(ncpp::bilangan_bulat("5") < ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") < ncpp::bilangan_desimal("2,5"));
    EXPECT_FALSE(ncpp::bilangan_bulat("12") < ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_bulat("2") < ncpp::bilangan_desimal("1,9"));
}

TEST(BILANGAN_BULAT_TEST, Operasi_Lebih_Kecil_Sama_Dengan) {
    EXPECT_TRUE(ncpp::bilangan_bulat("23") <= ncpp::bilangan_bulat("25"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") <= ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_bulat("1") <= ncpp::bilangan_bulat("-2"));
    EXPECT_FALSE(ncpp::bilangan_bulat("5") <= ncpp::bilangan_desimal("3,2"));
}

TEST(BILANGAN_BULAT_TEST, Operasi_Lebih_Besar) {
    EXPECT_TRUE(ncpp::bilangan_bulat("25") > ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") > ncpp::bilangan_desimal("1,9"));
    EXPECT_FALSE(ncpp::bilangan_bulat("2") > ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_bulat("2") > ncpp::bilangan_desimal("2,0"));
}

TEST(BILANGAN_BULAT_TEST, Operasi_Lebih_Besar_Sama_Dengan) {
    EXPECT_TRUE(ncpp::bilangan_bulat("23") >= ncpp::bilangan_bulat("23"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") >= ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_bulat("-3") >= ncpp::bilangan_bulat("-2"));
    EXPECT_FALSE(ncpp::bilangan_bulat("5,4") >= ncpp::bilangan_desimal("5,5"));
}

TEST(BILANGAN_BULAT_TEST, Operasi_Persamaan) {
    EXPECT_TRUE(ncpp::bilangan_bulat("10") == ncpp::bilangan_bulat("10"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") == ncpp::bilangan_desimal("2,0"));
    EXPECT_FALSE(ncpp::bilangan_bulat("10") == ncpp::bilangan_bulat("11"));
    EXPECT_FALSE(ncpp::bilangan_bulat("2") == ncpp::bilangan_desimal("2,1"));
}

TEST(BILANGAN_BULAT_TEST, Operasi_Pertidaksamaan) {
    EXPECT_TRUE(ncpp::bilangan_bulat("10") != ncpp::bilangan_bulat("11"));
    EXPECT_TRUE(ncpp::bilangan_bulat("2") != ncpp::bilangan_desimal("2,1"));
    EXPECT_FALSE(ncpp::bilangan_bulat("10") != ncpp::bilangan_bulat("10"));
    EXPECT_FALSE(ncpp::bilangan_bulat("2") != ncpp::bilangan_desimal("2,0"));
}

TEST(BILANGAN_BULAT_TEST, Addition_Assignment_Operator) {
    ncpp::bilangan_bulat var("1");
    var += ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("3"));
}

TEST(BILANGAN_BULAT_TEST, Subtraction_Assignment_Operator) {
    ncpp::bilangan_bulat var("1");
    var -= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("-1"));
}

TEST(BILANGAN_BULAT_TEST, Multiplication_Assignment_Operator) {
    ncpp::bilangan_bulat var("2");
    var *= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("4"));
}

TEST(BILANGAN_BULAT_TEST, Division_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var /= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("2"));
}

TEST(BILANGAN_BULAT_TEST, Modulus_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var %= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("1"));
}

TEST(BILANGAN_BULAT_TEST, Bitwise_And_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var &= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("0"));
}

TEST(BILANGAN_BULAT_TEST, Bitwise_Or_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var |= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("7"));
}

TEST(BILANGAN_BULAT_TEST, Bitwise_Xor_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var ^= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("7"));
}

TEST(BILANGAN_BULAT_TEST, Bitwise_Left_Shift_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var <<= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("20"));
}

TEST(BILANGAN_BULAT_TEST, Bitwise_Right_Shift_Assignment_Operator) {
    ncpp::bilangan_bulat var("5");
    var >>= ncpp::bilangan_bulat("2");
    EXPECT_EQ(var, ncpp::bilangan_bulat("1"));
}
