# Fungsi

Fungsi adalah tempat untuk menyimpan kumpulan intruksi yang akan di eksekusi ketika fungsi itu di panggil.

Sintaks :
```nusantara
tipedata namaFungsi(parameter) {
    // Kode yang akan di 
    // eksekusi ketika 
    // fungsi di panggil
}
```

## Fungsi yang mengeluarkan sesuatu

Contoh :
```nusantara
bilangan tambah(bilangan x, bilangan y) {
    keluar x + y;
}

cetak(tambah(10, 5));
```
Hasil :
```
15
```

## Fungsi yang tidak mengeluarkan sesuatu

Untuk membuat fungsi yang tidak akan mengeluarkan sesuatu kita tinggal tidak menulis tipedata yang akan
di keluarkan.

Contoh :
```nusantara
tambah(bilangan x, bilangan y) {
    cetak(x + y);
}

tambah(10, 5);
```
Hasil :
```
15
```

## Fungsi dengan nilai parameter bawaan

Contoh :
```nusantara
tambah(bilangan x = 10, bilangan y) {
    cetak(x + y);
}

tambah(5);
```
Hasil :
```
15
```

## Memanggil fungsi

Contoh :
```nusantara
tambah(bilangan x = 20, bilangan y = 3) {
    cetak(x + y);
}

tambah(10, 5);
tambah(5);
tambah(x: 10, y: 2);
tambah();
```
Hasil :
```
15
25
12
23
```