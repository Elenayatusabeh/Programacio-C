#include <stdlib.h>
#include <stdio.h>
/*
5.	Algorisme que calcula la suma dels n�meros parells i els n�meros senars dels n�meros entre 1 i 100.
*/
int main(void)
   {
       int n, par, imp;
       par=0;
       imp=0;
       n=1;
       while(n<=100){

       if(n%2==0)
        {
           par=n+par;
        }
       else
        {
           imp=n+imp;
        }
       n++;
        }
    printf("Els parells sumen:%d \nEls imparells sumen:%d\n ",par,imp);
return 0;

   }
