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

Tipe data ini akan menyimpan kumpulan data, seperti array dan map, kumpulan dibagi menjadi 2 yaitu kumpulan dan kumpulan asosiatif.

Sintaks :
```nusantara
// kumpulan
tipe[] namaKumpulan = [];

// kumpulan asosiatif
{key: value} namaKumpulanAsosiatif = {};
```

Contoh :
```nusantara
// kumpulan
bilangan[] kumpulanBilangan = [1, 2, 3, 4, 5];

// kumpulan asosiatif
{teks: dinamis} dataSiswa = {'nama': 'Fern', 'umur': 18};
```

## Dinamis

Tipe data ini akan menyimpan nilai dinamis.

Contoh :
```nusantara
dinamis tipeDinamis;
tipeDinamis = 10;
tipeDinamis = "Fern Aerell";
tipeDinamis = benar;
```