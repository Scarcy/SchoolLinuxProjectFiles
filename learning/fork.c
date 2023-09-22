#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
   fork();
   printf("Prosess %d sin forelderprosess er %d\n", getpid(), getppid());
   return 0;
}
