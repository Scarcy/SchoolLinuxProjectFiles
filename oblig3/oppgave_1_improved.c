#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void reverserOrd(char* str, int len) {
  for(int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}
void toLowerCase(char* str) {
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }
}

int palindrom(char* s1){
  int len = strlen(s1);
  char s2[len + 1];

  strcpy(s2, s1);
  reverserOrd(s2, len);
  int isPalindrom = strcmp(s1,s2);
  return isPalindrom;
}
int main(){
  char s1[100];
  printf("Sjekk om et ord er et palindrom: "); 
  scanf("%s", s1);
  toLowerCase(s1); 
  int isPalindrom = palindrom(s1);
  if(isPalindrom == 0){
   printf("Dette ordet er et palindrom :)\n"); 
  }
  else{
    printf("Dette ordet er ikke et palindrom :(\n");

  }
}
