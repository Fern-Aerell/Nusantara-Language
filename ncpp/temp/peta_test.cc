#include "ncpp/tipe_data/peta.h"
#include <gtest/gtest.h>
#include <string>
#include "ncpp/batas_jumlah.h"
#include "ncpp/konsol/konsol.h"

TEST(PETA_TEST, Constructor) {
	ncpp::konsol myKonsol;
	// Constructor 1
	ncpp::peta<std::string, std::string> var;
	myKonsol.cetak(var);
	EXPECT_EQ(myKonsol.isi(), "{}");
	myKonsol.bersihkan();
	// Constructor 2
	ncpp::peta<std::string, std::string> var1({{"nama", "Aerell"}});
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "{nama: Aerell}\n");
	myKonsol.bersihkan();
	// Constructor 3
	ncpp::peta<std::string, std::string> var2(
		ncpp::batas_jumlah_maksimal(3), 
		{
			{"nama", "Aerell"},
			{"umur", "18"},
			{"kelas", "XI PPLG"}
		}
	);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "{kelas: XI PPLG, nama: Aerell, umur: 18}\n");
	myKonsol.bersihkan();
	// Constructor 4
	ncpp::peta<std::string, std::string> var3(
		ncpp::batas_jumlah(3, 3),
		{
			{"nama", "Aerell"},
			{"umur", "18"},
			{"kelas", "XI PPLG"}
		}
	);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "{kelas: XI PPLG, nama: Aerell, umur: 18}\n");
	myKonsol.bersihkan();
}

TEST(PETA_TEST, Copy_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{1, 2}});
	ncpp::peta<int, int> var2(var1);
	ncpp::peta<int, int> var3;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "{1: 2}\n{1: 2}\n{}\n");
}

TEST(PETA_TEST, Copy_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1 = ncpp::peta<int, int>({{3, 2}});
	ncpp::peta<int, int> var2 = var1;
	ncpp::peta<int, int> var3;
	var3 = var1;
	myKonsol.cetak_baris_baru(var1);
	myKonsol.cetak_baris_baru(var2);
	myKonsol.cetak_baris_baru(var3);
	EXPECT_EQ(myKonsol.isi(), "{3: 2}\n{3: 2}\n{3: 2}\n");
}

TEST(PETA_TEST, Move_Constructor) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{5, 2}});
	ncpp::peta<int, int> var2(std::move(var1));
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "{5: 2}\n");
}

TEST(PETA_TEST, Move_Assigment_Operator) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{3, 66}});
	ncpp::peta<int, int> var2 = std::move(var1);
	myKonsol.cetak_baris_baru(var2);
	EXPECT_EQ(myKonsol.isi(), "{3: 66}\n");
}

TEST(PETA_TEST, Fungsi_Ubah_Ke_Teks) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	myKonsol.cetak_baris_baru(var1.ubah_ke_teks());
	EXPECT_EQ(myKonsol.isi(), "{20: 11}\n");
}

TEST(PETA_TEST, Fungsi_Jumlah) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	myKonsol.cetak_baris_baru(var1.jumlah());
	EXPECT_EQ(myKonsol.isi(), "1\n");
}

TEST(PETA_TEST, Operasi_Mendapatkan_Nilai) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	for(const auto& element : var1) {
		myKonsol.cetak_baris_baru(element.second);
	}
	EXPECT_EQ(myKonsol.isi(), "11\n");
}

TEST(PETA_TEST, Fungsi_Hapus) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	var1.hapus(20);
	myKonsol.cetak(var1);
	EXPECT_EQ(myKonsol.isi(), "{}");
}

TEST(PETA_TEST, Fungsi_Tambah) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	myKonsol.cetak_baris_baru(var1);
	var1.tambah(19, 25);
	myKonsol.cetak_baris_baru(var1);
	EXPECT_EQ(myKonsol.isi(), "{20: 11}\n{19: 25, 20: 11}\n");
}

