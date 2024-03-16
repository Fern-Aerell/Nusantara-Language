#include "ncpp/tipe_data/bilangan/bilangan.h"
#include <gtest/gtest.h>
#include <ncpp/ncpp.h>
#include <format>
#include <string>

TEST(BILANGAN_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::bilangan var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "0");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::bilangan var1("5");
	ncpp::bilangan var2("5,4");
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "5\n5,4\n");
	std::string nilai_var3 = "Bukan Bilangan";
	try {
		ncpp::bilangan var3(nilai_var3);
	} catch (const std::exception& error) {
		std::string error_str(error.what());
		EXPECT_TRUE(error_str.contains(std::format("'{}' bukanlah sebuah bilangan.", nilai_var3)));
	}
}

TEST(BILANGAN_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::bilangan var1("5");
	ncpp::bilangan var2(var1);
	ncpp::bilangan var3(ncpp::bilangan("10"));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "5\n5\n10\n");
}

TEST(BILANGAN_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::bilangan var1 = ncpp::bilangan("10");
	ncpp::bilangan var2 = var1;
	ncpp::bilangan var3(ncpp::bilangan("10"));
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "10\n10\n10\n");
}

TEST(BILANGAN_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::bilangan var1("10");
	ncpp::bilangan var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "10\n");
}

TEST(BILANGAN_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::bilangan var1("16");
	ncpp::bilangan var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "16\n");
}

TEST(BILANGAN_TEST, Fungsi_Ini_Bulat) {
	ncpp::bilangan var1("16");
	ncpp::bilangan var2("17,5");
	EXPECT_TRUE(var1.ini_bulat());
	EXPECT_FALSE(var2.ini_bulat());
}

TEST(BILANGAN_TEST, Fungsi_Ini_Desimal) {
	ncpp::bilangan var1("17,5");
	ncpp::bilangan var2("16");
	EXPECT_TRUE(var1.ini_desimal());
	EXPECT_FALSE(var2.ini_desimal());
}

TEST(BILANGAN_TEST, Fungsi_Ubah_Ke_String) {
	ncpp::bilangan var1("16");
	ncpp::bilangan var2("17,5");
	EXPECT_EQ(var1.ubah_ke_string(), "16");
	EXPECT_EQ(var2.ubah_ke_string(), "17,5");
}

TEST(BILANGAN_TEST, Operasi_Penjumlahan) {
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 + var2, ncpp::bilangan("20"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10,5");
		EXPECT_EQ(var1 + var2, ncpp::bilangan("21"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 + var2, ncpp::bilangan("20,5"));
	}
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("45,3");
		EXPECT_EQ(var1 + var2, ncpp::bilangan("55,3"));
	}
}

TEST(BILANGAN_TEST, Operasi_Pengurangan) {
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 - var2, ncpp::bilangan("0"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10,5");
		EXPECT_EQ(var1 - var2, ncpp::bilangan("0"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 - var2, ncpp::bilangan("0,5"));
	}
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("45,3");
		EXPECT_EQ(var1 - var2, ncpp::bilangan("-35,3"));
	}
}

TEST(BILANGAN_TEST, Operasi_Perkalian) {
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 * var2, ncpp::bilangan("100"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10,5");
		EXPECT_EQ(var1 * var2, ncpp::bilangan("110,25"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 * var2, ncpp::bilangan("105"));
	}
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("45,3");
		EXPECT_EQ(var1 * var2, ncpp::bilangan("453"));
	}
}

TEST(BILANGAN_TEST, Operasi_Pembagian) {
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 / var2, ncpp::bilangan("1"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10,5");
		EXPECT_EQ(var1 / var2, ncpp::bilangan("1"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 / var2, ncpp::bilangan("1,05"));
	}
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("45,3");
		EXPECT_EQ(var1 / var2, ncpp::bilangan("0,2207505518763797"));
	}
}

