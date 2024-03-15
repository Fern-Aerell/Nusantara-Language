#include <gmp.h>
#include <gtest/gtest.h>
#include <regex>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/_bilangan_bulat_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"

TEST(_BILANGAN_BULAT_TEST, Constructors) {
    ncpp::konsol myKonsol;
    {
        ncpp::_bilangan_bulat_ var1;
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "0");
        myKonsol.bersihkan();
    }
    {
        ncpp::_bilangan_bulat_ var1("-50");
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "-50");
        myKonsol.bersihkan();
    }
}

TEST(_BILANGAN_BULAT_TEST, Copy_constructor) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_bulat_ var1("23");
    ncpp::_bilangan_bulat_ var2(var1);
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "23\n23\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_BULAT_TEST, Copy_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_bulat_ var1("25");
    ncpp::_bilangan_bulat_ var2 = var1;
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "25\n25\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_BULAT_TEST, Move_Constructor) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_bulat_ var1("114");
    ncpp::_bilangan_bulat_ var2(std::move(var1));
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "114\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_BULAT_TEST, Move_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_bulat_ var1("211");
    ncpp::_bilangan_bulat_ var2 = std::move(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "211\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_BULAT_TEST, Static_Variable_Basis) {
    EXPECT_EQ(ncpp::_bilangan_bulat_::basis, 10);
}

TEST(_BILANGAN_BULAT_TEST, Static_Fungsi_Pattern) {
    EXPECT_TRUE(std::regex_match("10", ncpp::_bilangan_bulat_::pattern()));
    EXPECT_TRUE(std::regex_match("-10", ncpp::_bilangan_bulat_::pattern()));
    EXPECT_FALSE(std::regex_match("10,0", ncpp::_bilangan_bulat_::pattern()));
}

TEST(_BILANGAN_BULAT_TEST, Fungsi_Ubah_Ke_String) {
    ncpp::_bilangan_bulat_ var1("54");
    EXPECT_EQ(var1.ubah_ke_string(), "54");
}

TEST(_BILANGAN_BULAT_TEST, Fungsi_Ambil) {
    ncpp::_bilangan_bulat_ var1("32");
    mpz_t var2;
    mpz_init_set_str(var2, "32", 10);
    EXPECT_TRUE(mpz_cmp(var1.ambil(), var2) == 0);
    mpz_clear(var2);
}

