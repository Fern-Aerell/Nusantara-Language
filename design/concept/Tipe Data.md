# Tipe Data Nusantara

Tipe data di nusantara di bagi menjadi 1 jenis
- bawaan (bilangan, teks, benarsalah, kumpulan, dinamis)

## Bilangan

Tipe data ini akan menyimpan nilai bilangan bulat atau desimal, bisa juga lebih spesifik dengan menambahkan kata kunci ```bulat``` atapun ```desimal```.

Contoh :
```nusantara
bilangan nilai = 10;
bilangan bulat umur = 18;
bilangan desimal btc = 0,5;
```

## Teks

Tipe data ini akan menyimpan nilai teks yang biasa nya di bungkus dengan kutip 1 atau 2.

Contoh :
```nusantara
teks nama = "Fern Aerell";
```

## Benarsalah

Tipe data ini akan menyimpan 2 nilai, antara benar atau salah.

Contoh :
```nusantara
benarsalah lulus = benar;
```

## Kumpulan

Tipe data ini dapat menyimpan banyak tipe data dengan configurasi tertentu.

Sintaks :
```nusantara
tipe[](configurasi) namaKumpulan1 = [];
{tipe, tipe}(configurasi) namaKumpulan2 = {};
```

Contoh :
```nusantara
bilangan[] nomor = [1, 2, 2, 4, 5];
{teks, teks} biodata = {'nama': 'aerell'}
```

## Dinamis

Tipe data ini dapat menyimpan nilai apa saja dan otomatis akan menyesuaikan tipe data nya dengan nilai yang di berikan.

Contoh :
```nusantara
dinamis tipeDinamis;
tipeDinamis = 10;
tipeDinamis = "Fern Aerell";
tipeDinamis = benar;
```
