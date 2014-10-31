
#include <stdlib.h>
#include <stdio.h>
/*
12.	Algorisme que llegeix una seqüència de 10 números per teclat i en acabar ens diu el més gran, el més petit i la mitjana aritmètica de tots ells.
*/
int main(void)
   {
    int x, n, menor, major, mitjana;
    x=0;
    menor=0;
    major=0;
    mitjana=0;

    printf("Introdueix 10 numeros:\n");
    while(x<10)
    {
        scanf("%d",&n);
        mitjana=mitjana+n;
        if((n<menor) || (x==0))
        {
            menor=n;

        }
        if((n>major) || (x==0))
        {
            major=n;
        }
        x++;
    }
    printf("El major es: %d\nEl menor es: %d\nLa mitjana aritmetica es: %d",major,menor,mitjana/10);
    return 0;

   }
