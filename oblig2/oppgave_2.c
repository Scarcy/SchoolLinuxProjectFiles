#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int tallArray[1000];
  int i, r, currentLowest;
  srand(time(NULL));
   
  for(i = 0; i < 1000; i++){
    r = rand() % 100000;
    tallArray[i] = r;

    if(i == 0 || tallArray[i] < currentLowest){
      currentLowest = tallArray[i];
    }
  }
  
  printf("Laveste tallet i arrayen: %d\n", currentLowest);
}
