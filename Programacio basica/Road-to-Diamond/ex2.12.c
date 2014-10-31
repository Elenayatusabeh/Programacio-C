#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seqüència de 10 números per teclat i en acabar ens diu el més gran,
el més petit i la mitjana aritmètica de tots ells.*/

int main (void)
{
    int n, cont, x, y;
    printf("Introdueix un nombre enter ");
    scanf("%d",&n);
    x=n;
    y=n;
    cont=0;


    while(cont < 10){
        printf("Introdueix un nombre enter ");
        scanf("%d",&n);
        if(n>x){
            x=n;
        }
        else if(n<y){
            y=n;
        }
        cont++;
    }
    printf("El numero mes gran es %d\n",x);
    printf("El numero mes petit es %d\n",y);

}
