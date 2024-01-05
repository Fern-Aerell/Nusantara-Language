lexer grammar NusantaraLanguageLexer;

// Token untuk mengimport file
MUAT
    : 'muat'
    ;
    
// Tipe Data
TIPE_DATA_BILANGAN_BULAT
    : 'bilangan bulat'
    ;
    
TIPE_DATA_BILANGAN_DESIMAL
    : 'bilangan desimal'
    ;
    
TIPE_DATA_KARAKTER
    : 'karakter'
    ;
    
TIPE_DATA_KALIMAT
    : 'kalimat'
    ;
    
TIPE_DATA_BOOLEAN
    : 'bool' 
    ;
    
// Nilai
NILAI_BILANGAN_BULAT
    : '-' ? [0-9]+ 
    ;
    
NILAI_BILANGAN_DESIMAL
    : '-' ? [0-9]+ ',' [0-9]+ 
    ;
    
NILAI_KARAKTER
    : KUTIP_SATU . KUTIP_SATU
    | KUTIP_DUA . KUTIP_DUA
    ;
    
NILAI_KALIMAT
    : KUTIP_SATU .*? KUTIP_SATU
    | KUTIP_DUA .*? KUTIP_DUA
    ;
    
NILAI_BOOLEAN
    : 'salah'
    | 'benar'
    ;
    
// Operator
TAMBAH
    : '+' 
    ;
    
KURANG
    : '-'
    ;
    
KALI
    : '*'
    ;
    
BAGI
    : '/'
    ;
    
SISA_BAGI
    : '%'
    ;

// Other
KUTIP_SATU
    : '\''
    ;
    
KUTIP_DUA
    : '"'
    ;
    
IDENTIFIKASI
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;
    
SAMA_DENGAN
    : '='
    ;
    
TITIK_KOMA
    : ';'
    ;
    
KURUNG_BUKA
    : '('
    ;
    
KURUNG_TUTUP
    : ')'
    ;
    
KURUNG_KURAWAL_BUKA
    : '{' 
    ;
    
KURUNG_KURAWAL_TUTUP
    : '}'
    ;
    
KURUNG_SIKU_BUKA
    : '['
    ;
    
KURUNG_SIKU_TUTUP
    : ']'
    ;
    
KURANG_DARI
    : '<'
    ;
    
LEBIH_BESAR_DARI
    : '>'
    ;
    
KURANG_DARI_SAMA_DENGAN
    : '<='
    ;
    
LEBIH_BESAR_DARI_SAMA_DENGAN
    : '>='
    ;
    
TANDA_TANYA
    : '?'
    ;
    
TANDA_SERU
    : '!'
    ;
    
KOMA
    : ','
    ;
    
TITIK
    : '.'
    ;
    
DOLAR
    : '$'
    ;

// Skip
KOMENTAR_SATU_BARIS
    : '//' ~[\r\n]* -> skip
    ;
    
KOMENTAR_BANYAK_BARIS
    : '/*' .*? '*/' -> skip
    ;
    
WHITESPACE
    : [ \t\n\r\f]+ -> skip 
    ;