#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   pid_t child;
   
   child = fork();
   
   if (child == 0)
   {
     // Dette utføres bare av barneprosessen som lages av fork
      printf("Hei! Jeg har PID %d og er barneprosessen til PID %d\n",
	     getpid(), getppid());
   }
   else if (child > 0)
   {
     // Dette utføres bare av forelderprosessen som kaller fork
      printf("Hei! Jeg har PID %d og er forelderprosessen til PID %d\n",
	     getpid(), child);
   }
   else
   {
     // Merk bruken av "perror" for feilmelding, se "man perror"
      perror("fork");
      exit(-1);
   }
   return 0;
}
