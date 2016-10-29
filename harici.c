#include <stdio.h>

int main(int argc, char **argv) {
    char *dizi = *argv;
    if (argc < 1) {
        return 1;
    }

    int adet;
    for (adet = 0; dizi[adet] != '\0' && adet < 10; adet++); // Komut satırı parametresi ile gelen sayının kaç basamak
//    olduğu değeri alınır. int veri tipinin alabileceği maksimum değer 10 basamaklı olduğundan fazlası yok sayılır.

    int sayi = 0;
    int i, j, n;
    for (i = 0; i < adet; i++) {
        n = dizi[i] - '0'; // O anki rakamın karakter değerinden 0 karakteri çıkartılarak rakamın sayısal değeri
//        elde edilir.
        if (n < 0 || n > 9) continue; // Eğer değer bir rakama eşit değilse o karakter yok sayılır.
        for (j = 0; j < adet - 1 - i; j++) n *= 10; // Sayı, sasamak değeri kadar 10 ile çarpılır.
        sayi += n;
    }

    n = sayi / 2;
    printf("[YAVRU] %d sayisina kadar olan cift sayilarin toplami: %d\n", sayi, n * (n + 1));
    printf("[YAVRU] Islem tamamlandi.\n");

    return 0;
}