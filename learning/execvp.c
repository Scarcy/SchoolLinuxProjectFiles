#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   char *argv[4];
   argv[0] = strdup("ncal");
   argv[1] = strdup("-w");
   argv[2] = strdup("2023");
   argv[3] = NULL;

   printf("Hei, jeg er programmet som snart skal dø...\n\n");
   sleep(1);

   execvp(argv[0], argv);

   printf("Dette vil ikke kunne skrives ikke ut\n");
}
