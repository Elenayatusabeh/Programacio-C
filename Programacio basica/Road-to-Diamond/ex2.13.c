#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix una seqüència de notes entre 0 i 10. La seqüència s’acaba amb el -1.
En acabar ens mostra: la mitjana aritmètica de totes les notes introduïdes, quants han tret
excel·lent, quants notable, quants bé, quants suficient, quants insuficient i quants molt deficient.*/

int main (void)
{
    int n, mit, res,  ex, no, be, su, in, mi;
    mit=0;
    res=0;
    ex=0;
    no=0;
    be=0;
    su=0;
    in=0;
    mi=0;

    while(n!=-1){
        printf("Introdueix una nota ");
        scanf("%d",&n);
        switch(n){
            case 0:
            case 1:
            case 2:
                mi++;
            break;

            case 3:
            case 4:
                in++;
            break;

            case 5:
                su++;
            break;

            case 6:
                be++;
            break;

            case 7:
            case 8:
                no++;
            break;

            case 9:
            case 10:
                ex++;
            break;

            default:
                printf("Nota erronea\n");
            break;
        }
        if(n>=0 && n<=10){
            res=res+n;
            mit++;
        }

    }
    mit=res/mit;
    printf("La mitjana aritmetica es %d\n", mit);
    printf("Nº excelents %d\n", ex);
    printf("Nº notables %d\n", no);
    printf("Nº be %d\n", be);
    printf("Nº suficient %d\n", su);
    printf("Nº insuficient %d\n", in);
    printf("Nº molt insuficient %d\n", mi);
}



