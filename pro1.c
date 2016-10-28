#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  pid_t pid = fork();

  if (pid == 0) // Çatallama başarılı
    {
    }
  else if (pid < 0) // Çatallama başarısız
    {
      printf("fork() basarisiz!\n");
      return 1;
    }
  else // Çatallamadan sonra ebeveyn işlem
    {
    }

  return 0;
}
