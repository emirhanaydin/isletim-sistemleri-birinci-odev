#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    char sayiDizisi[11];

    char c;
    int i, adet = 0;
    // İlk parametre dizisinin o anki indeksi diziye atanır ve adet değeri döngü sayısı ile belirlenir.
    for (i = 0; (c = *(*(argv + 1) + i)) != '\0' && i < 10; i++) {
        sayiDizisi[i] = c;
        adet++;
    }
    sayiDizisi[10] = '\0';

    int sayi = 0;
    int j, n;
    for (i = 0; i < adet; i++) {
        n = sayiDizisi[i] - '0';
        for (j = 0; j < adet - 1 - i; j++) n *= 10;
        sayi += n;
    }

    printf("%d", sayi);

    return 0;
}