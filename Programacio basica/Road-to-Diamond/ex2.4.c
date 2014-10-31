#include <stdio.h>
#include <stdlib.h>
/*4.	Algorisme que llegeix una seqüència de notes enteres (0..10) fins que llegeix el -1 i
 ens diu si alguna de les notes era un 10.*/

int main (void)
{
    int n, cont;
    n=0;
    cont=0;
    while(n!=-1){
        printf("Introdueix una nota ");
        scanf("%d",&n);
        if(n==10){
            cont++;
        }
    }
    printf("El nombre de notes amb valor 10 es %d",cont);
}
