#include <stdio.h>
#include <stdlib.h>

struct prosess
{
   int nummer; 
   char status;
   float start_tid;
   float CPU_tid;
};
struct prosess* kopier(struct prosess p){
  struct prosess* kopi = malloc(sizeof(struct prosess));
  
  printf("Prossesen som skal kopieres: \n");
  printf("Nr: %3d  Status: %c  Start: %5.2f  CPU: %5.2f\n",
      p.nummer, p.status, p.start_tid, p.CPU_tid); 

  kopi->nummer = p.nummer;
  kopi->status = p.status;
  kopi->start_tid = p.start_tid;
  kopi->CPU_tid = p.CPU_tid;


  return kopi;
}

int main( )
{
   FILE* fil;
   struct prosess *P;
   int i, n;

   // Åpner fil
   fil = fopen("res/prosess.txt", "r");
   if (fil == NULL)
   {
      printf("Feil i åpning av fil");
      exit(0);
   }

   // Leser antall prosesser
   fscanf(fil, "%d", &n);

   // Oppretter en dynamisk array med strukturer
   P = (struct prosess *) malloc(n * sizeof(struct prosess));

   // Leser inn dataene fra fil
   for (i = 0; i < n; i++)
     fscanf(fil, "%d %c %f %f",
	    &P[i].nummer, &P[i].status, &P[i].start_tid, &P[i].CPU_tid);

   // Skriver ut innleste data
   for (i = 0; i < n; i++)
     printf("Nr: %3d  Status: %c  Start: %5.2f  CPU: %5.2f\n",
	    P[i].nummer, P[i].status, P[i].start_tid, P[i].CPU_tid);

   struct prosess* kopi = kopier(P[0]);
   printf("- - - - - - - - - \n");
   printf("Kopien av prosessen:\n");
   printf("Nr: %3d  Status: %c  Start: %5.2f  CPU: %5.2f\n",
   kopi->nummer, kopi->status, kopi->start_tid, kopi->CPU_tid);
   free(kopi);
   free(P);
   return 0;
}
