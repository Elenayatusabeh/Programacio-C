#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seq��ncia de lletres (que formen una frase) fins arribar al punt.
La sortida ens diu el n�mero de vegades que llegeix la s�l�laba LA (tant maj�scula com a min�scula).*/

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
