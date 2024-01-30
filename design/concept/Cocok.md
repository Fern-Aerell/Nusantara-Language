# Cocok

Nusantara memiliki cocok, fungsi nya sama
seperti switch di bahasa pemrograman lain.

```nusantara
kalimat nama = 'Fern Aerell';
cocok(nama) {
    kasus 'Fern':
        cetak('First name');
        berhenti;
    kasus 'Aerell':
        cetak('Last name');
        berhenti;
    kasus 'Fern Aerell':
        cetak('Full name');
        berhenti;
    bawaan:
        cetak('Nama siapa itu?');
}
```