TEST(BILANGAN_TEST, Operasi_Sisa_Pembagian) {
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 % var2, ncpp::bilangan("0"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10,5");
		EXPECT_EQ(var1 % var2, ncpp::bilangan("0"));
	}
	{
		ncpp::bilangan var1("10,5");
		ncpp::bilangan var2("10");
		EXPECT_EQ(var1 % var2, ncpp::bilangan("0,5"));
	}
	{
		ncpp::bilangan var1("10");
		ncpp::bilangan var2("45,3");
		EXPECT_EQ(var1 % var2, ncpp::bilangan("10"));
	}
}

TEST(BILANGAN_TEST, Operasi_Bitwise_Not) {
	{
		ncpp::bilangan var1("10");
		EXPECT_EQ(~var1, ncpp::bilangan("-11"));
	}
	{
		try {
			ncpp::bilangan var1("10,5");
			EXPECT_EQ(~var1, ncpp::bilangan("0"));
		} catch (const std::exception& error) {
			std::string error_str(error.what());
			EXPECT_TRUE(error_str.contains("Operasi bitwise not '~' pada bilangan desimal tidak dapat dilakukan."));
		}
	}
}

TEST(BILANGAN_TEST, Operasi_Pre_Increment) {
	{
        ncpp::bilangan var1("5");
        EXPECT_EQ(++var1, ncpp::bilangan("6"));
    }
    {
        ncpp::bilangan var1("-10");
        EXPECT_EQ(++var1, ncpp::bilangan("-9"));
    }
}

TEST(BILANGAN_TEST, Operasi_Post_Increment) {
	{
        ncpp::bilangan var1("2,4");
        EXPECT_EQ(var1++, ncpp::bilangan("2,4"));
        EXPECT_EQ(var1, ncpp::bilangan("3,4"));
    }
    {
        ncpp::bilangan var1("-18,3");
        EXPECT_EQ(var1++, ncpp::bilangan("-18,3"));
        EXPECT_EQ(var1, ncpp::bilangan("-17,3"));
    }
}

TEST(BILANGAN_TEST, Operasi_Pre_Decrement) {
	{
        ncpp::bilangan var1("5");
        EXPECT_EQ(--var1, ncpp::bilangan("4"));
    }
    {
        ncpp::bilangan var1("-10");
        EXPECT_EQ(--var1, ncpp::bilangan("-11"));
    }
}

TEST(BILANGAN_TEST, Operasi_Post_Decrement) {
	{
        ncpp::bilangan var1("5,15");
        EXPECT_EQ(var1--, ncpp::bilangan("5,15"));
        EXPECT_EQ(var1, ncpp::bilangan("4,15"));
    }
    {
        ncpp::bilangan var1("-12,3");
        EXPECT_EQ(var1--, ncpp::bilangan("-12,3"));
        EXPECT_EQ(var1, ncpp::bilangan("-13,3"));
    }
}

TEST(BILANGAN_TEST, Operasi_Bitwise_And) {
	{
        ncpp::bilangan var1("10");
        ncpp::bilangan var2("15");
        EXPECT_EQ(var1 & var2, ncpp::bilangan("10"));
    }
}

TEST(BILANGAN_TEST, Operasi_Bitwise_Xor) {
	{
        ncpp::bilangan var1("26");
        ncpp::bilangan var2("32");
        EXPECT_EQ(var1 ^ var2, ncpp::bilangan("58"));
    }
}

TEST(BILANGAN_TEST, Operasi_Bitwise_Or) {
	{
        ncpp::bilangan var1("10");
        ncpp::bilangan var2("12");
        EXPECT_EQ(var1 | var2, ncpp::bilangan("14"));
    }
}

TEST(BILANGAN_TEST, Operasi_Bitwise_Left_Shift) {
	{
        ncpp::bilangan var1("10");
        ncpp::bilangan var2("12");
        EXPECT_EQ(var1 << var2, ncpp::bilangan("40960"));
    }
}

TEST(BILANGAN_TEST, Operasi_Bitwise_Right_Shift) {
	{
        ncpp::bilangan var1("35");
        ncpp::bilangan var2("2");
        EXPECT_EQ(var1 >> var2, ncpp::bilangan("8"));
    }
}

