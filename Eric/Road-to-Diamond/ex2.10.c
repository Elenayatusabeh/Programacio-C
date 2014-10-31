#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix un número enter X i un altre número enter n i ens calcula l’N-èsima potencia de X.*/

int main (void)
{
    int n, x, cont, res;
    printf("Introdueix dos nombres enters ");
    scanf("%d %d",&x,&n);

    cont=0;
    res=1;
    if(n<0){
        printf("Ha de ser un nombre positiu");
    }
    else{
        while(cont<n){
            res=res*x;
            cont++;
        }
        printf("%d elevat a %d es igual a %d", x, n, res);
}
    }



