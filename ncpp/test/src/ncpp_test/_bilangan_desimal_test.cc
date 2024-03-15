#include <gmp.h>
#include <gtest/gtest.h>
#include <mpfr.h>
#include <ncpp/ncpp.h>
#include <regex>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/_bilangan_bulat_.h"
#include "ncpp/tipe_data/bilangan/_bilangan_desimal_.h"

TEST(_BILANGAN_DESIMAL_TEST, Constructors) {
    ncpp::konsol myKonsol;
    {
        ncpp::_bilangan_desimal_ var1;
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "0");
        myKonsol.bersihkan();
    }
    {
        ncpp::_bilangan_desimal_ var1("-50,5");
        myKonsol.cetak(var1);
        EXPECT_EQ(myKonsol.isi(), "-50,5");
        myKonsol.bersihkan();
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Copy_constructor) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_desimal_ var1("23,2");
    ncpp::_bilangan_desimal_ var2(var1);
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "23,2\n23,2\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_DESIMAL_TEST, Copy_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_desimal_ var1("25,23");
    ncpp::_bilangan_desimal_ var2 = var1;
    myKonsol.cetak_baris_baru(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "25,23\n25,23\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_DESIMAL_TEST, Move_Constructor) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_desimal_ var1("11,4");
    ncpp::_bilangan_desimal_ var2(std::move(var1));
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "11,4\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_DESIMAL_TEST, Move_Assignment_Operator) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_desimal_ var1("211,12");
    ncpp::_bilangan_desimal_ var2 = std::move(var1);
    myKonsol.cetak_baris_baru(var2);
    EXPECT_EQ(myKonsol.isi(), "211,12\n");
    myKonsol.bersihkan();
}

TEST(_BILANGAN_DESIMAL_TEST, Static_Variable_Basis) {
    EXPECT_EQ(ncpp::_bilangan_desimal_::basis, 10);
}

TEST(_BILANGAN_DESIMAL_TEST, Static_Variable_Presisi_String_Bawaan) {
    EXPECT_EQ(ncpp::_bilangan_desimal_::presisi_string_bawaan, 15);
}

TEST(_BILANGAN_DESIMAL_TEST, Static_Fungsi_Pattern) {
    EXPECT_TRUE(std::regex_match("10,2", ncpp::_bilangan_desimal_::pattern()));
    EXPECT_TRUE(std::regex_match("-10,4", ncpp::_bilangan_desimal_::pattern()));
    EXPECT_FALSE(std::regex_match("10", ncpp::_bilangan_desimal_::pattern()));
}

TEST(_BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_String) {
    ncpp::_bilangan_desimal_ var1("54,2");
    EXPECT_EQ(var1.ubah_ke_string(), "54,2");
}

TEST(_BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_String_Tetap) {
    ncpp::_bilangan_desimal_ var1("54,22");
    EXPECT_EQ(var1.ubah_ke_string_tetap(1), "54,2");
}

TEST(_BILANGAN_DESIMAL_TEST, Fungsi_Ubah_Ke_String_Presisi) {
    ncpp::_bilangan_desimal_ var1("10,5");
    EXPECT_EQ(var1.ubah_ke_string_presisi(2), "10");
}

TEST(_BILANGAN_DESIMAL_TEST, Fungsi_Ambil) {
    ncpp::_bilangan_desimal_ var1("32,2");
    mpfr_t var2;
    mpfr_init_set_str(var2, "32.2", 10, ncpp::_bilangan_desimal_::pembulatan);
    EXPECT_TRUE(mpfr_equal_p(var1.ambil(), var2) != 0);
    mpfr_clear(var2);
}

