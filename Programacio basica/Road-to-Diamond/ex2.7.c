#include <stdio.h>
#include <stdlib.h>
/*7.	Algorisme que llegeix una seqüència de números enters fins a llegir un zero. Llavors ens
diu quin és el número més gran. */

int main (void)
{
    int n, x;
    n=1;
    x=-1;
    while(n!=0){
        printf("Introdueix un numero ");
        scanf("%d",&n);
        if(n>x){
            x=n;
        }
    }
    printf("El numero amb valor mes alt es %d",x);
}
