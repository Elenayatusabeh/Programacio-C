#include <stdlib.h>
#include <stdio.h>
/*
9.	Algorisme que llegeix dos números enters positius i ens dóna el producte mitjançant sumes successives.
10.	Algorisme que llegeix un número enter X i un altre número enter n i ens calcula l’N-èsima potencia de X.
11.	Algorisme que llegeix un número enter N i ens diu la llista de números que són divisors d’aquest.
12.	Algorisme que llegeix una seqüència de 10 números per teclat i en acabar ens diu el més gran, el més petit i la mitjana aritmètica de tots ells.
13.	Algorisme que llegeix una seqüència de notes entre 0 i 10. La seqüència s’acaba amb el -1. En acabar ens mostra: la mitjana aritmètica de totes les notes introduïdes, quants han tret excel•lent, quants notable, quants bé, quants suficient, quants insuficient i quants molt deficient.
*/
int main(void)
   {
        int n1, n2, x;
        printf("Introdueix un numero enter positiu:");
        scanf("%d",&n1);
        printf("Introdueix un segon numero enter positiu:");
        scanf("%d",&n2);

        x=n2;

        if(n1>0 && n2>0)
        {
            printf("%d*%d= ",n1,n2);
            while(x>1) //El while acaba un número abans perquè en el últim dígit no es mostri el signe +
            {
               printf("%d+",n1);
               x--;
            }
            printf("%d = %d",n1,n1*n2); //Aquí es posa l'últim n1 i el resultat.
        }
        else
        {
            printf("Has d'introduïr un nombres enters i positius.");
        }

    return 0;

   }
