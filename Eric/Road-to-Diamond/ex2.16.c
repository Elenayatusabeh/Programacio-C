#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seqüència de lletres (que formen una frase) fins arribar al punt.
La sortida ens diu el número de vegades que llegeix la síl·laba LA (tant majúscula com a minúscula).*/

int main (void)
{
    int n;
    char c, c2;
    n=0;
    fflush(stdin);
    while((c!='.')&&(c2!='.')){

        scanf("%c",&c2);
        if((c=='L' || c=='l') && (c2=='A' || c2=='a')){
            n++;
        }
        c=c2;
    }

    printf("El numero de silabes LA es %d",n);

}
