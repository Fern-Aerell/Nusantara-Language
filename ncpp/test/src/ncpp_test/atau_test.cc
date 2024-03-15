#include "ncpp/tipe_data/atau.h"
#include <gtest/gtest.h>
#include <string>
#include "ncpp/konsol/konsol.h"
#include "ncpp/tipe_data/bilangan/bilangan.h"

TEST(ATAU_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::atau<int, const char*> var(10);
	myKonsol.cetak_baris_baru(var);
	var = static_cast<const char*>("halo gaess");
	myKonsol.cetak_baris_baru(var);
	EXPECT_EQ(myKonsol.isi(), "10\nhalo gaess\n");
	myKonsol.bersihkan();
}

TEST(ATAU_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::atau<int, double> var1(100);
	ncpp::atau<int, double> var2(var1);
	ncpp::atau<const char*, int> var3(ncpp::atau<const char*, int>(static_cast<const char*>("heleep")));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "100\n100\nheleep\n");
}

TEST(ATAU_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::atau<bool, int> var1 = true;
	ncpp::atau<bool, int> var2 = var1;
	ncpp::atau<std::string, ncpp::bilangan> var3(ncpp::atau<std::string, ncpp::bilangan>(ncpp::bilangan("10")));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "1\n1\n10\n");
}

TEST(ATAU_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::atau<std::string, const char*> var1(std::string("Chezca"));
	ncpp::atau<std::string, const char*> var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Chezca\n");
}

TEST(ATAU_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::atau<ncpp::bilangan, double> var1(ncpp::bilangan("10000000000000000000"));
	ncpp::atau<ncpp::bilangan, double> var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "10000000000000000000\n");
}

TEST(ATAU_TEST, Fungsi_Ubah_Ke_String) {
	ncpp::atau<std::string, const char*> var1(std::string("Chezca"));
	std::string var_str = var1.ubah_ke_string();
	EXPECT_EQ(var_str, "Chezca");
}