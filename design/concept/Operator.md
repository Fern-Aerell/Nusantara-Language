# Nusantara Operator

Operator di nusantara di bagi menjadi beberapa jenis :
| Jenis |
| ----- |
| [Aritmatika Operator](#aritmatika-operator) |
| [Penugasan Operator](#penugasan-operator) |
| [Perbandingan Operator](#perbandingan-operator) |
| [Logika Operator](#logika-operator) |
| [Bitwise Operator](#bitwise-operator) |

## Aritmatika Operator

| Operator | Nama | Deskripsi | Contoh |
| -------- | ---- | --------- | ------ |
| + | Tambah | Menambahkan 2 nilai secara bersamaan | x + y |
| - | Kurang | Mengurangi 1 nilai dari yang lain | x - y |
| * | Kali | Mengkalikan 2 nilai | x * y |
| / | Bagi | Membagi 1 nilai dengan yang lain | x / y |
| % | Sisa bagi | Menghasilkan sisa dari pembagian | x % y |
| ++ | Tambah satu | Menambah 1 dari suatu nilai | x++ |
| -- | Kurang satu | Mengurangi 1 dari suatu nilai | x-- |

## Penugasan Operator

| Operator | Contoh |
| -------- | ------ |
| = | x = y |
| += | x += y |
| -= | x -= y |
| *= | x *= y |
| /= | x /= y |
| %= | x %= y |
| &= | x & y |
| \|= | x \|= y |
| ^= | x ^= y |
| ~= | x ~= y |
| <<= | x <<= y |
| >>= | x >>= y |

## Perbandingan Operator

| Operator | Nama | Contoh |
| -------- | ---- | ------ |
| == | Sama dengan | x == y |
| != | Tidak sama dengan | x != y |
| > | Lebih besar dari | x > y |
| < | Lebih kecil dari | x < y |
| >= | Lebih besar dari atau sama dengan | x >= y |
| <= | Lebih kecil dari atau sama dengan | x <= y |

## Logika Operator

| Operator | Nama | Deskripsi | Contoh |
| -------- | ---- | --------- | ------ |
| && | Dan | Mengeluarkan ```benar``` jika ke-2 pernyataan ```benar``` | x && y |
| \|\| | Atau | Mengeluarkan ```benar``` jika salah satu pernyataan ```benar``` | x \|\| y |
| ! | Tidak | Mengeluarkan kebalikan nya, ```benar``` jika ```salah``` | !x |

## Bitwise Operator

| Operator | Nama | Contoh |
| -------- | ---- | ------ |
| & | AND Bit | x & y |
| \| | OR Bit | x \| y |
| ^ | XOR Bit | x ^ y |
| ~ | NOT Bit | x ~ y |
| << | Pergeseran Kiri Bit | x << y |
| >> | Pergeseran Kanan Bit| x >> y |

## Urutan Operator

Urutan operator yang Anda berikan adalah sebagai berikut, dengan operator yang memiliki prioritas yang lebih tinggi ditempatkan lebih awal:

1. `++` (Increment)
2. `--` (Decrement)
3. `~` (Bitwise NOT)
4. `!` (Logical NOT)
5. `*` (Multiplication)
6. `/` (Division)
7. `%` (Modulus)
8. `+` (Addition)
9. `-` (Subtraction)
10. `<<` (Bitwise Left Shift)
11. `>>` (Bitwise Right Shift)
12. `<` (Less Than)
13. `<=` (Less Than or Equal To)
14. `>` (Greater Than)
15. `>=` (Greater Than or Equal To)
16. `==` (Equal To)
17. `!=` (Not Equal To)
18. `&` (Bitwise AND)
19. `^` (Bitwise XOR)
20. `|` (Bitwise OR)
21. `&&` (Logical AND)
22. `||` (Logical OR)
23. `=` (Assignment)
26. `*=` (Multiplication Assignment)
27. `/=` (Division Assignment)
28. `%=` (Modulus Assignment)
24. `+=` (Addition Assignment)
25. `-=` (Subtraction Assignment)
29. `&=` (Bitwise AND Assignment)
30. `|=` (Bitwise OR Assignment)
31. `^=` (Bitwise XOR Assignment)
32. `<<=` (Bitwise Left Shift Assignment)
33. `>>=` (Bitwise Right Shift Assignment)

Perlu diingat bahwa urutan ini berdasarkan pada standar umum. Beberapa bahasa pemrograman dapat memiliki aturan yang sedikit berbeda atau mendukung operator tambahan yang tidak ada dalam daftar ini. Juga, penggunaan tanda kurung bisa memodifikasi urutan evaluasi.