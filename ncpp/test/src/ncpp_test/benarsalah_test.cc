#include "ncpp/tipe_data/benarsalah.h"
#include <gtest/gtest.h>
#include <ncpp/ncpp.h>

TEST(BENARSALAH_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::benarsalah var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "salah");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(false);
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "benar\nsalah\n");	
	myKonsol.bersihkan();
}

TEST(BENARSALAH_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(var1);
	ncpp::benarsalah var3(salah);
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "benar\nbenar\nsalah\n");
}

TEST(BENARSALAH_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1 = benar;
	ncpp::benarsalah var2 = var1;
	ncpp::benarsalah var3(salah);
	ncpp::benarsalah var4 = false;
	var4 = true;
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	myKonsol.cetak_baris_baru(var4);
	EXPECT_EQ(myKonsol.isi(), "benar\nbenar\nbenar\nbenar\n");
}

TEST(BENARSALAH_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "benar\n");
}

TEST(BENARSALAH_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1(false);
	ncpp::benarsalah var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "salah\n");
}

TEST(BENARSALAH_TEST, Fungsi_Ubah_Ke_String) {
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(false);
	EXPECT_EQ(var1.ubah_ke_string(), "benar");
	EXPECT_EQ(var2.ubah_ke_string(), "salah");
}

TEST(BENARSALAH_TEST, Fungsi_Ubah_Ke_Bool) {
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(false);
	EXPECT_EQ(var1.ubah_ke_bool(), true);
	EXPECT_EQ(var2.ubah_ke_bool(), false);
}

TEST(BENARSALAH_TEST, Operasi_Bool) {
	ncpp::benarsalah var1(true);
	ncpp::benarsalah var2(false);
	EXPECT_TRUE(var1);
	EXPECT_FALSE(var2);
}

TEST(BENARSALAH_TEST, Operasi_Persamaan) {
	EXPECT_TRUE(benar == benar);
	EXPECT_TRUE(salah == salah);
	EXPECT_FALSE(benar == salah);
	EXPECT_FALSE(salah == benar);
	EXPECT_TRUE(benar == true);
	EXPECT_TRUE(salah == false);
	EXPECT_FALSE(benar == false);
	EXPECT_FALSE(salah == true);
	EXPECT_TRUE(true == benar);
	EXPECT_TRUE(false == salah);
	EXPECT_FALSE(true == salah);
	EXPECT_FALSE(false == benar);
}

TEST(BENARSALAH_TEST, Operasi_Pertidaksamaan) {
	EXPECT_TRUE(benar != salah);
	EXPECT_TRUE(salah != benar);
	EXPECT_FALSE(benar != benar);
	EXPECT_FALSE(salah != salah);
	EXPECT_TRUE(benar != false);
	EXPECT_TRUE(salah != true);
	EXPECT_FALSE(benar != true);
	EXPECT_FALSE(salah != false);
	EXPECT_TRUE(false != benar);
	EXPECT_TRUE(true != salah);
	EXPECT_FALSE(false != salah);
	EXPECT_FALSE(true != benar);
}

TEST(BENARSALAH_TEST, Operasi_Logika_Tidak) {
	EXPECT_TRUE(!salah);
	EXPECT_FALSE(!benar);
}

TEST(BENARSALAH_TEST, Operasi_Logika_Dan) {
	EXPECT_TRUE(benar && benar);
	EXPECT_FALSE(benar && salah);
	EXPECT_TRUE(benar && true);
	EXPECT_FALSE(benar && false);
	EXPECT_TRUE(true && benar);
	EXPECT_FALSE(false && salah);
}

TEST(BENARSALAH_TEST, Operasi_Logika_Atau) {
	EXPECT_TRUE(benar || benar);
	EXPECT_TRUE(benar || salah);
	EXPECT_TRUE(salah || benar);
	EXPECT_FALSE(salah || salah);
	EXPECT_TRUE(benar || true);
	EXPECT_TRUE(benar || false);
	EXPECT_TRUE(salah || true);
	EXPECT_FALSE(salah || false);
	EXPECT_TRUE(true || benar);
	EXPECT_TRUE(true || salah);
	EXPECT_TRUE(false || benar);
	EXPECT_FALSE(false || salah);
}
