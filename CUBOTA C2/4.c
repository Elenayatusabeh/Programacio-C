#include <stdlib.h>
#include <stdio.h>
/*
4.	Algorisme que llegeix una seqüència de notes enteres (0..10) fins que llegeix el -1 i ens diu si alguna de les notes era un 10.
*/
int main(void)
   {
       int n, y;
       y=0;
       n=0;
       while(n!=-1){

       printf("Introdueix una nota numerica:");
       scanf("%d",&n);
       if(n==10)
       {
           y++;

       }
       }
    printf("S'han introduit %d deus.",y);
return 0;

   }
