#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix un número enter N i ens diu la llista de números que són divisors d’aquest.*/

int main (void)
{
    int n, x;
    printf("Introdueix un nombre enter ");
    scanf("%d",&n);
    x=n;

    while(x>0){
        if(n%x==0){
            printf("%d\n",x);
        }
        x--;
    }
    return 0;
}

