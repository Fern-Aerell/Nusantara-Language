# Variable

Variable adalah tempat untuk menyimpan nilai dari suatu tipe data.

Sintaks :
```nusantara
tipedata namaVariable;
tipedata namaVariable = nilaiTipeData;
```

Contoh membuat variable tanpa inisialisasi :
```nusantara
kalimat nama;
```

Contoh membuat variable dan inisialisasi :
```nusantara
kalimat nama = "Fern Aerell";
```

## Keamanan dari ketidak adaan atau kekosongan

Nusantara memiliki konsep null safety atau keamanan dari ketidak adaan atau kekosongan.

ketika anda membuat variable tanpa inisialisasi, itu berarti variable itu kosong.

Contoh :
```nusantara
kalimat nama;
cetak(nama);
```

Hasil :
```
kosong
```

## konstan

Kalian bisa membuat variable dengan tambahan kata kunci ```konst``` yang akan mempengaruhi bagaimana kita menggunakan variable itu nanti.

Contoh :
```nusantara
konst kalimat nama = "Fern Aerell";
```
Perilaku :
- Variable konst harus di inisialisasi.
- Variable konst hanya bisa di inisialisasi sekali.
- Variable konst isi tidak bisa di ubah.