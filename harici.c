/**
* @file harici.c
* @description Komut satırı parametresi olarak gönderilen sayıya kadar olan çift sayıların toplamını ekrana yazdırır.
* @course 2A
* @assignment 1
* @date 29.10.2016
* @authors 
 *Emirhan Aydın (g141210018@sakarya.edu.tr)
 *Mesut Sertaç Gün (g141210036@sakarya.edu.tr)
 *Alpcan Tuna (g141210030@sakarya.edu.tr)
 *Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/

#include <stdio.h>

int main(int argc, char **argv) {
    char *argvDizi = *argv;
    int sayiDizisi[10]; // int veri tipinin alabileceği maksimum değer 10 basamaklı olduğundan fazlası yok sayılır.
    if (argc < 1) {
        return 1;
    }

    int i, n, adet = 0;
    for (i = 0; i < 10; i++) { // Komut satırı parametresi ile gelen dizi tek tek okunur ve sayı dizisine atanır.
        n = argvDizi[adet] - '0'; // O anki rakamın karakter değerinden 0 karakteri çıkartılarak rakamın sayısal değeri
//        elde edilir.
        if (n >= 0 && n <= 9) { // Eğer karakterin sayısal değeri bir rakama eşitse sayı dizisine atanır ve sayı adedi
//            bir artırılır.
            sayiDizisi[adet++] = n;
        }
    }

    for (i = 0, n = 1; i < adet - 1 - i; i++, n *= 10); // En yüksek basamaklı sayının basamak değeri kadar 10'un
//    kuvveti alınır.

    int sayi = 0;
    for (i = 0; i < adet; i++) {
        sayi += sayiDizisi[i] * n; // Sayıya o anki rakam basamak değeri ile çarpılarak eklenir.
        n /= 10; // Basamak değeri 10'a bölünerek bir azaltılır.
    }

    n = sayi / 2; // Sonlu toplam formülünde sayının yarısı kullanılacaktır.
    printf("[YAVRU] %d sayisina kadar olan cift sayilarin toplami: %d\n", sayi, n * (n + 1)); // Sonlu toplam formülü
//    kullanılarak hesaplama yapılır.
    printf("[YAVRU] Islem tamamlandi.\n");

    return 0;
}
