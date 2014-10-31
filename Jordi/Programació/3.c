#include <stdio.h>
#include <stdlib.h>
/*
3.	Algorisme que llegeix un número enter N i calcula la seva taula de multiplicar.
*/
int main(void)
   {
       int n, x, y;
       printf("Introdueix un numero per saber la seva taula de multiplicar:");
       scanf("%d",&n);

       x=0;

       while(x<10){
            x++;
        printf("\n%d * %d = %d",n,x,n*x);
       }

return 0;

   }
