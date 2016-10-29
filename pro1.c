#include <stdio.h>
#include <unistd.h> // fork()
#include <sys/wait.h> // wait()

int main(int argc, char **argv) {
    pid_t pid;

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

    pid = fork(); // Çatallama işlemi yapılır ve oluşan çocuk işlemin pid'i değişkene atanır.
    if (pid == 0) // Çatallama başarılı
    {
        execl("./harici", sayi, (char *) 0);
        printf("[YAVRU] Islem tamamlandi.\n");
    } else if (pid < 0) // Çatallama başarısız
    {
        printf("fork() basarisiz!\n");
        return 1;
    } else // Çatallamadan sonra ebeveyn işlem
    {
        int donusDurumu;
        wait(&donusDurumu); // Yavru işlem tamamlayıncaya kadar beklenir. Çocuk işlemin
        // dönüş değeri değişkene aktarılır.

        if (donusDurumu == 0) // Çocuk işlem hatasız bir şekilde sonlandıysa.
        {
            printf("[EBEVEYN] Yavru islem tamamlandi, program sonlandiriliyor.\n");
        } else // Hata koduyla sonlanmışsa
        {
            printf("Cocuk islem bir hata ile sonlandirildi! (%d)\n", donusDurumu);
        }
    }

    return 0;
}
