#include <stdio.h>
#include <stdlib.h>
/*3.	Algorisme que llegeix un número enter N i calcula la seva taula de multiplicar.*/

int main (void)
{
    int n, res, cont;
    printf("Introdueix un nombre ");
    scanf("%d",&n);
    cont=0;
    res=0;
    while(cont<=10){
        res=n*cont;
        printf("%d x %d = %d\n", n, cont, res);
        cont++;
    }

}
