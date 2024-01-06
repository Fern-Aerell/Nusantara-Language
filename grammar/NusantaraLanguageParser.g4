parser grammar NusantaraLanguageParser;
options { tokenVocab=NusantaraLanguageLexer; }

nusantara
    : pernyataan* EOF
    ;

pernyataan
    : blok_kode
    | buat_fungsi
    | muat_file TITIK_KOMA
    | panggil_fungsi TITIK_KOMA
    | buat_variable TITIK_KOMA
    | ngisi_variable TITIK_KOMA
    | buat_dan_ngisi_variable TITIK_KOMA
    ;
    
muat_file
    : MUAT NILAI_KALIMAT
    ;
    
blok_kode
    : KURUNG_KURAWAL_BUKA pernyataan* KURUNG_KURAWAL_TUTUP
    ;
    
parameter_fungsi_kosong
    : KURUNG_BUKA KURUNG_TUTUP
    ;
    
parameter_buat_fungsi
    : parameter_fungsi_kosong
    | KURUNG_BUKA (buat_variable|buat_dan_ngisi_variable)( KOMA (buat_variable|buat_dan_ngisi_variable)*)? KURUNG_TUTUP
    ;
    
buat_fungsi
    : IDENTIFIKASI parameter_buat_fungsi blok_kode
    ;
    
parameter_panggil_fungsi
    : parameter_fungsi_kosong
    | KURUNG_BUKA (nilai_variable)( KOMA (nilai_variable)*)? KURUNG_TUTUP
    ;
    
panggil_fungsi
    : IDENTIFIKASI parameter_panggil_fungsi
    ;
    
tipe_data_variable
    : TIPE_DATA_BILANGAN_BULAT
    | TIPE_DATA_BILANGAN_DESIMAL
    | TIPE_DATA_KARAKTER
    | TIPE_DATA_KALIMAT
    | TIPE_DATA_BOOLEAN
    ;
    
buat_variable
    : tipe_data_variable IDENTIFIKASI
    ;
    
nilai_variable
    : NILAI_BILANGAN_BULAT
    | NILAI_BILANGAN_DESIMAL
    | NILAI_KARAKTER
    | NILAI_KALIMAT
    | NILAI_BOOLEAN
    ;
    
ngisi_variable
    : IDENTIFIKASI SAMA_DENGAN nilai_variable
    ;
    
buat_dan_ngisi_variable
    : TIPE_DATA_BILANGAN_BULAT IDENTIFIKASI SAMA_DENGAN NILAI_BILANGAN_BULAT
    | TIPE_DATA_BILANGAN_DESIMAL IDENTIFIKASI SAMA_DENGAN NILAI_BILANGAN_DESIMAL
    | TIPE_DATA_KARAKTER IDENTIFIKASI SAMA_DENGAN NILAI_KARAKTER
    | TIPE_DATA_KALIMAT IDENTIFIKASI SAMA_DENGAN NILAI_KALIMAT
    | TIPE_DATA_BOOLEAN IDENTIFIKASI SAMA_DENGAN NILAI_BOOLEAN
    ;