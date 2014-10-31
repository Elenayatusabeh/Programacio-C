#include <stdio.h>
#include <stdlib.h>
/*1.	Algorisme que llegeix 10 números enters i ens diu quants d’ells són positius.*/

int main (void)
{
    int n, cont, pos;
    cont=0;
    pos=0;
    while(cont < 10){
        printf("Introdueix un nombre enter ");
        scanf("%d",&n);
        if(n>0){
            pos++;
        }
        cont++;
    }
    printf("El numero de nombres positius es %d",pos);

}
