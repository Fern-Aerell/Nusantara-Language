#include "ncpp/tipe_data/kumpulan.h"
#include <gtest/gtest.h>
#include "ncpp/batas_jumlah.h"
#include "ncpp/konsol/konsol.h"

TEST(KUMPULAN_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::kumpulan<int> var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "[]");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::kumpulan<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
	myKonsol.bersihkan();
	// Constructor 3
	ncpp::kumpulan<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
	myKonsol.bersihkan();
	// Constructor 4
	ncpp::kumpulan<int> var3(ncpp::batas_jumlah(3, 3), {1,2,3});
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
	myKonsol.bersihkan();
}

TEST(KUMPULAN_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	ncpp::kumpulan<int> var2(var1);
	ncpp::kumpulan<int> var3;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n[3, 2, 1]\n[]\n");
}

TEST(KUMPULAN_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1 = ncpp::kumpulan<int>({1,2,3});
	ncpp::kumpulan<int> var2 = var1;
	ncpp::kumpulan<int> var3;
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n[3, 2, 1]\n[3, 2, 1]\n");
}

TEST(KUMPULAN_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	ncpp::kumpulan<int> var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
}

TEST(KUMPULAN_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	ncpp::kumpulan<int> var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
}

TEST(KUMPULAN_TEST, Fungsi_Ubah_Ke_Teks) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1.ubah_ke_teks());
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n");
}

TEST(KUMPULAN_TEST, Fungsi_Jumlah) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1.jumlah());
	EXPECT_EQ(myKonsol.isi(), "3\n");
}

TEST(KUMPULAN_TEST, Operasi_Mendapatkan_Nilai) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	for(const int& element : var1) {
		myKonsol.cetak_baris_baru(element);
	}
	EXPECT_EQ(myKonsol.isi(), "3\n2\n1\n");
}

TEST(KUMPULAN_TEST, Fungsi_Hapus) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	var1.hapus(2);
	myKonsol.cetak(var1);
	EXPECT_EQ(myKonsol.isi(), "[3, 1]");
}

TEST(KUMPULAN_TEST, Fungsi_Tambah) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1);
	var1.tambah(19);
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "[3, 2, 1]\n[19, 3, 2, 1]\n");
}

TEST(KUMPULAN_TEST, Fungsi_Berisi) {
	ncpp::konsol myKonsol;
	ncpp::kumpulan<int> var1({1,2,3});
	EXPECT_TRUE(var1.berisi(3));
	EXPECT_FALSE(var1.berisi(4));
}

TEST(KUMPULAN_TEST, Fungsi_Ini_Kosong) {
	ncpp::kumpulan<int> var1;
	ncpp::kumpulan<int> var2({1,2,3});
	EXPECT_TRUE(var1.ini_kosong());
	EXPECT_FALSE(var2.ini_kosong());
}

TEST(KUMPULAN_TEST, Fungsi_Ini_Tidak_Kosong) {
	ncpp::kumpulan<int> var1({1,2,3});
	ncpp::kumpulan<int> var2;
	EXPECT_TRUE(var1.ini_tidak_kosong());
	EXPECT_FALSE(var2.ini_tidak_kosong());
}

TEST(KUMPULAN_TEST, Operasi_Persamaan) {
	{
		ncpp::kumpulan<int> var1({1,2,3});
		ncpp::kumpulan<int> var2({1,2,3});
		EXPECT_TRUE(var1 == var2);
	}
	{
		ncpp::kumpulan<int> var1({1,2,3});
		ncpp::kumpulan<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_FALSE(var1 == var2);
	}
}

TEST(KUMPULAN_TEST, Operasi_Pertidaksamaan) {
	{
		ncpp::kumpulan<int> var1({1,2,3});
		ncpp::kumpulan<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_TRUE(var1 != var2);
	}
	{
		ncpp::kumpulan<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		ncpp::kumpulan<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_FALSE(var1 != var2);
	}
}

TEST(KUMPULAN_TEST, Fungsi_Ada_Batas_Jumlah) {
	ncpp::kumpulan<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	ncpp::kumpulan<int> var2({1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah());
	EXPECT_FALSE(var2.ada_batas_jumlah());
}

TEST(KUMPULAN_TEST, Fungsi_Ada_Batas_Jumlah_Minimal) {
	ncpp::kumpulan<int> var1(ncpp::batas_jumlah_minimal(3), {1,2,3});
	ncpp::kumpulan<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah_minimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_minimal());
}

TEST(KUMPULAN_TEST, Fungsi_Ada_Batas_Jumlah_maksimal) {
	ncpp::kumpulan<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	ncpp::kumpulan<int> var2(ncpp::batas_jumlah_minimal(3), {1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah_maksimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_maksimal());
}

TEST(KUMPULAN_TEST, Fungsi_Batas_Jumlah_Minimal) {
	ncpp::kumpulan<int> var1(ncpp::batas_jumlah_minimal(3), {1,2,3});
	EXPECT_EQ(var1.batas_jumlah_minimal(), 3);
}

TEST(KUMPULAN_TEST, Fungsi_Batas_Jumlah_maksimal) {
	ncpp::kumpulan<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	EXPECT_EQ(var1.batas_jumlah_maksimal(), 3);
}