TEST(BILANGAN_TEST, Operasi_Lebih_Kecil) {
	EXPECT_TRUE(ncpp::bilangan("4") < ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("4") < ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("4,0") < ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("4,0") < ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("7") < ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5,2") < ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") < ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("5,3") < ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") < ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Operasi_Lebih_Kecil_Sama_Dengan) {
	EXPECT_TRUE(ncpp::bilangan("5") <= ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5") <= ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("4,0") <= ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5,0") <= ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("7") <= ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5,2") <= ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") <= ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("5,3") <= ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") <= ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Operasi_Lebih_Besar) {
	EXPECT_TRUE(ncpp::bilangan("6") > ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("6") > ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("6,0") > ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5,1") > ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("5") > ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5,0") > ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("4,9") > ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("5,0") > ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,0") > ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Operasi_Lebih_Besar_Sama_Dengan) {
	EXPECT_TRUE(ncpp::bilangan("5") >= ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5") >= ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("5,1") >= ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5,0") >= ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("5") >= ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5,0") >= ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("4,0") >= ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("1,4") >= ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("4,4") >= ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Operasi_Persamaan) {
	EXPECT_TRUE(ncpp::bilangan("5") == ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5") == ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("5,0") == ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5,0") == ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("5") == ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5") == ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") == ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("5,0") == ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,1") == ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Operasi_Pertidaksamaan) {
	EXPECT_TRUE(ncpp::bilangan("6") != ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("2") != ncpp::bilangan("5,0"));
	EXPECT_TRUE(ncpp::bilangan("5,1") != ncpp::bilangan("5"));
	EXPECT_TRUE(ncpp::bilangan("5,2") != ncpp::bilangan("5,0"));
	EXPECT_FALSE(ncpp::bilangan("6") != ncpp::bilangan("6"));
	EXPECT_FALSE(ncpp::bilangan("5,1") != ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,0") != ncpp::bilangan("5"));
	EXPECT_FALSE(ncpp::bilangan("5,1") != ncpp::bilangan("5,1"));
	EXPECT_FALSE(ncpp::bilangan("5,0") != ncpp::bilangan("5,0"));
}

TEST(BILANGAN_TEST, Addition_Assignment_Operator) {
    ncpp::bilangan var("1");
    var += ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("3"));
}

TEST(BILANGAN_TEST, Subtraction_Assignment_Operator) {
    ncpp::bilangan var("1");
    var -= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("-1"));
}

TEST(BILANGAN_TEST, Multiplication_Assignment_Operator) {
    ncpp::bilangan var("2");
    var *= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("4"));
}

TEST(BILANGAN_TEST, Division_Assignment_Operator) {
    ncpp::bilangan var("5");
    var /= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("2,5"));
}

TEST(BILANGAN_TEST, Modulus_Assignment_Operator) {
    ncpp::bilangan var("5");
    var %= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("1"));
}

TEST(BILANGAN_TEST, Bitwise_And_Assignment_Operator) {
    ncpp::bilangan var("5");
    var &= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("0"));
}

TEST(BILANGAN_TEST, Bitwise_Or_Assignment_Operator) {
    ncpp::bilangan var("5");
    var |= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("7"));
}

TEST(BILANGAN_TEST, Bitwise_Xor_Assignment_Operator) {
    ncpp::bilangan var("5");
    var ^= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("7"));
}

TEST(BILANGAN_TEST, Bitwise_Left_Shift_Assignment_Operator) {
    ncpp::bilangan var("5");
    var <<= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("20"));
}

TEST(BILANGAN_TEST, Bitwise_Right_Shift_Assignment_Operator) {
    ncpp::bilangan var("5");
    var >>= ncpp::bilangan("2");
    EXPECT_EQ(var, ncpp::bilangan("1"));
}

TEST(BILANGAN_TEST, Is_Arithmetic_True) {
	EXPECT_TRUE(std::is_arithmetic_v<ncpp::bilangan>);
}
