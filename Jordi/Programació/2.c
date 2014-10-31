#include <stdio.h>
#include <stdlib.h>
/*
2.	Algorisme que calcula la suma i el producte dels 5 primers números naturals.
*/
int main(void)
   {
       int n, x, y;
        x=0;
        n=0;
        y=1;
       while (x<5)
       {
        x++;
        n=n+x;
        y=x*y;


       }
    printf("\nSuma:%d\nMultiplicacio:%d\n\n",n,y);
    return 0;
   }
