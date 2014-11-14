#include <stdio.h>
#include <stdlib.h>
/*
11. Algorisme que llegeix un número enter N i ens diu la llista de números que són divisors d’aquest.
*/

int main (void)
{
    int n, x;
    printf("Introdueix un numero enter:\n");
    scanf("%d",&n);
    x=n/2;
    printf("\nEls divisors de %d son:\n",n);
    printf("%d",n);
    while(x>0){
        if(n%x==0){
            printf("%d\n",x);
        }
        x--;
    }
    return 0;
}

