#include <stdlib.h>
#include <stdio.h>
/*
10.	Algorisme que llegeix un número enter X i un altre número enter n i ens calcula l’N-èsima potencia de X.
11.	Algorisme que llegeix un número enter N i ens diu la llista de números que són divisors d’aquest.
12.	Algorisme que llegeix una seqüència de 10 números per teclat i en acabar ens diu el més gran, el més petit i la mitjana aritmètica de tots ells.
13.	Algorisme que llegeix una seqüència de notes entre 0 i 10. La seqüència s’acaba amb el -1. En acabar ens mostra: la mitjana aritmètica de totes les notes introduïdes, quants han tret excel•lent, quants notable, quants bé, quants suficient, quants insuficient i quants molt deficient.
*/
int main(void)
   {
        int x, n, p, c;
        printf("Introdueix un numero enter:");
        scanf("%d",&x);
        printf("Introdueix un segon numero enter:");
        scanf("%d",&n);

        c=n;
        p=1;
        while(c>0)
        {
           p=p*x;
           c--;
        }
        printf("\nEl resultat de la potencia es:%d",p);
    return 0;

   }
