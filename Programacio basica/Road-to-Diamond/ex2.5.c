#include <stdio.h>
#include <stdlib.h>
/*5.	Algorisme que calcula la suma dels números parells i els números senars dels números entre 1 i 100.*/

int main (void)
{
    int cont, par, sen;
    cont=1;
    par=0;
    sen=0;
    while (cont<=100){
        if (cont%2==0){
            par=cont+par;
        }
        else{
            sen=cont+sen;
        }
        cont++;
    }
    printf("La suma dels nombres parell es %d\n", par);
    printf("La suma dels nombres senars es %d\n", sen);
}
