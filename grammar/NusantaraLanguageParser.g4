parser grammar NusantaraLanguageParser;
options { tokenVocab=NusantaraLanguageLexer; }

nusantara
    : pernyataan* EOF
    ;

pernyataan
    : buat_dan_ngisi_variable TITIK_KOMA # pernyataanBuatDanNgisiVariable
    ;

buat_dan_ngisi_variable
    : TIPE_DATA_BILANGAN_BULAT IDENTIFIKASI SAMA_DENGAN NILAI_BILANGAN_BULAT # buatDanNgisiVariableBilanganBulat
    | TIPE_DATA_BILANGAN_DESIMAL IDENTIFIKASI SAMA_DENGAN NILAI_BILANGAN_DESIMAL # buatDanNgisiVariableBilanganDesimal
    | TIPE_DATA_KARAKTER IDENTIFIKASI SAMA_DENGAN NILAI_KARAKTER # buatDanNgisiVariableKarakter
    | TIPE_DATA_KALIMAT IDENTIFIKASI SAMA_DENGAN NILAI_KALIMAT # buatDanNgisiVariableKalimat
    | TIPE_DATA_BOOLEAN IDENTIFIKASI SAMA_DENGAN NILAI_BOOLEAN # buatDanNgisiVariableBoolean
    ;