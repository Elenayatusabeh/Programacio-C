#include <stdio.h>
#include <stdlib.h>
/*2.	Algorisme que calcula la suma i el producte dels 5 primers números naturals.*/

int main (void)
{
    int n, cont, sum;
    cont=1;
    n=0;
    sum=0;
    while(n<5){
        n++;
        sum=sum+n;
        cont=cont*n;
    }
    printf("%d %d",sum, cont);
}
