# Muat

Muat adalah sebuah kata kunci untuk mengimport file external di nusantara.

## Sintaks
```nusantara
muat 'filepath';
```

## Cara kerja

Contoh kita punya file operasi_file.nl
```nusantara
// operasi_file.nl

tambah(bulat a, bulat b) {
    keluar a + b;
}
```

Dan kita memuatnya ke file main.nl
```nusantara
// main.nl
muat 'operasi_file.nl';

awal {
 cetak(tambah(1, 5));
}
```

Itu sama saja seperti kita membuat nya seperti ini
```nusantara
tambah(bulat a, bulat b) {
    keluar a + b;
}

awal {
    cetak(tambah(1, 5));
}
```

## Aturan

Untuk memuat file tidak harus di baris paling atas
kalian bisa menaruh nya dikawasan mana aja, 
contoh nya di blok kode
```nusantara
aerell {
    muat 'file.nl';
}
```
