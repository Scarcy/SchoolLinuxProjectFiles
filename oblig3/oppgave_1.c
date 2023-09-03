#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int palindrom(char* s1){
  int length = strlen(s1);
  char* s2 = malloc(length + 1);
  if(s2 == NULL){
    printf("Memory allcocation failed");
  }
  for(int i = length - 1, j = 0; i >= 0; i--, j++){
    s1[i] = tolower(s1[i]);
    s2[j] = s1[i]; 
  }
  s2[length] = '\0';
  int isPalindrom = strcmp(s1,s2);
  printf("s1: %s, s2: %s\n", s1,s2);
  free(s2);
  return isPalindrom;
}
int main(){
  char s1[100];
  printf("Sjekk om et ord er et palindrom: "); 
  scanf("%s", s1);
  
  int isPalindrom = palindrom(s1);
  if(isPalindrom == 0){
   printf("Dette ordet er et palindrom :)\n"); 
  }
  else{
    printf("Dette ordet er ikke et palindrom :(\n");

  }
}
