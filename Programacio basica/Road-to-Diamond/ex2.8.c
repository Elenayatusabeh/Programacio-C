#include <stdio.h>
#include <stdlib.h>
/*8.	Algorisme que llegeix un número enter positiu i ens calcula el factorial (N!).*/

int main (void)
{
    int n, cont, res;
    printf("Introdueix un nombre positiu ");
    scanf("%d",&n);
    cont=1;
    res=1;
    if(n<=0){
        printf("Ha de ser un nombre positiu ");
    }
    else{
       while(cont<=n){
        res=res*cont;
        cont++;
        }
         printf("El factorial de %d es %d",n, res);
    }
}


