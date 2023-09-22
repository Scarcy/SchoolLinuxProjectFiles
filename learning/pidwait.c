#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   pid_t child, w_pid;
   int status = 0;

   // Lager en barneprosess
   child = fork();
   
   if (child == 0)
   {
     printf("\nHei. Jeg er barneprosessen med PID %d\n", getpid());
     printf("Nå er det på tide å sove litt...Zzzz\n");
     sleep(2);
     printf("Barneprosessen er våken igjen!\n");
     return 0;
   }
   else if (child > 0)
   {
      // Her venter forelder på at barneprosessen skal bli ferdig
      w_pid = wait(&status);
      
      printf("\nHei. Jeg er forelderprosessen med PID %d\n",  getpid());
      printf("Min barneprosess med PID %d er nå ferdig\n",  w_pid);
      printf("Barneprosessen returnerte med status lik %d\n\n", status);
      return 0;
   }
   else
   {
      perror("fork");
      exit(-1);
   }
}