TEST(_BILANGAN_BULAT_TEST, Static_Fungsi_Ubah) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_desimal_ var1("10,5");
    ncpp::_bilangan_bulat_ var2(ncpp::_bilangan_bulat_::ubah(var1));
    myKonsol.cetak(var2);
    EXPECT_EQ(myKonsol.isi(), "10");
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Penjumlahan) {
	{
        ncpp::_bilangan_bulat_ var1("5");
	    ncpp::_bilangan_bulat_ var2("10");
        EXPECT_EQ(var1 + var2, ncpp::_bilangan_bulat_("15"));
    }
    {
        ncpp::_bilangan_bulat_ var1("2");
        ncpp::_bilangan_desimal_ var2("2,2");
        EXPECT_EQ(var1 + var2, ncpp::_bilangan_desimal_("4,2"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Pengurangan) {
	{
        ncpp::_bilangan_bulat_ var1("5");
	    ncpp::_bilangan_bulat_ var2("10");
        EXPECT_EQ(var1 - var2, ncpp::_bilangan_bulat_("-5"));
    }
    {
        ncpp::_bilangan_bulat_ var1("2");
        ncpp::_bilangan_desimal_ var2("2,2");
        EXPECT_EQ(var1 - var2, ncpp::_bilangan_desimal_("-0,2"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Perkalian) {
	{
        ncpp::_bilangan_bulat_ var1("5");
	    ncpp::_bilangan_bulat_ var2("10");
        EXPECT_EQ(var1 * var2, ncpp::_bilangan_bulat_("50"));
    }
    {
        ncpp::_bilangan_bulat_ var1("2");
        ncpp::_bilangan_desimal_ var2("2,2");
        EXPECT_EQ(var1 * var2, ncpp::_bilangan_desimal_("4,4"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Pembagian) {
	{
        ncpp::_bilangan_bulat_ var1("5");
	    ncpp::_bilangan_bulat_ var2("10");
        EXPECT_EQ(var1 / var2, ncpp::_bilangan_desimal_("0,5"));
    }
    {
        ncpp::_bilangan_bulat_ var1("2");
        ncpp::_bilangan_desimal_ var2("2,2");
        EXPECT_EQ(var1 / var2, ncpp::_bilangan_desimal_("0,9090909090909091"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Sisa_Pembagian) {
	{
        ncpp::_bilangan_bulat_ var1("5");
	    ncpp::_bilangan_bulat_ var2("10");
        EXPECT_EQ(var1 % var2, ncpp::_bilangan_desimal_("5"));
    }
    {
        ncpp::_bilangan_bulat_ var1("2");
        ncpp::_bilangan_desimal_ var2("2,2");
        EXPECT_EQ(var1 % var2, ncpp::_bilangan_desimal_("2"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Bitwise_Not) {
	{
        ncpp::_bilangan_bulat_ var1("5");
        EXPECT_EQ(~var1, ncpp::_bilangan_bulat_("-6"));
    }
    {
        ncpp::_bilangan_bulat_ var1("-10");
        EXPECT_EQ(~var1, ncpp::_bilangan_desimal_("9"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Pre_Increment) {
	{
        ncpp::_bilangan_bulat_ var1("5");
        EXPECT_EQ(++var1, ncpp::_bilangan_bulat_("6"));
    }
    {
        ncpp::_bilangan_bulat_ var1("-10");
        EXPECT_EQ(++var1, ncpp::_bilangan_bulat_("-9"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Post_Increment) {
	{
        ncpp::_bilangan_bulat_ var1("5");
        EXPECT_EQ(var1++, ncpp::_bilangan_bulat_("5"));
        EXPECT_EQ(var1, ncpp::_bilangan_bulat_("6"));
    }
    {
        ncpp::_bilangan_bulat_ var1("-10");
        EXPECT_EQ(var1++, ncpp::_bilangan_bulat_("-10"));
        EXPECT_EQ(var1, ncpp::_bilangan_bulat_("-9"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Pre_Decrement) {
	{
        ncpp::_bilangan_bulat_ var1("5");
        EXPECT_EQ(--var1, ncpp::_bilangan_bulat_("4"));
    }
    {
        ncpp::_bilangan_bulat_ var1("-10");
        EXPECT_EQ(--var1, ncpp::_bilangan_bulat_("-11"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Post_Decrement) {
	{
        ncpp::_bilangan_bulat_ var1("5");
        EXPECT_EQ(var1--, ncpp::_bilangan_bulat_("5"));
        EXPECT_EQ(var1, ncpp::_bilangan_bulat_("4"));
    }
    {
        ncpp::_bilangan_bulat_ var1("-10");
        EXPECT_EQ(var1--, ncpp::_bilangan_bulat_("-10"));
        EXPECT_EQ(var1, ncpp::_bilangan_bulat_("-11"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Bitwise_And) {
	{
        ncpp::_bilangan_bulat_ var1("10");
        ncpp::_bilangan_bulat_ var2("12");
        EXPECT_EQ(var1 & var2, ncpp::_bilangan_bulat_("8"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Bitwise_Or) {
	{
        ncpp::_bilangan_bulat_ var1("10");
        ncpp::_bilangan_bulat_ var2("12");
        EXPECT_EQ(var1 | var2, ncpp::_bilangan_bulat_("14"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Bitwise_Left_Shift) {
	{
        ncpp::_bilangan_bulat_ var1("10");
        ncpp::_bilangan_bulat_ var2("12");
        EXPECT_EQ(var1 << var2, ncpp::_bilangan_bulat_("40960"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Bitwise_Right_Shift) {
	{
        ncpp::_bilangan_bulat_ var1("35");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 >> var2, ncpp::_bilangan_bulat_("8"));
    }
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Lebih_Kecil) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("5") < ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") < ncpp::_bilangan_desimal_("2,5"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("12") < ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("2") < ncpp::_bilangan_desimal_("1,9"));
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Lebih_Kecil_Sama_Dengan) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("23") <= ncpp::_bilangan_bulat_("25"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") <= ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("1") <= ncpp::_bilangan_bulat_("-2"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("5") <= ncpp::_bilangan_desimal_("3,2"));
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Lebih_Besar) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("25") > ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") > ncpp::_bilangan_desimal_("1,9"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("2") > ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("2") > ncpp::_bilangan_desimal_("2,0"));
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Lebih_Besar_Sama_Dengan) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("23") >= ncpp::_bilangan_bulat_("23"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") >= ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("-3") >= ncpp::_bilangan_bulat_("-2"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("5,4") >= ncpp::_bilangan_desimal_("5,5"));
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Persamaan) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("10") == ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") == ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("10") == ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("2") == ncpp::_bilangan_desimal_("2,1"));
}

TEST(_BILANGAN_BULAT_TEST, Operasi_Pertidaksamaan) {
    EXPECT_TRUE(ncpp::_bilangan_bulat_("10") != ncpp::_bilangan_bulat_("11"));
    EXPECT_TRUE(ncpp::_bilangan_bulat_("2") != ncpp::_bilangan_desimal_("2,1"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("10") != ncpp::_bilangan_bulat_("10"));
    EXPECT_FALSE(ncpp::_bilangan_bulat_("2") != ncpp::_bilangan_desimal_("2,0"));
}

TEST(_BILANGAN_BULAT_TEST, Addition_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("1");
    var += ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("3"));
}

TEST(_BILANGAN_BULAT_TEST, Subtraction_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("1");
    var -= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("-1"));
}

TEST(_BILANGAN_BULAT_TEST, Multiplication_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("2");
    var *= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("4"));
}

TEST(_BILANGAN_BULAT_TEST, Division_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var /= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("2"));
}

TEST(_BILANGAN_BULAT_TEST, Modulus_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var %= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("1"));
}

TEST(_BILANGAN_BULAT_TEST, Bitwise_And_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var &= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("0"));
}

TEST(_BILANGAN_BULAT_TEST, Bitwise_Or_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var |= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("7"));
}

TEST(_BILANGAN_BULAT_TEST, Bitwise_Xor_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var ^= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("7"));
}

TEST(_BILANGAN_BULAT_TEST, Bitwise_Left_Shift_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var <<= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("20"));
}

TEST(_BILANGAN_BULAT_TEST, Bitwise_Right_Shift_Assignment_Operator) {
    ncpp::_bilangan_bulat_ var("5");
    var >>= ncpp::_bilangan_bulat_("2");
    EXPECT_EQ(var, ncpp::_bilangan_bulat_("1"));
}