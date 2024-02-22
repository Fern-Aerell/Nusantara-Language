#  Fitur yang akan dibuat.
- [X] Nusantara mendukung operasi bit.
- [X] Nusantara mendukung operasi kondisional.
- [ ] Nusantara mendukung deklarasi variable.
- [ ] Nusantara mendukung ekspresi fungsi.

# 1.11.6-Indev (18 Feb 2024)

### Sdk (nusantara)
- Menambahkan file changelog.

# 1.10.6-Indev (18 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Menambahkan nilai kalimat context.
- Perubahan
    - Membuat lexer mendukung kalimat interpolasi.
    - Membuat parser mendukung kalimat interpolasi.
    - Membuat interpreter mendukung kalimat interpolasi.
- Perbaikan
    - Memperbaiki include error pada kalimat.h saat compile di termux.

# 1.6.5-Indev (15 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Perubahan
    - Memecah file core.h dan konsol.h menjadi beberapa file yang ada di folder include/nstd.
    - Membuat semua file yang ada di src dan include mendukung pemecahan dari file 'core.h' dan 'konsol.h'.

# 1.4.5-Indev (14 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Design
- Merubah beberapa konsep design.
- Menghapus beberapa konsep design.

# 1.2.5-Indev (12 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Perubahan
    - Membuat .clang-format dengan aturan yang baru.
    - Memformat semua file.
- Perbaikan
    - Memperbaiki kesalahan lexer saat mengenerate token dari input yg berisi '==' dan '!='.
    - Memperbaiki beberapa kejadian yang tidak di inginkan pada class cli.

# 1.0.3-Indev (11 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Membuat context dengan mekanisme baru dan unique_ptr.
    - Menambah file konsol dan 'debug.gdb'.
    - Menambahkan interpreter.
    - Membuat parser agar memberikan info kalau ada karakter yang tidak di kenali.
    - Membuat class interpreter membutuhkan error_info.
    - Menambahkan file 'clang-format-all.sh'.
    - Membuat fungsi inLine di class errorInfo untuk menghasilkan pesan error dari daftar token.
    - Menambahkan class cli.
- Perubahan
    - Mengimplementasikan context yang baru ke visitor.
    - Merubah cara kerja lexer.
    - Merubah isi '.clang-format'.
    - Merubah isi '.clang-tidy'.
    - Memformat semua file.
- Penghapusan
    - Menghapus file 'build.bat'.
- Perbaikan
    - Memperbaiki masalah bad option.
    - Memperbaiki masalah saat proses linking di termux.
    - Memperbaiki beberapa bug yang ditemukan.

# 0.13.0-Indev (5 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Menambahkan file 'core.h'.
- Perubahan
    - Mengembalikan bentuk visitor ke sebelumnya.
- Penghapusan
    - Menghapus semua context.

# 0.10.0-Indev (4 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Menambahkan context untuk visitor.
- Perubahan
    - Merubah struktur folder src dan include.
    - Merubah cara kerja visitor.

# 0.7.0-Indev (3 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Menambahkan parser.
    - Menambahkan visitor.
- Pembaruan
    - Memperbarui beberapa kode file.

# 0.4.0-Indev (2 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Penambahan
    - Menambahkan error_info untuk membuat format pesan error.
    - Menambahkan parser_tree untuk parser.
- Pembaruan
    - Memperbarui cara kerja lexer.

# 0.1.0-Indev (1 Feb 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

### Sdk (nusantara)
- Menambahkan fungsi readFile ke dalam file utils.

# 0.0.0-Indev (30 Jan 2024)

Note : Changelog mungkin tidak lengkap dikarenakan file changelog ini dibuat pada 18 Feb 2024, dan kami hanya mendata melalui commit di github.

Versi pertama dan pertama kali project ini dibuat.

- Setup workspace project

### Design (konsep)
- Menambahkan beberapa konsep design untuk bahasa nusantara.

### Sdk (nusantara)
- Menambahkan folder sdk.
- Menambahkan beberapa file pendukung untuk folder sdk.
- Menambahkan build.bat untuk build project otomatis di windows.
- Menambahkan file utils.
- Menambahkan lexer.