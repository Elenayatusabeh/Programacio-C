#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seq��ncia de lletres (que formen una frase)
fins arribar al punt. La sortida ens diu quantes paraules cont� la frase introdu�da.*/

int main (void)
{
    int n, f, x;
    char c, res;
    n=0;


    while(c!='.'){

        scanf("%c",&c);
        if(c==' '){
            n++;
        }

    }
    n++;
    printf("\nParaules = %d\n",n);
}


