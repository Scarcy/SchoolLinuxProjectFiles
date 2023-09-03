#include <stdio.h>

int main(){
  
  int sum = 0;

  for(int n = 0; n <= 100; n++){
    sum += n * n;
  }
  printf("Summen av kvadraten av de første hundre heltall er: %d\n", sum);
}