TEST(_BILANGAN_DESIMAL_TEST, Static_Fungsi_Ubah) {
    ncpp::konsol myKonsol;
    ncpp::_bilangan_bulat_ var1("10");
    ncpp::_bilangan_desimal_ var2(ncpp::_bilangan_desimal_::ubah(var1));
    myKonsol.cetak(var2);
    EXPECT_EQ(myKonsol.isi(), "10");
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Penjumlahan) {
	{
        ncpp::_bilangan_desimal_ var1("5,5");
	    ncpp::_bilangan_desimal_ var2("10,5");
        EXPECT_EQ(var1 + var2, ncpp::_bilangan_desimal_("16"));
    }
    {
        ncpp::_bilangan_desimal_ var1("2,5");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 + var2, ncpp::_bilangan_desimal_("4,5"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Pengurangan) {
	{
        ncpp::_bilangan_desimal_ var1("5,5");
	    ncpp::_bilangan_desimal_ var2("10,5");
        EXPECT_EQ(var1 - var2, ncpp::_bilangan_desimal_("-5"));
    }
    {
        ncpp::_bilangan_desimal_ var1("2,5");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 - var2, ncpp::_bilangan_desimal_("0,5"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Perkalian) {
	{
        ncpp::_bilangan_desimal_ var1("5,5");
	    ncpp::_bilangan_desimal_ var2("10,5");
        EXPECT_EQ(var1 * var2, ncpp::_bilangan_desimal_("57,75"));
    }
    {
        ncpp::_bilangan_desimal_ var1("2,5");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 * var2, ncpp::_bilangan_desimal_("5"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Pembagian) {
	{
        ncpp::_bilangan_desimal_ var1("5,5");
	    ncpp::_bilangan_desimal_ var2("10,5");
        EXPECT_EQ(var1 / var2, ncpp::_bilangan_desimal_("0,5238095238095238"));
    }
    {
        ncpp::_bilangan_desimal_ var1("2,5");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 / var2, ncpp::_bilangan_desimal_("1,25"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Sisa_Pembagian) {
	{
        ncpp::_bilangan_desimal_ var1("5,5");
	    ncpp::_bilangan_desimal_ var2("10,5");
        EXPECT_EQ(var1 % var2, ncpp::_bilangan_desimal_("5,5"));
    }
    {
        ncpp::_bilangan_desimal_ var1("2,5");
        ncpp::_bilangan_bulat_ var2("2");
        EXPECT_EQ(var1 % var2, ncpp::_bilangan_desimal_("0,5"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Pre_Increment) {
	{
        ncpp::_bilangan_desimal_ var1("5,2");
        EXPECT_EQ(++var1, ncpp::_bilangan_desimal_("6,2"));
    }
    {
        ncpp::_bilangan_desimal_ var1("-10,10");
        EXPECT_EQ(++var1, ncpp::_bilangan_desimal_("-9,1"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Post_Increment) {
	{
        ncpp::_bilangan_desimal_ var1("2,4");
        EXPECT_EQ(var1++, ncpp::_bilangan_desimal_("2,4"));
        EXPECT_EQ(var1, ncpp::_bilangan_desimal_("3,4"));
    }
    {
        ncpp::_bilangan_desimal_ var1("-18,3");
        EXPECT_EQ(var1++, ncpp::_bilangan_desimal_("-18,3"));
        EXPECT_EQ(var1, ncpp::_bilangan_desimal_("-17,3"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Pre_Decrement) {
	{
        ncpp::_bilangan_desimal_ var1("21,2");
        EXPECT_EQ(--var1, ncpp::_bilangan_desimal_("20,2"));
    }
    {
        ncpp::_bilangan_desimal_ var1("-1,5");
        EXPECT_EQ(--var1, ncpp::_bilangan_desimal_("-2,5"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Post_Decrement) {
	{
        ncpp::_bilangan_desimal_ var1("5,15");
        EXPECT_EQ(var1--, ncpp::_bilangan_desimal_("5,15"));
        EXPECT_EQ(var1, ncpp::_bilangan_desimal_("4,15"));
    }
    {
        ncpp::_bilangan_desimal_ var1("-12,3");
        EXPECT_EQ(var1--, ncpp::_bilangan_desimal_("-12,3"));
        EXPECT_EQ(var1, ncpp::_bilangan_desimal_("-13,3"));
    }
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Lebih_Kecil) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("5,5") < ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("2,45") < ncpp::_bilangan_desimal_("2,5"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("11,0") < ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("2,0") < ncpp::_bilangan_desimal_("1,9"));
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Lebih_Kecil_Sama_Dengan) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("25,0") <= ncpp::_bilangan_bulat_("25"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("1,9") <= ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("1,1") <= ncpp::_bilangan_bulat_("-2"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("5,3") <= ncpp::_bilangan_desimal_("3,2"));
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Lebih_Besar) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("10,1") > ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("2,0") > ncpp::_bilangan_desimal_("1,9"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("10,9") > ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("1,9") > ncpp::_bilangan_desimal_("2,0"));
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Lebih_Besar_Sama_Dengan) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("23,1") >= ncpp::_bilangan_bulat_("23"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("2,0") >= ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("-2,0") >= ncpp::_bilangan_bulat_("-2,1"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("5,4") >= ncpp::_bilangan_desimal_("5,5"));
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Persamaan) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("10,0") == ncpp::_bilangan_bulat_("10"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("2,0") == ncpp::_bilangan_desimal_("2,0"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("10,0") == ncpp::_bilangan_bulat_("11"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("2,0") == ncpp::_bilangan_desimal_("2,1"));
}

TEST(_BILANGAN_DESIMAL_TEST, Operasi_Pertidaksamaan) {
    EXPECT_TRUE(ncpp::_bilangan_desimal_("11,1") != ncpp::_bilangan_bulat_("11"));
    EXPECT_TRUE(ncpp::_bilangan_desimal_("2,0") != ncpp::_bilangan_desimal_("2,1"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("10,0") != ncpp::_bilangan_bulat_("10"));
    EXPECT_FALSE(ncpp::_bilangan_desimal_("2,0") != ncpp::_bilangan_desimal_("2,0"));
}

TEST(_BILANGAN_DESIMAL_TEST, Addition_Assignment_Operator) {
    ncpp::_bilangan_desimal_ var("1,2");
    var += ncpp::_bilangan_desimal_("2,4");
    EXPECT_EQ(var, ncpp::_bilangan_desimal_("3,6"));
}

TEST(_BILANGAN_DESIMAL_TEST, Subtraction_Assignment_Operator) {
    ncpp::_bilangan_desimal_ var("1,4");
    var -= ncpp::_bilangan_desimal_("2,6");
    EXPECT_EQ(var, ncpp::_bilangan_desimal_("-1,2"));
}

TEST(_BILANGAN_DESIMAL_TEST, Multiplication_Assignment_Operator) {
    ncpp::_bilangan_desimal_ var("2,7");
    var *= ncpp::_bilangan_desimal_("2,5");
    EXPECT_EQ(var, ncpp::_bilangan_desimal_("6,75"));
}

TEST(_BILANGAN_DESIMAL_TEST, Division_Assignment_Operator) {
    ncpp::_bilangan_desimal_ var("5,5");
    var /= ncpp::_bilangan_desimal_("2,1");
    EXPECT_EQ(var, ncpp::_bilangan_desimal_("2,619047619047619"));
}

TEST(_BILANGAN_DESIMAL_TEST, Modulus_Assignment_Operator) {
    ncpp::_bilangan_desimal_ var("5,1");
    var %= ncpp::_bilangan_desimal_("2,6");
    EXPECT_EQ(var, ncpp::_bilangan_desimal_("2.4999999999999996"));
}