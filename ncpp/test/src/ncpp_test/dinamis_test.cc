#include "ncpp/tipe_data/dinamis.h"
#include <gtest/gtest.h>
#include <string>
#include "ncpp/konsol/konsol.h"

TEST(DINAMIS_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::dinamis var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "kosong");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::dinamis var2("Fern");
	myKonsol.cetak(var2);
	EXPECT_EQ(myKonsol.isi(), "Fern");
	myKonsol.bersihkan();
}

TEST(DINAMIS_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::dinamis var1("Aerell");
	ncpp::dinamis var2(var1);
	ncpp::dinamis var3(ncpp::dinamis("Fern"));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "Aerell\nAerell\nFern\n");
}

TEST(DINAMIS_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::dinamis var1 = ncpp::dinamis("Aerell");
	ncpp::dinamis var2 = var1;
	ncpp::dinamis var3(ncpp::dinamis("Fern"));
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "Aerell\nAerell\nAerell\n");
}

TEST(DINAMIS_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::dinamis var1("Chezca");
	ncpp::dinamis var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Chezca\n");
}

TEST(DINAMIS_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::dinamis var1("Zoro");
	ncpp::dinamis var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "Zoro\n");
}

TEST(DINAMIS_TEST, Fungsi_Ubah_Ke_String) {
	ncpp::dinamis var1("Fern");
	std::string var_str = var1.ubah_ke_string();
	EXPECT_EQ(var_str, "Fern");
}

TEST(DINAMIS_TEST, Fungsi_Static_Ini) {
	ncpp::dinamis var1("Fern");
	EXPECT_TRUE(ncpp::dinamis::ini<const char*>(var1));
	EXPECT_FALSE(ncpp::dinamis::ini<int>(var1));
}

TEST(DINAMIS_TEST, Fungsi_Ini) {
	ncpp::dinamis var1("Fern");
	EXPECT_TRUE(var1.ini<const char*>());
	EXPECT_FALSE(var1.ini<int>());
}

TEST(DINAMIS_TEST, Fungsi_Static_Sebagai) {
	ncpp::dinamis var1("Fern");
	EXPECT_EQ(ncpp::dinamis::sebagai<const char*>(var1), "Fern");
	ncpp::dinamis::sebagai<const char*>(var1) = "halo";
	EXPECT_EQ(ncpp::dinamis::sebagai<const char*>(var1), "halo");
}

TEST(DINAMIS_TEST, Fungsi_Sebagai) {
	ncpp::dinamis var1("Fern");
	EXPECT_EQ(var1.sebagai<const char*>(), "Fern");
	var1.sebagai<const char*>() = "halo";
	EXPECT_EQ(var1.sebagai<const char*>(), "halo");
}