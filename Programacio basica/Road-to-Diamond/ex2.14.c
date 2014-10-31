#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seqüència de lletres (que formen una frase) fins arribar al punt.
 La sortida ens diu el número de vegades que llegeix la lletra A (tant majúscula com a minúscula).*/

int main (void)
{
    int n;
    char c;
    n=0;
    fflush(stdin);
    while(c!='.'){

        scanf("%c",&c);
        switch(c){
            case 'A':
            case 'a':
                n++;
            break;
            default:
            break;
        }

    }

    printf("El numero de lletres A es %d",n);

}
