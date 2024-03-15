# Tipe Data Nusantara

Tipe data di nusantara di bagi menjadi 1 jenis
- bawaan (bilangan, teks, atau, kumpulan, dinamis)

## Bilangan

Tipe data ini akan menyimpan nilai bilangan bulat atau desimal dengan konfigurasi tertentu, bisa juga lebih spesifik dengan menambahkan kata kunci ```bulat``` atapun ```desimal```.

Konfigurasi :
- min:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong
- maks:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong
- negatif:
    - tipe data: ya|tidak
    - nilai bawaan: ya
- tipe:
    - tipe data: (bulat|desimal)?
    - nilai bawaan: kosong

Sintaks :
```nusantara
bilangan(konfig(,konfig)*) nama;

bilangan(konfig(,konfig)*) nama = nilai;

bilangan konfig* nama;

bilangan konfig* nama = nilai;
```

Contoh :
```nusantara
bilangan(negatif: tidak) nilai = 10;

bilangan(negatif: ya, min:5) nilai = 1; // error: karena nilai minimal 5

bilangan !negatif min:10 maks:20 bulat umur = 18;

bilangan desimal btc = 0,5;
```

## Teks

Tipe data ini akan menyimpan nilai teks yang biasa nya di bungkus dengan kutip 1 atau 2 dengan konfigurasi tertentu.

Konfigurasi :
- min:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong
- maks:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong

Sintaks :
```nusantara
teks(konfig(,konfig)*) nama;

teks(konfig(,konfig)*) nama = nilai;

teks konfig* nama;

teks konfig* nama = nilai;
```

Contoh :
```nusantara
teks nama = "Fern Aerell";

teks min:30 deskripsi = "Ini adalah sebuah deskripsi"; // error: karena minimal 30 karakter
```

## Atau

Tipe data ini dapat menyimpan salah satu dari beberapa tipe yang telah ditentukan, minimal 2.

Konfigurasi :
- tidak ada

Sintaks :
```nusantara
(tipe|tipe(|tipe)*) nama;

(tipe|tipe(|tipe)*) nama = nilai;

tipe|tipe(|tipe)* nama;

tipe|tipe(|tipe)* nama = nilai;
```

Contoh :
```nusantara
bilangan|teks var = 10;

var = "waduh"
```

## Kumpulan

Tipe data ini dapat menyimpan banyak tipe data dengan konfigurasi tertentu.

Konfigurasi :
- min:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong
- maks:
    - tipe data: bilangan? bulat
    - nilai bawaan: kosong
- berurutan:
    - tipe data: ya|tidak
    - nilai bawaan: ya
- duplikasi:
    - tipe data: ya|tidak
    - nilai bawaan: tidak

Sintaks :
```nusantara
tipe[](konfig(,konfig)*) nama = [];

tipe[](konfig(,konfig)*) nama;

tipe[] konfig* nama = [];

tipe[] konfig* nama;

{tipe, tipe}(konfig(,konfig)*) nama = {};

{tipe, tipe}(konfig(,konfig)*) nama;

{tipe, tipe} konfig* nama = {};

{tipe, tipe} konfig* nama;
```

Contoh :
```nusantara
bilangan[] nomor = [1, 2, 2, 4, 5];

{teks, teks} biodata = {'nama': 'aerell'}
```

## Dinamis

Tipe data ini dapat menyimpan nilai apa saja dan otomatis akan menyesuaikan tipe data nya dengan nilai yang di berikan.

Konfigurasi :
- tidak ada

Sintaks :
```nusantara
dinamis nama;

dinamis nama = nilai;

dinamis nama;

dinamis nama = nilai;
```

Contoh :
```nusantara
dinamis tipeDinamis;

tipeDinamis = 10;

tipeDinamis = "Fern Aerell";

tipeDinamis = benar;
```
