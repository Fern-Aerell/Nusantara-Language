#include "ncpp/tipe_data/teks.h"
#include <gtest/gtest.h>
#include <format>
#include <iostream>
#include <string>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/bilangan.h"
#include "ncpp/tipe_data/bilangan/bilangan_bulat.h"

TEST(TEKS_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::teks var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::teks var1("Fern");
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "Fern\n");
	myKonsol.bersihkan();
	// Constructor 3
	ncpp::teks var2("Umur: {}", 18);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Umur: 18\n");
}

TEST(TEKS_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::teks var1("Aerell");
	ncpp::teks var2(var1);
	ncpp::teks var3(ncpp::teks("Fern"));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "Aerell\nAerell\nFern\n");
}

TEST(TEKS_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::teks var1 = ncpp::teks("Aerell");
	ncpp::teks var2 = var1;
	ncpp::teks var3(ncpp::teks("Fern"));
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "Aerell\nAerell\nAerell\n");
}

TEST(TEKS_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::teks var1("Chezca");
	ncpp::teks var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Chezca\n");
}

TEST(TEKS_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::teks var1("Zoro");
	ncpp::teks var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Zoro\n");
}

TEST(TEKS_TEST, Operasi_Penjumlahan) {
	ncpp::teks first("Fern");
	ncpp::teks last("Aerell");
	EXPECT_EQ(first + last, ncpp::teks("FernAerell"));
}

TEST(TEKS_TEST, Operasi_Penjumlahan_Assigment) {
	ncpp::teks var1("Fern");
	ncpp::teks var2("Aerell");
	var1 += var2;
	EXPECT_EQ(var1, ncpp::teks("FernAerell"));
}

TEST(TEKS_TEST, Operasi_Perkalian) {
	ncpp::teks var("A");
	ncpp::bilangan nilaix("2");
	std::cout << nilaix.ini_desimal();
	ncpp::bilangan_bulat nilaiy("3");
	EXPECT_EQ(var * nilaix * nilaiy, ncpp::teks("AAAAAA"));
}

TEST(TEKS_TEST, Operasi_Perkalian_Assigment) {
	ncpp::teks var("A");
	ncpp::bilangan nilaix("2");
	ncpp::bilangan_bulat nilaiy("3");
	var *= nilaix;
	var *= nilaiy;
	EXPECT_EQ(var, ncpp::teks("AAAAAA"));
}

TEST(TEKS_TEST, Operasi_Persamaan) {
	{
		ncpp::teks var1("Fern");
		ncpp::teks var2("Fern");
		EXPECT_TRUE(var1 == var2);
	}
	{
		ncpp::teks var1("Fern");
		ncpp::teks var2("Fernn");
		EXPECT_FALSE(var1 == var2);
	}
}

TEST(TEKS_TEST, Operasi_Pertidaksamaan) {
	{
		ncpp::teks var1("Fern");
		ncpp::teks var2("Aerell");
		EXPECT_TRUE(var1 != var2);
	}
	{
		ncpp::teks var1("Fern");
		ncpp::teks var2("Fern");
		EXPECT_FALSE(var1 != var2);
	}
}

TEST(TEKS_TEST, Fungsi_Ubah_Ke_String) {
	ncpp::teks var1("Fern");
	std::string var_str = var1.ubah_ke_string();
	EXPECT_EQ(var_str, "Fern");
}

TEST(TEKS_TEST, Fungsi_Ubah_Ke_C_String) {
	ncpp::teks var1("Fern");
	std::string var_c_str = var1.ubah_ke_c_string();
	EXPECT_EQ(var_c_str, "Fern");
}

TEST(TEKS_TEST, Fungsi_Jumlah) {
	ncpp::teks var1("Fern");
	EXPECT_EQ(var1.jumlah(), 4);
}

TEST(TEKS_TEST, Operasi_Mengambil_Karakter) {
	ncpp::teks var1("Fern");
	EXPECT_EQ(var1[2], 'e');
}

TEST(TEKS_TEST, Fungsi_Cari) {
	ncpp::teks var1("Ferne");
	EXPECT_EQ(var1.cari("r"), 3);
	EXPECT_EQ(var1.cari("e", 3), 5);
}

TEST(TEKS_TEST, Fungsi_Ganti) {
	ncpp::teks var1("Ferne");
	var1.ganti("e", "a");
	EXPECT_EQ(var1, ncpp::teks("Farne"));
}

TEST(TEKS_TEST, Fungsi_Ganti_Semua) {
	ncpp::teks var1("Ferne");
	var1.ganti_semua("e", "a");
	EXPECT_EQ(var1, ncpp::teks("Farna"));
}