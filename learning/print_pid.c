#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
   printf("\nDenne prosessen har PID  : %d\n", getpid());
   printf("Forelderprosessen har PID: %d\n", getppid());

   printf("Prosessen sover de neste 2 minuttene\n");
   sleep(120);
   printf("Prosessen er våken igjen!\n");
   return 0;
}
