#include <stdlib.h>
#include <stdio.h>
/*
10.	Algorisme que llegeix un n�mero enter X i un altre n�mero enter n i ens calcula l�N-�sima potencia de X.
11.	Algorisme que llegeix un n�mero enter N i ens diu la llista de n�meros que s�n divisors d�aquest.
12.	Algorisme que llegeix una seq��ncia de 10 n�meros per teclat i en acabar ens diu el m�s gran, el m�s petit i la mitjana aritm�tica de tots ells.
13.	Algorisme que llegeix una seq��ncia de notes entre 0 i 10. La seq��ncia s�acaba amb el -1. En acabar ens mostra: la mitjana aritm�tica de totes les notes introdu�des, quants han tret excel�lent, quants notable, quants b�, quants suficient, quants insuficient i quants molt deficient.
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
