#include <stdio.h>
#include <stdlib.h>
/*
1.	Algorisme que llegeix 10 n�meros enters i ens diu quants d�ells s�n positius.
*/
int main(void)
   {
       int n, x, y;
        x=0;
        y=0;
       while (x<10)
       {
        printf("Introdueix un numero:\n");
        scanf("%d",&n);
        if (n>0){
            y++;
        }
            x++;
       }
      printf("%d Numeros positius.",y);
      return 0;
   }