TEST(PETA_TEST, Fungsi_Berisi_Kata_Kunci) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	EXPECT_TRUE(var1.berisi_kata_kunci(20));
	EXPECT_FALSE(var1.berisi_kata_kunci(4));
}

TEST(PETA_TEST, Fungsi_Ini_Kosong) {
	ncpp::peta<int, int> var1;
	ncpp::peta<int, int> var2({{20, 11}});
	EXPECT_TRUE(var1.ini_kosong());
	EXPECT_FALSE(var2.ini_kosong());
}

TEST(PETA_TEST, Fungsi_Ini_Tidak_Kosong) {
	ncpp::peta<int, int> var1({{20, 11}});
	ncpp::peta<int, int> var2;
	EXPECT_TRUE(var1.ini_tidak_kosong());
	EXPECT_FALSE(var2.ini_tidak_kosong());
}

TEST(PETA_TEST, Operasi_Persamaan) {
	{
		ncpp::peta<int, int> var1({{20, 11}});
		ncpp::peta<int, int> var2({{20, 11}});
		EXPECT_TRUE(var1 == var2);
	}
	{
		ncpp::peta<int, int> var1({{20, 11}});
		ncpp::peta<int, int> var2(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
		EXPECT_FALSE(var1 == var2);
	}
}

TEST(PETA_TEST, Operasi_Pertidaksamaan) {
	{
		ncpp::peta<int, int> var1({{20, 11}});
		ncpp::peta<int, int> var2(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
		EXPECT_TRUE(var1 != var2);
	}
	{
		ncpp::peta<int, int> var1(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
		ncpp::peta<int, int> var2(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
		EXPECT_FALSE(var1 != var2);
	}
}

TEST(PETA_TEST, Fungsi_Ada_Batas_Jumlah) {
	ncpp::peta<int, int> var1(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
	ncpp::peta<int, int> var2({{20, 11}});
	EXPECT_TRUE(var1.ada_batas_jumlah());
	EXPECT_FALSE(var2.ada_batas_jumlah());
}

TEST(PETA_TEST, Fungsi_Ada_Batas_Jumlah_Minimal) {
	ncpp::peta<int, int> var1(ncpp::batas_jumlah_minimal(3), {{20, 11}, {24, 30}, {21, 44}});
	ncpp::peta<int, int> var2(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
	EXPECT_TRUE(var1.ada_batas_jumlah_minimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_minimal());
}

TEST(PETA_TEST, Fungsi_Ada_Batas_Jumlah_maksimal) {
	ncpp::peta<int, int> var1(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
	ncpp::peta<int, int> var2(ncpp::batas_jumlah_minimal(3), {{20, 11}, {24, 30}, {21, 44}});
	EXPECT_TRUE(var1.ada_batas_jumlah_maksimal());
	EXPECT_FALSE(var2.ada_batas_jumlah_maksimal());
}

TEST(PETA_TEST, Fungsi_Batas_Jumlah_Minimal) {
	ncpp::peta<int, int> var1(ncpp::batas_jumlah_minimal(3), {{20, 11}, {24, 30}, {21, 44}});
	EXPECT_EQ(var1.batas_jumlah_minimal(), 3);
}

TEST(PETA_TEST, Fungsi_Batas_Jumlah_maksimal) {
	ncpp::peta<int, int> var1(ncpp::batas_jumlah_maksimal(3), {{20, 11}});
	EXPECT_EQ(var1.batas_jumlah_maksimal(), 3);
}

TEST(PETA_TEST, Operasi_Mengambil_data) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	myKonsol.cetak_baris_baru(var1[20]);
	EXPECT_EQ(myKonsol.isi(), "11\n");
}

TEST(PETA_TEST, Operasi_Mengubah_Data) {
	ncpp::konsol myKonsol;
	ncpp::peta<int, int> var1({{20, 11}});
	myKonsol.cetak_baris_baru(var1[20]);
	var1[20] = 5;
	myKonsol.cetak_baris_baru(var1[20]);
	EXPECT_EQ(myKonsol.isi(), "11\n5\n");
}