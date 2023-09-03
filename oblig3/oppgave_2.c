#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int antallHeltall = 0;
  printf("Hvor mange heltall: ");
  scanf("%d", &antallHeltall);
  
  int* A = malloc(antallHeltall * sizeof(int));
  if(A == NULL){
    printf("Memory Allocation feilet");
    return 1;
  }
  printf("Skriv tall \n");
  for(int i = 0; i < antallHeltall; i++){
    printf("Tall %d: ", i + 1);
    scanf("%d", &A[i]);
  }
  // Finner antall elementer i arrayen
  for(int i = antallHeltall - 1; i >= 0; i--){
      printf("%d", *(A + i));

      if(i > 0)
        printf(", ");
      else if(i == 0)
        printf("\n");
  }

  free(A);
  return 0;
}

