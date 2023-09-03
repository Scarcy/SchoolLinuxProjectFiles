#include <stdio.h>
#include <stdlib.h>
long fib(int n){ 
  long a = 0, b = 1, c;
  if(n == 0){
    return a;
  }
  for(int i = 2; i <= n; i++){
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int main(){
  // Kjører en Unix kommando som sletter innholdet i filen når programmet starter
  system("echo -n > res/fibonacci.txt");
  int n;
  FILE* fil;
  
  fil = fopen("res/fibonacci.txt", "w");

  if(fil == NULL){
    printf("Filen kunne ikke åpnes");
    return 1;
  }

  printf("Skriv ett nummer: ");
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++){
    long f = fib(i);

    fprintf(fil, "%ld\n", f);
  }


  printf("Fibonacci nummerene ble skrevet til fibonacci.txt! \n");
  fclose(fil);
}
