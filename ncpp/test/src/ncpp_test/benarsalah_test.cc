#include "ncpp/tipe_data/benarsalah.h"
#include <gtest/gtest.h>
#include <ncpp/ncpp.h>
#include <format>
#include <string>
#include "ncpp/tipe_data/teks.h"

TEST(BENARSALAH_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::benarsalah var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "salah");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::benarsalah var1("benar");
	ncpp::benarsalah var2("salah");
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "benar\nsalah\n");
	std::string nilai_var3 = "Bukan benar atau salah";
	try {
		ncpp::benarsalah var3(nilai_var3);
	} catch (const std::exception& error) {
		std::string error_str(error.what());
		EXPECT_TRUE(error_str.contains(std::format("'{}' bukanlah nilai benar atau salah.", nilai_var3)));
	}
}

TEST(BENARSALAH_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1("benar");
	ncpp::benarsalah var2(var1);
	ncpp::benarsalah var3(ncpp::benarsalah("salah"));
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "benar\nbenar\nsalah\n");
}

TEST(BENARSALAH_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1 = ncpp::benarsalah("benar");
	ncpp::benarsalah var2 = var1;
	ncpp::benarsalah var3(ncpp::benarsalah("salah"));
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "benar\nbenar\nbenar\n");
}

TEST(BENARSALAH_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1("benar");
	ncpp::benarsalah var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "benar\n");
}

TEST(BENARSALAH_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::benarsalah var1("salah");
	ncpp::benarsalah var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "salah\n");
}

TEST(BENARSALAH_TEST, Fungsi_Ubah_Ke_Teks) {
	ncpp::benarsalah var1("benar");
	ncpp::benarsalah var2("salah");
	EXPECT_EQ(var1.ubah_ke_teks(), ncpp::teks("benar"));
	EXPECT_EQ(var2.ubah_ke_teks(), ncpp::teks("salah"));
}

TEST(BENARSALAH_TEST, Operasi_Bool) {
	ncpp::benarsalah var1("benar");
	ncpp::benarsalah var2("salah");
	EXPECT_TRUE(var1);
	EXPECT_FALSE(var2);
}

TEST(BENARSALAH_TEST, Fungsi_Static_Benar) {
	EXPECT_EQ(ncpp::benarsalah::benar(), ncpp::benarsalah("benar"));
}

TEST(BENARSALAH_TEST, Fungsi_Static_Salah) {
	EXPECT_EQ(ncpp::benarsalah::salah(), ncpp::benarsalah("salah"));
}

TEST(BENARSALAH_TEST, Operasi_Persamaan) {
	EXPECT_TRUE(ncpp::benarsalah("benar") == ncpp::benarsalah("benar"));
	EXPECT_TRUE(ncpp::benarsalah("salah") == ncpp::benarsalah("salah"));
	EXPECT_FALSE(ncpp::benarsalah("benar") == ncpp::benarsalah("salah"));
	EXPECT_FALSE(ncpp::benarsalah("salah") == ncpp::benarsalah("benar"));
}

TEST(BENARSALAH_TEST, Operasi_Pertidaksamaan) {
	EXPECT_TRUE(ncpp::benarsalah("benar") != ncpp::benarsalah("salah"));
	EXPECT_TRUE(ncpp::benarsalah("salah") != ncpp::benarsalah("benar"));
	EXPECT_FALSE(ncpp::benarsalah("benar") != ncpp::benarsalah("benar"));
	EXPECT_FALSE(ncpp::benarsalah("salah") != ncpp::benarsalah("salah"));
}

TEST(BENARSALAH_TEST, Operasi_Logika_Tidak) {
	EXPECT_TRUE(!ncpp::benarsalah("salah"));
	EXPECT_FALSE(!ncpp::benarsalah("benar"));
}

TEST(BENARSALAH_TEST, Operasi_Logika_Dan) {
	EXPECT_TRUE(ncpp::benarsalah("benar") && ncpp::benarsalah("benar"));
	EXPECT_FALSE(ncpp::benarsalah("benar") && ncpp::benarsalah("salah"));
}

TEST(BENARSALAH_TEST, Operasi_Logika_Atau) {
	EXPECT_TRUE(ncpp::benarsalah("benar") || ncpp::benarsalah("benar"));
	EXPECT_TRUE(ncpp::benarsalah("benar") || ncpp::benarsalah("salah"));
	EXPECT_TRUE(ncpp::benarsalah("salah") || ncpp::benarsalah("benar"));
	EXPECT_FALSE(ncpp::benarsalah("salah") || ncpp::benarsalah("salah"));
}
