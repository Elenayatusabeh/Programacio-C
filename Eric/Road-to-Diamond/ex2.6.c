#include <stdio.h>
#include <stdlib.h>
/*6.	Algorisme que llegeix una seq��ncia de 10 n�meros i ens diu quants s�n positius, quants s�n negatius
i quants s�n zero. */


int main (void)
{
    int n, cont, pos, neg, zer;
    cont=0;
    pos=0;
    neg=0;
    zer=0;
    while(cont < 10){
        printf("Introdueix un nombre enter ");
        scanf("%d",&n);
        if(n>0){
            pos++;
        }
        else if(n<0){
            neg++;
        }
        else{
            zer++;
        }
        cont++;
    }
    printf("El numero de nombres positius es %d\n",pos);
    printf("El numero de nombres negatius es %d\n",neg);
    printf("El numero de zero es %d\n",zer);
}
