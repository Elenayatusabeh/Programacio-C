#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seq��ncia de 10 n�meros per teclat i en acabar ens diu el m�s gran,
el m�s petit i la mitjana aritm�tica de tots ells.*/

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
