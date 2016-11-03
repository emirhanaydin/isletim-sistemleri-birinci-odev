/**
* @file pro1.c
* @description Çatallama işleminin ve harici program çağrısının yapılacağı ana program.
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
#include <unistd.h> // fork()
#include <sys/wait.h> // wait()

int main(int argc, char **argv) {
    int n;
    printf("[EBEVEYN] 0'dan n'e kadar olan cift sayilarin toplami icin n degeri: ");
    scanf("%d", &n);

    char sayi[11]; // int veri tipinin alabileceği maksimum değer 10 basamaklı olduğundan fazlası yok sayılır.
    int i, j = n, adet = 0;
    for (i = 0; i < 10 && j > 0; i++) { // Ardışık 10'a modüler ve standart bölme işlemleriyle sayı diziye aktarılır.
        sayi[i] = j % 10 + '0'; // Birler basamağındaki rakam alınır.
        j /= 10; // Sayı sağdan bir basamak eksiltilir.
        adet++;
    }
    sayi[adet] = '\0';

    char gecici;
    j = adet / 2;
    for (i = 0; i < j; i++) { // Sayı diziye sağdan sola doğru atandığı için terslenerek gerçek haline döndürülür.
        gecici = sayi[i];
        sayi[i] = sayi[adet - 1 - i];
        sayi[adet - 1 - i] = gecici;
    }

    pid_t pid;
    pid = fork(); // Çatallama işlemi yapılır ve oluşan çocuk işlemin pid'i değişkene atanır.
    if (pid == 0) // Çatallama başarılı
    {
        execl("./harici", sayi, (char *) 0);
    } else if (pid < 0) // Çatallama başarısız
    {
        printf("fork() basarisiz!\n");
        return 1;
    } else // Çatallamadan sonra ebeveyn işlem
    {
        int donusDurumu;
        wait(&donusDurumu); // Yavru işlem tamamlayıncaya kadar beklenir. Yavru işlemin dönüş değeri değişkene
//        aktarılır.

        if (donusDurumu == 0) // Yavru işlem hatasız bir şekilde sonlandıysa.
        {
            printf("[EBEVEYN] Yavru islem tamamlandi, program sonlandiriliyor.\n");
        } else // Hata koduyla sonlanmışsa dönüş değeri yazdırılır.
        {
            printf("[EBEVEYN] Yavru islem hata ile sonlandirildi! (%d)\n", donusDurumu);
        }
    }

    return 0;
}
