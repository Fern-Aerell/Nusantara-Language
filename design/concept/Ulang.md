# Ulang

Nusantara juga mendukung perulangan, untuk
membuat perulangan kita dapat menggunakan
keyword 'ulang' dan 'kerja'.

## Ulang (While)

```nusantara
int i = 0;
ulang(i < 10) {
    cetak("Halo Dunia!");
    i++;
}
```

## Kerja Ulang (Do While)

```nusantara
int i = 0;
kerja {
    cetak("Halo Dunia!");<F5>
    i++;
} ulang(i < 10); 
```

## Ulang (For loop)

```nusantara
ulang(bulat i = 0; i < 10: i++) {
    cetak(i);
}
```

## Ulang Di (For In)

```nusantara
bulat[3] nomors = [1, 2, 3];
ulang(bulat nomor di nomors) {
    cetak(nomor);
}
```
