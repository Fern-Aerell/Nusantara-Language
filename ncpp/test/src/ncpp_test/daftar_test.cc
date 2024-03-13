#include "ncpp/tipe_data/daftar.h"
#include <gtest/gtest.h>
#include "ncpp/batas_jumlah.h"
#include "ncpp/konsol/konsol.h"

TEST(DAFTAR_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::daftar<int> var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "[]");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::daftar<int> var1({1,2,3, 3});
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3, 3]\n");
	myKonsol.bersihkan();
	// Constructor 3
	ncpp::daftar<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n");
	myKonsol.bersihkan();
	// Constructor 4
	ncpp::daftar<int> var3(ncpp::batas_jumlah(3, 3), {1,2,3});
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n");
	myKonsol.bersihkan();
}

TEST(DAFTAR_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	ncpp::daftar<int> var2(var1);
	ncpp::daftar<int> var3;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n[1, 2, 3]\n[]\n");
}

TEST(DAFTAR_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1 = ncpp::daftar<int>({1,2,3});
	ncpp::daftar<int> var2 = var1;
	ncpp::daftar<int> var3;
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n[1, 2, 3]\n[1, 2, 3]\n");
}

TEST(DAFTAR_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	ncpp::daftar<int> var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n");
}

TEST(DAFTAR_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	ncpp::daftar<int> var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n");
}

TEST(DAFTAR_TEST, Fungsi_Ubah_Ke_Teks) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1.ubah_ke_teks());
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n");
}

TEST(DAFTAR_TEST, Fungsi_Jumlah) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1.jumlah());
	EXPECT_EQ(myKonsol.isi(), "3\n");
}

TEST(DAFTAR_TEST, Operasi_Mendapatkan_Nilai) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	for(const int& element : var1) {
		myKonsol.cetak_baris_baru(element);
	}
	EXPECT_EQ(myKonsol.isi(), "1\n2\n3\n");
}

TEST(DAFTAR_TEST, Fungsi_Hapus) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	var1.hapus(2);
	myKonsol.cetak(var1);
	EXPECT_EQ(myKonsol.isi(), "[1, 3]");
}

TEST(DAFTAR_TEST, Fungsi_Tambah) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1);
	var1.tambah(19);
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "[1, 2, 3]\n[1, 2, 3, 19]\n");
}

TEST(DAFTAR_TEST, Fungsi_Berisi) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	EXPECT_TRUE(var1.berisi(3));
	EXPECT_FALSE(var1.berisi(4));
}

TEST(DAFTAR_TEST, Fungsi_Ini_Kosong) {
	ncpp::daftar<int> var1;
	ncpp::daftar<int> var2({1,2,3});
	EXPECT_TRUE(var1.ini_kosong());
	EXPECT_FALSE(var2.ini_kosong());
}

TEST(DAFTAR_TEST, Fungsi_Ini_Tidak_Kosong) {
	ncpp::daftar<int> var1({1,2,3});
	ncpp::daftar<int> var2;
	EXPECT_TRUE(var1.ini_tidak_kosong());
	EXPECT_FALSE(var2.ini_tidak_kosong());
}

TEST(DAFTAR_TEST, Operasi_Persamaan) {
	{
		ncpp::daftar<int> var1({1,2,3});
		ncpp::daftar<int> var2({1,2,3});
		EXPECT_TRUE(var1 == var2);
	}
	{
		ncpp::daftar<int> var1({1,2,3});
		ncpp::daftar<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_FALSE(var1 == var2);
	}
}

TEST(DAFTAR_TEST, Operasi_Pertidaksamaan) {
	{
		ncpp::daftar<int> var1({1,2,3});
		ncpp::daftar<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_TRUE(var1 != var2);
	}
	{
		ncpp::daftar<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		ncpp::daftar<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
		EXPECT_FALSE(var1 != var2);
	}
}

TEST(DAFTAR_TEST, Fungsi_Ada_Batas_Jumlah) {
	ncpp::daftar<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	ncpp::daftar<int> var2({1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah());
	EXPECT_FALSE(var2.ada_batas_jumlah());
}

TEST(DAFTAR_TEST, Fungsi_Ada_Batas_Jumlah_Minimal) {
	ncpp::daftar<int> var1(ncpp::batas_jumlah_minimal(3), {1,2,3});
	ncpp::daftar<int> var2(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah_minimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_minimal());
}

TEST(DAFTAR_TEST, Fungsi_Ada_Batas_Jumlah_maksimal) {
	ncpp::daftar<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	ncpp::daftar<int> var2(ncpp::batas_jumlah_minimal(3), {1,2,3});
	EXPECT_TRUE(var1.ada_batas_jumlah_maksimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_maksimal());
}

TEST(DAFTAR_TEST, Fungsi_Batas_Jumlah_Minimal) {
	ncpp::daftar<int> var1(ncpp::batas_jumlah_minimal(3), {1,2,3});
	EXPECT_EQ(var1.batas_jumlah_minimal(), 3);
}

TEST(DAFTAR_TEST, Fungsi_Batas_Jumlah_maksimal) {
	ncpp::daftar<int> var1(ncpp::batas_jumlah_maksimal(3), {1,2,3});
	EXPECT_EQ(var1.batas_jumlah_maksimal(), 3);
}

TEST(DAFTAR_TEST, Operasi_Mengambil_data) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1[2]);
	EXPECT_EQ(myKonsol.isi(), "2\n");
}

TEST(DAFTAR_TEST, Operasi_Mengubah_Data) {
	ncpp::konsol myKonsol;
	ncpp::daftar<int> var1({1,2,3});
	myKonsol.cetak_baris_baru(var1[3]);
	var1[3] = 5;
	myKonsol.cetak_baris_baru(var1[3]);
	EXPECT_EQ(myKonsol.isi(), "3\n5\n");
}