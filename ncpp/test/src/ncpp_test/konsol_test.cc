#include "ncpp/konsol/konsol.h"
#include <gtest/gtest.h>

TEST(KONSOL_TEST, Isi) {
    ncpp::konsol myKonsol;
    myKonsol.cetak("Ini adalah isi dari konsol");
    EXPECT_EQ(myKonsol.isi(), "Ini adalah isi dari konsol");
}

TEST(KONSOL_TEST, Cetak) {
    ncpp::konsol myKonsol;
    myKonsol.cetak("Halo Dunia!");
    EXPECT_EQ(myKonsol.isi(), "Halo Dunia!");
}

TEST(KONSOL_TEST, Cetak_Baris_Baru) {
    ncpp::konsol myKonsol;
    myKonsol.cetak_baris_baru("Halo Dunia!");
    EXPECT_EQ(myKonsol.isi(), "Halo Dunia!\n");
}

TEST(KONSOL_TEST, Bersihkan) {
    ncpp::konsol myKonsol;
    myKonsol.cetak_baris_baru("Halo Dunia!");
    myKonsol.bersihkan();
    EXPECT_EQ(myKonsol.isi(), "");
}
