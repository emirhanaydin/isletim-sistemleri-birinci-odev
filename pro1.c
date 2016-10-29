#include <stdio.h>
#include <unistd.h> // fork()
#include <sys/wait.h> // wait()

int main(int argc, char **argv) {
    pid_t pid;

    int n;
    printf("0'dan n'e kadar olan cift sayilarin toplami icin n degerini giriniz: ");
    scanf("%d", &n);

    pid = fork(); // Çatallama işlemi yapılır ve oluşan çocuk işlemin pid'i değişkene atanır.
    if (pid == 0) // Çatallama başarılı
    {

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

        } else // Hata koduyla sonlanmışsa
        {
            printf("Cocuk islem bir hata ile sonlandirildi!\n");
        }
    }

    return 0;
}
