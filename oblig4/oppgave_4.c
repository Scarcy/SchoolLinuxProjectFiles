#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main() {
  int status = 0;
  pid_t child, child2;
  char *args[3];
  args[0] = strdup("ping");
  args[1] = strdup("vg.no");
  args[2] = NULL;
 
  child = fork();
 
  if(child > 0){
    sleep(5);
    kill(child, SIGKILL);
    printf("Barn drept med SIGKILL\n");
  } else if(child == 0){
    execvp(args[0], args);
  } else{
    perror("fork");
    exit(-1);
  }  
  // Valgte å prøve begge metodene i samme program. Både SIGKILL og SIGINT.
  child2 = fork();

  if(child2 > 0){
    sleep(5);
    kill(child2, SIGINT);
    printf("Barn drept med SIGINT\n");
  } else if(child2 == 0){
    execvp(args[0], args);
  } else{
    perror("fork");
    exit(-1);
  }
  
  // Når barne prosessen blir stoppet med SIGINT, så får man slutt resultatene
  // av ping programmet. Det betyr at når vi stopper ping med SIGKILL så lar vi
  // ikke programmet ping gjøre seg ferdig, men med SIGINT så kan ping 
  // rydde opp når den blir avsluttet
  return 0;
}

