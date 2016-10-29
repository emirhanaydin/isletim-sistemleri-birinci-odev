#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 1) {
        return 1;
    }

    char sayiDizisi[11]; // int veri tipinin tutabileceği maksimum değer 10 basamaklı olduğundan dizi en fazla 10
//     eleman tutacaktır. Son elemandan sonra NULL karakteri yerleştirilir.

    char c;
    int i, adet = 0;
    // İlk parametre dizisinin o anki indeksi diziye atanır ve adet değeri döngü sayısı ile belirlenir.
    for (i = 0; c != '\0' && i < 10; i++) {
        c = *(*(argv + 1) + i);
        if (c == '\0') break;
        sayiDizisi[i] = c;
        adet++;
    }
    sayiDizisi[adet] = '\0';

    int sayi = 0;
    int j, n;
    for (i = 0; i < adet; i++) {
        n = sayiDizisi[i] - '0'; // O anki rakamın karakter değerinden 0 karakteri çıkartılarak rakamın sayısal değeri
//        elde edilir.
        if (n < 0 || n > 9) continue; // Eğer değer bir rakama eşit değilse o karakter yok sayılır.
        for (j = 0; j < adet - 1 - i; j++) n *= 10; // Sayı, sasamak değeri kadar 10 ile çarpılır.
        sayi += n;
    }

    printf("%d", sayi);

    return 0;
}